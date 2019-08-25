#include "IPHEADER.h"
#include <ctime>

IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::MakeIpPacket(chageValue cv)
{
	MakeEthernetPacket(cv->targetMac);

	Version_length = 0x45;
	ToS = 0x00;

	memcpy(TotalLength, cv->TotalLength, 2);
	memcpy(Identifier, cv->Identifier, 2);

	Flags[0] = 0x00; // or 0x4000
	Flags[1] = 0x00;

	TTL = 0xff;

	Protocol = cv->Protocol; // UDP 0x11, TCP 0x06

	//IP checksum

	memcpy(SrcIP, MakeRandomIP()/* attacker IP*/, IPSIZE);
	memcpy(DstIP, cv->DstIP, IPSIZE);
}

uchar* IPHeader::IpToPacket()
{
	uchar* packet = new uchar[20];

  packet[0] = 0x45;
	packet[1] = 0x00;
	memcpy(&packet[2], TotalLength, 2);
	memcpy(&packet[4], Identifier, 2);
	packet[6] = Flags[0]; // or 0x4000
	packet[7] = Flags[1];
	packet[8] = TTL;
	packet[9] = Protocol;

	//checksum

	memcpy(&packet[12], SrcIP, 4);
	memcpy(&packet[16], DstIP, 4);
	return packet;
}







vector<uchar> IPHeader::MakeRandomIP() {
	int cnt = 0;
	vector<uchar> randomIP;
	uchar tmp;


	for (int i = 0; i < 4; i++) {
		tmp = rand() % 255;
		while (cnt == 0) {

			if (tmp != 10 && tmp != 172 && tmp != 192) {
				cnt++;
				break;
			}
			tmp = rand() % 255;
		}
		randomIP.push_back(tmp);
	}

	return randomIP;

}
