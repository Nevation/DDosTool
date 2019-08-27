#pragma once
#include "Header.h"
#include "ETHERNET.h"
#include "IPHEADER.h"

class UDPHeader : public IPHeader {
public:
	UDPHeader();
	~UDPHeader();
    void SetUdp();
    vector<uchar> MakerandomPort();
    void MakeUdpPacket(cv_udphd udphd);
    vector<uchar> UdpToPacket();
protected:
	uchar Sport[2];
	uchar Dport[2];
	uchar u_length[2];
	uchar u_checksum[2];
};
