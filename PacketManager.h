#pragma once

#include "UDPHeader.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "Header.h"


class PacketManager{
public:
    PacketManager() {}
    PacketManager(uchar* target);
    ~PacketManager() {}

    vector<uchar> MakeDummy();



    bool MakePacket(int type, int cnt);
    vector<uchar*> GetPacketArray();
private:
    vector<uchar*> packets;
    vector<int> packets_size;
    int packet_cnt;
    uchar target_ip[4];
};
