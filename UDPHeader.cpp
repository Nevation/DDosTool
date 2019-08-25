#include "UDPHeader.h"

UDPHeader::UDPHeader()
{
}

UDPHeader::~UDPHeader()
{
}

void UDPHeader::MakeUdpPacket(uchar* packet)
{
//	MakeEthernetPacket(&packet[0]);
//	MakeIpPacket(&packet[14]);
	memcpy(Sport, &packet[34], 2);
	memcpy(Dport, &packet[36], 2);
	memcpy(u_length, &packet[38], 2);
	memcpy(u_checksum, &packet[40], 2);
}

uchar* UDPHeader::ToPacket()
{
	return nullptr;
}
