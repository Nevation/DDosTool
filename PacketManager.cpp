#include "PacketManager.h"

PacketManager::~PacketManager(){

}

PacketManager::PacketManager(uchar* target){
    target_ip[0] = target[0];
    target_ip[1] = target[1];
    target_ip[2] = target[2];
    target_ip[3] = target[3];
    packet_cnt = 0;
}

bool PacketManager::MakePacket(int type, int cnt)
{
    printf("MakePacket!\n");
    packet_cnt += cnt;

    cv_ether ether;
    for (int i=0; i<6; i++) ether.targetmac[i] = 0xff;
    //ether.targetmac = {};//gateway mac


    cv_iphd iph;
    iph.ether = ether;
    iph.TotalLength[0] = 0x05; iph.TotalLength[1] = 0xce;
    iph.Identifier[0] = 0x00;  iph.Identifier[1] = 0x00;
    iph.IP_checksum[0] = 0x00; iph.IP_checksum[1] = 0x00;
    iph.DstIP[0] = target_ip[0]; iph.DstIP[1] = target_ip[1];
    iph.DstIP[2] = target_ip[2]; iph.DstIP[3] = target_ip[3];

    switch (type)
    {
    case UDP:
        iph.Protocol = 0x11;
        cv_udphd udph;
        udph.iphd = iph;
        udph.Dport[0] = 0x00;
        udph.Dport[1] = 0x50;

        udph.u_length[0] = 0x05;
        udph.u_length[1] = 0xba;
        udph.u_checksum[0] = 0x00;
        udph.u_checksum[1] = 0x00;

        for (int i = 0; i < cnt; i++) {
            UDPHeader packet;
            packet.MakeUdpPacket(udph);
            packets.push_back(packet.UdpToPacket());
            for (int i=0;i<200; i++){
               printf("0x%02x ", packets[0][i]);
               if (i == 13 || i == 33) printf("\n");
            }
        }
        break;
    case TCP:
        /*
        cv_tcphd tcph;
        tcph.iphd = iph;
        tcph.Dport[0] = 0x00;
        tcph.Dport[0] = 0x50;
        tcph.Sequence[4] = { 0x02, 0x02, 0x02, 0x02}; //random
        tcph.Ack[4] = { 0x00, 0x00, 0x00, 0x01};
        tcph.LenRev = 0x00; //--
        tcph.Rev = 0x00;  //--
        tcph.Window[2] = { 0x00, 0x00 };  //--
        tcph.Checksum[2] = { 0x00, 0x00};
        tcph.Point[2] = { 0x00, 0x00 };

        for (int i = 0; i < cnt; i++) {
            TCPHeader packet;
            // packet make function
            packets.push_back(packet.TcpToPacket());
        }
        */

        break;
    default:
        break;
    }
    printf("Complete Packet!\n");
    return false;
}

vector<vector<uchar>> PacketManager::GetPackets(){
    return packets;
}


int PacketManager::GetPacketCnt(){
    return packet_cnt;
}

