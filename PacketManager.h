#pragma once

#include "UDP.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "Header.h"

class PacketManager : public UDPHeader{
public:
	PacketManager() {};
	~PacketManager() {};
	bool MakePacket(int type, int cnt);
	void MakeIPArray(int cnt);
	vector<uchar*> GetPacketArray();
private:
	vector<uchar[4]> ipaddr;
	vector<UDPHeader> udp;
	//vector<�ڷ���> ���� = > �ڷ��� ������ ���� 
};