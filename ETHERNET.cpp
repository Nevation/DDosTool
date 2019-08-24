#include "ETHERNET.h"

EthernetHeader::EthernetHeader()
{
}

EthernetHeader::~EthernetHeader()
{
}

void EthernetHeader::MakeEthernetPacket(uchar* packet)
{
	memcpy(Dest, &packet[0], MACSIZE);
	memcpy(Src, &packet[6], MACSIZE);
	memcpy(Type, &packet[12], 2);
}

uchar* EthernetHeader::EthernetToPacket()
{
	return nullptr;
}
