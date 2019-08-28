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

    //u_short check = ip_sum_calc(20, (u_short*)(&(copy.data())[14]));
    //memcpy(&packet[24], &check, 2);

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

vector<uchar> IPHeader::IpCheckSum(vector<uchar> packet)
{
    vector<uchar> result;
    int sum=0;
    uint16_t buf[10];
    memcpy(buf, &packet[14],20);
    for(int i=0; i<10;i++) sum+=static_cast<int>(buf[i]);

    sum = (sum>>16) + (sum & 0xffff);
    sum = (sum^0xffff);
    memcpy(result.data(), &sum ,4);
    return result;
}

u_short IPHeader::ip_sum_calc( u_short len_ip_header, u_short * buff )
{
    u_short word16;
    u_int sum = 0;
    u_short i;
    // make 16 bit words out of every two adjacent 8 bit words in the packet
    // and add them up
    for( i = 0; i < len_ip_header; i = i+2 )
    {
        word16 = ( ( buff[i]<<8) & 0xFF00 )+( buff[i+1] & 0xFF );
        sum = sum + (u_int) word16;
    }
    // take only 16 bits out of the 32 bit sum and add up the carries
    while( sum >> 16 )
        sum = ( sum & 0xFFFF ) + ( sum >> 16 );
    // one's complement the result
    sum = ~sum;

    return ((u_short) sum);
}
