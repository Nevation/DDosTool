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
	UDP = 0,
	TCP,

};
