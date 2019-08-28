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
    //00:0c:29:ae:ac:39;
    Src[0] = 0x00;
    Src[1] = 0x0c;
    Src[2] = 0x29;
    Src[3] = 0xae;
    Src[4] = 0xac;
    Src[5] = 0x39;


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
