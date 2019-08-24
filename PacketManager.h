#pragma once

#include "UDPHeader.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "Header.h"

class PacketManager{
public:
    PacketManager() { }
    PacketManager(uchar* target);
    ~PacketManager() {}
	bool MakePacket(int type, int cnt);
	void MakeIPArray(int cnt);
    vector<uchar*> GetPacketArray();
private:
	vector<UDPHeader> udp;
    uchar target_ip[4];
};
