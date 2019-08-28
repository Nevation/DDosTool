#include "UDPHeader.h"

UDPHeader::UDPHeader()
{
}

UDPHeader::~UDPHeader()
{
}


void UDPHeader::MakeUdpPacket(cv_udphd udphd)
{
    vector<uchar> arr = MakerandomPort();
    MakeIpPacket(udphd.iphd);

    memcpy(Sport, arr.data(), 2);
    memcpy(Dport, udphd.Dport, 2);
    memcpy(u_length, udphd.u_length, 2);
    memcpy(u_checksum, udphd.u_checksum, 2);
}

vector<uchar> UDPHeader::MakerandomPort(){
  vector<uchar> rst;
  rst.push_back(rand() * 256);
  rst.push_back(rand() * 256);
  return rst;
}

vector<uchar> UDPHeader::UdpToPacket()
{
    vector<uchar> packet = IpToPacket();

    for(int i=0; i < 2; i++) packet.push_back(Sport[i]);
    for(int i=0; i < 2; i++) packet.push_back(Dport[i]);
    for(int i=0; i < 2; i++) packet.push_back(u_length[i]);
    for(int i=0; i < 2; i++) packet.push_back(0);
    // add check sum

    return MakeDummy(packet);
}
