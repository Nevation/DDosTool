#include "IPHEADER.h"

IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::MakeIpPacket(uchar* packet)
{
	MakeEthernetPacket(&packet[0]);
	Version_length = packet[14];
	ToS = packet[15];
	memcpy(TotalLength, &packet[16], 2);
	memcpy(Identifier, &packet[18], 2);
	memcpy(Flags, &packet[20], 2);
	TTL = packet[22];
	Protocol = packet[23];
	memcpy(IP_checksum, &packet[24], 2);
	memcpy(SrcIP, &packet[26], IPSIZE);
	memcpy(DstIP, &packet[30], IPSIZE);
}

uchar* IPHeader::IpToPacket()
{
	return nullptr;
}
