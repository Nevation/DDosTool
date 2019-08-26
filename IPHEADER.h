#pragma once
#include "Header.h"
#include "ETHERNET.h"

class IPHeader : public EthernetHeader {
public:
	IPHeader();
	~IPHeader();

    void MakeIpPacket(cv_iphd iphd);

    vector<uchar> IpToPacket();

	vector<uchar> MakeRandomIP();

    uint16_t IpCheckSum(vector<uchar> packet);
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
