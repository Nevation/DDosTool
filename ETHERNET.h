#pragma once
#include "Header.h"

class EthernetHeader {
public:
	EthernetHeader();
	~EthernetHeader();
    void MakeEthernetPacket(cv_ether ether);

    vector<uchar> EthernetToPacket();
protected:
	uchar Dest[6];
	uchar Src[6];
	uchar Type[2];
};
