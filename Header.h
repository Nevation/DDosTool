#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;


typedef unsigned char uchar;
#define MACSIZE 6
#define IPSIZE 4

enum PacketType {
    UDP = 1,
	TCP,

};


struct cv_ether{  //cv == changeValue
    uchar targetmac[MACSIZE];
};

struct cv_iphd{
    cv_ether ether;
    uchar TotalLength[2];
    uchar Identifier[2];
    uchar Flags[2];
    uchar Protocol;
    uchar IP_checksum[2];
    uchar DstIP[4];
};

struct cv_udphd{
    cv_iphd iphd;
    uchar Sport[2];
    uchar Dport[2];
    uchar u_length[2];
    uchar u_checksum[2];
};


struct cv_tcphd{
  cv_iphd iphd;
  uchar DstPort[2];
  uchar Sequence[4];
  uchar Ack[4];
  uchar LenRev;
  uchar Rev;
  uchar Window[2];
  uchar Checksum[2];
  uchar Point[2];
};
/*
struct cv_tcpPseudohd{
  uchar SrcIp[4];
  uchar DstIp[4];
  uchar Reserve;  //always 0x00
  uchar Protocol; //always 0x06
  uchar tcpTotalLen[2]; //tcp header length + data length(1400?)
};

*/
