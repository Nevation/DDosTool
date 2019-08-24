#pragma once
#include "Header.h"
#include "ETHERNET.h"
#include "IPHEADER.h"

class UDPHeader : public IPHeader {
public:
	UDPHeader();
	~UDPHeader();
	void MakeUdpPacket(uchar* packet);
	uchar* ToPacket();
protected:
	uchar Sport[2];
	uchar Dport[2];
	uchar u_length[2];
	uchar u_checksum[2];
};
