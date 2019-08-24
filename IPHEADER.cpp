#include "IPHEADER.h"

struct iphdr {
	uchar total_length[2];
	uchar flags[2];
	uchar protocol;
	uchar ip_checksum[2];
	uchar src_ip[4];
	uchar dst_ip[4];
};
IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::IpInit() {
	Version_length = '0x45';
	ToS = '0x00';
}
void IPHeader::setIpHeader(struct iphdr ipheader) {
	TotalLength[0] = ipheader.total_length[0];
	TotalLength[1] = ipheader.total_length[1];
	Flags[0] = ipheader.flags[0];
	Flags[1] = ipheader.flags[1];
	IP_checksum[0] = ipheader.ip_checksum[0];
	IP_checksum[1] = ipheader.ip_checksum[1];
	Protocol = ipheader.protocol;
	IP_checksum[0] = ipheader.ip_checksum[0];
	IP_checksum[1] = ipheader.ip_checksum[1];
	memcpy(SrcIP, &ipheader.src_ip, sizeof(SrcIP));
	memcpy(DstIP, &ipheader.dst_ip, sizeof(DstIP));
}
/*
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
}*/

uchar* IPHeader::IpToPacket()
{
	return nullptr;
}
