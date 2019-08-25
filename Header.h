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



typedef struct{
  // Ethernet Header
  uchar targetMac[6];

  // IP header
  uchar TotalLength[2];
  uchar Identifier[2];
  uchar Flags[2];
  uchar Protocol;
  uchar IP_checksum[2];
  uchar DstIP[4];

  //TCP Header


  //UDP Header
  uchar Sport[2];
  uchar Dport[2];
  uchar u_length[2];
  uchar u_checksum[2];

}changeValue;
