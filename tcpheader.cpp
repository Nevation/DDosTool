#include "TCPHeader.h"

void TCPHeader::SetTcpheader(const uchar* packet){

    //packet += 14 + GetIpheaderLength();
    int idx = 0;
    SrcPort[0] = packet[idx++]; SrcPort[1] = packet[idx++];
    DstPort[0] = packet[idx++]; DstPort[1] = packet[idx++];
    for (int i=0;i<4; i++) Sequence[i] = packet[idx++];
    for (int i=0;i<4; i++) Ack[i] = packet[idx++];
    LenRev = packet[idx++];
    Rev = packet[idx++];
    Window[0] = packet[idx++]; Window[1] = packet[idx++];
    for (int i=0;i<4; i++) Checksum[i] = packet[idx++];
    for (int i=0;i<4; i++) Point[i] = packet[idx++];
}
uchar TCPHeader::GetTcpHeaderLength(){
    return ((LenRev & 0xf0) >> 4) * 4;
}


vector<uchar> TCPHeader::TcpToPacket(){
    vector<uchar> packet = IpToPacket();
    // add tcp packet;
    return MakeDummy(packet);
}
