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



vector<uchar> MakerandomsPort(){
  vector<uchar> rst;
  rst.push_back(rand() * 256);
  rst.push_back(rand() * 256);
  return rst;
}
void TCPHeader::MakeTcpPacket(cv_tcphd tcphd){
    MakeIpPacket(tcphd.iphd);
    vector<uchar> sport = MakerandomsPort();
    for (int i=0; i< 2; i++) SrcPort[i] = sport[i];
    for (int i=0; i< 2; i++) DstPort[i] = tcphd.Dport[i];
    for (int i=0; i< 4; i++) Sequence[i] = tcphd.Sequence[i];
    for (int i=0; i< 4; i++) Ack[i] = tcphd.Ack[i];
    LenRev = tcphd.LenRev;
    Rev = tcphd.Rev;
    for (int i=0; i< 2; i++) Window[i] = tcphd.Window[i];
    for (int i=0; i< 4; i++) Checksum[i] = tcphd.Checksum[i];
    for (int i=0; i< 4; i++) Point[i] = tcphd.Point[i];
}

vector<uchar> TCPHeader::TcpToPacket(){
    vector<uchar> packet = IpToPacket();
    // add tcp packet;
    for (int i=0; i< 2; i++) packet.push_back(SrcPort[i]);
    for (int i=0; i< 2; i++) packet.push_back(DstPort[i]);
    for (int i=0; i< 4; i++) packet.push_back(Sequence[i]);
    for (int i=0; i< 4; i++) packet.push_back(Ack[i]);
    packet.push_back(LenRev);
    packet.push_back(Rev);
    for (int i=0; i< 2; i++) packet.push_back(Window[i]);
    for (int i=0; i< 4; i++) packet.push_back(Checksum[i]);
    for (int i=0; i< 4; i++) packet.push_back(Point[i]);

    return MakeDummy(packet);
}
