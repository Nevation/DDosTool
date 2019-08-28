#include "IPHEADER.h"
#include <ctime>
#include <stdlib.h>

IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::MakeIpPacket(cv_iphd iphd){
    MakeEthernetPacket(iphd.ether);

    // js think don't need fix member value
    // ex) Version_length, Tos, Flag?

    Version_length = 0x45;
    ToS = 0x00;

    memcpy(TotalLength, iphd.TotalLength, 2);
    memcpy(Identifier, iphd.Identifier, 2);


    Flags[0] = 0x00; // or 0x4000
    Flags[1] = 0x00;

    TTL = 0xff;

    Protocol = iphd.Protocol; // UDP 0x11, TCP 0x06


    memcpy(SrcIP, MakeRandomIP().data(), IPSIZE);
    memcpy(DstIP, iphd.DstIP, IPSIZE);
}

vector<uchar> IPHeader::IpToPacket()
{
    vector<uchar> packet;
    vector<uchar> copy;

    packet = EthernetToPacket();

    packet.push_back(0x45);
    packet.push_back(0x00);
    for(int i=0; i < 2; i++) packet.push_back(TotalLength[i]);
    for(int i=0; i < 2; i++) packet.push_back(Identifier[i]);
    for(int i=0; i < 2; i++) packet.push_back(Flags[i]);
    packet.push_back(TTL);
    packet.push_back(Protocol);

    // add check sum
    for(int i=0; i < 2; i++) packet.push_back(0x00);
    for(int i=0; i < 4; i++) packet.push_back(SrcIP[i]);
    for(int i=0; i < 4; i++) packet.push_back(DstIP[i]);

    uint16_t checksum = IpCheckSum(packet.data());
    uchar a[2];
    memcpy(a, &checksum, 4);
    packet[24] = a[0];
    packet[25] = a[1];

    return packet;
}


vector<uchar> IPHeader::MakeRandomIP() {
    int cnt = 0;
    vector<uchar> randomIP;
    uchar tmp;


    for (int i = 0; i < 4; i++) {
        tmp = rand() % 256;
        while (cnt == 0) {

            if (tmp != 10 && tmp != 172 && tmp != 192) {
                cnt++;
                break;
            }
            tmp = rand() % 256;
        }
        randomIP.push_back(tmp);
    }

    return randomIP;

}

uint16_t IPHeader::IpCheckSum(uchar* packet)
{
    uint16_t check_sum = 0;
    int sum=0;
    uint16_t buf[10];
    memcpy(buf, &packet[14],20);
    for(int i=0; i<10;i++) sum+=static_cast<int>(buf[i]);

    check_sum = (sum>>16) + (sum & 0xffff);
    check_sum = (check_sum^0xffff);

    return check_sum;
}

