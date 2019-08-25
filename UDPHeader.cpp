#include "UDPHeader.h"

UDPHeader::UDPHeader()
{
}

UDPHeader::~UDPHeader()
{
}

void UDPHeader::MakeUdpPacket(changeValue cv)
{
  MakeIpPacket(cv);
	memcpy(Sport, MakerandomPort(), 2);
	memcpy(Dport, MakerandomPort(), 2);

	u_length[0] = 0x05; 	// 1400
	u_length[1] = 0x78;

	//UDP checksum
}

uchar* UDPHeader::ToPacket()
{
	uchar* packet = new uchar[8];

	memcpy(&packet[0], Sport, 2);
	memcpy(&packet[2], Dport, 2);
	packet[4] = u_length[0];
	packet[5] = u_length[1];

	//UDP checksum

	return packet;
}

vector<uchar> UDPHeader::MakerandomPort(){
  vector<uchar> randomPort;
	uchar tmp;
	for(int i = 0 ; i < 2; i++){
		tmp = rand() % 256;
		randomPort.push_back(tmp);
	}
  return randomPort;
}
