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
    uint16_t tcpCheckSum(uint16_t len_tcp, uint16_t src_addr[], uint16_t dest_addr[], BOOL padding, uint16_t buff[]);
    uint16_t UdpCheckSum(uint16_t len_tcp, uint16_t src_addr[], uint16_t dest_addr[], BOOL padding, uint16_t buff[]);


private:
    vector<vector<uchar>> packets;
    int packet_cnt;
    uchar target_ip[4];
};
