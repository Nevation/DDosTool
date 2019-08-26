#include "ETHERNET.h"

EthernetHeader::EthernetHeader()
{
}

EthernetHeader::~EthernetHeader()
{
}


void EthernetHeader::MakeEthernetPacket(cv_ether ether)
{
    //
    memcpy(Dest, ether.targetmac, MACSIZE);

    // insert attacker mac
    // memcpy(Src, &packet[6], MACSIZE);

    Type[0] = 0x08;
    Type[1] = 0x00;
}

vector<uchar> EthernetHeader::EthernetToPacket()
{
    vector<uchar> packet;

    for (int i=0; i< MACSIZE; i++) packet.push_back(Dest[i]);
    for (int i=0; i< MACSIZE; i++) packet.push_back(Src[i]);
    packet.push_back(Type[0]);
    packet.push_back(Type[1]);

    return packet;
}
