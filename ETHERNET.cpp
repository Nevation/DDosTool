#include "ETHERNET.h"

EthernetHeader::EthernetHeader()
{
}

EthernetHeader::~EthernetHeader()
{
}

uchar* EthernetHeader::EthernetToPacket()
{
	return nullptr;
}
void EthernetHeader::setEthernet(uchar* dst, uchar* src) {
	memcpy(Dest, &dst, MACSIZE);
	memcpy(Src, &src, MACSIZE);
	memset(&Type[0], '0x08', sizeof(Type));
	memset(&Type[1], '0x00', sizeof(Type));
}
