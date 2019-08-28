#pragma once
#include "Header.h"
#include "ETHERNET.h"
#include "IPHEADER.h"

class TCPHeader : public IPHeader {
public:
    TCPHeader() {}
    ~TCPHeader() {}
    void SetTcpheader(const uchar* packet);
    uchar GetTcpHeaderLength();
    vector<uchar> TcpToPacket();
    void MakeTcpPacket(cv_tcphd tcphd);
protected:
    uchar SrcPort[2];
    uchar DstPort[2];
    uchar Sequence[4];
    uchar Ack[4];
    uchar LenRev;
    uchar Rev;
    uchar Window[2];
    uchar Checksum[4];
    uchar Point[4];
};
