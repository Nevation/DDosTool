#pragma once
#include "Header.h"
#include "ETHERNET.h"

class IPHeader : public EthernetHeader {
public:
	IPHeader();
	~IPHeader();
	void MakeIpPacket(uchar* packet);
	void IpInit();
	void setIpHeader(struct iphdr iphdr);
	uchar* IpToPacket();
protected:
	uchar Version_length;
	uchar ToS;
	uchar TotalLength[2];
	uchar Identifier[2];
	uchar Flags[2];
	uchar TTL;
	uchar Protocol;
	uchar IP_checksum[2];
	uchar SrcIP[4];
	uchar DstIP[4];
};