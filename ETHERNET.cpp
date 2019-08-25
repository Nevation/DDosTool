#include "ETHERNET.h"

EthernetHeader::EthernetHeader()
{
}

EthernetHeader::~EthernetHeader()
{
}

void EthernetHeader::MakeEthernetPacket(uchar* targetMac)
{
	memcpy(Dest, targetMac, MACSIZE);
	memcpy(Src, /*attacker Mac*/, MACSIZE);
	Type[0] = 0x08;
	Type[1] = 0x00;
}

uchar* EthernetHeader::EthernetToPacket()
{
	uchar* packet = new uchar[14];
	memcpy(&packet[0], Dest, 6);
	memcpy(&packet[6], Src, 6);
	memcpy(&packet[12], Type, 2);
	return packet;
}
