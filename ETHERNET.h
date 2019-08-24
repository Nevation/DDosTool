#pragma once
#include "Header.h"

class EthernetHeader {
public:
	EthernetHeader();
	~EthernetHeader();
	uchar* EthernetToPacket();
	void setEthernet(uchar* dst, uchar* src);
protected:
	uchar Dest[6];
	uchar Src[6];
	uchar Type[2];
};
