#pragma once
#include "Header.h"

class EthernetHeader {
public:
	EthernetHeader();
	~EthernetHeader();
	void MakeEthernetPacket(uchar* packet);
	uchar* EthernetToPacket();
protected:
	uchar Dest[6];
	uchar Src[6];
	uchar Type[2];
};
