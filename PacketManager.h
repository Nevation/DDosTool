#pragma once
#include "TCPHeader.h"
#include "UDPHeader.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "Header.h"


class PacketManager{
public:
    PacketManager() { }
    PacketManager(uchar* target);
    ~PacketManager();

    vector<uchar> MakeDummy();
    bool MakePacket(int type, int cnt);
    vector<vector<uchar>> GetPackets();
    int GetPacketCnt();
private:
    vector<vector<uchar>> packets;
    int packet_cnt;
    uchar target_ip[4];
};
