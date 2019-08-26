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


struct cv_ether{
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
