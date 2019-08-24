#include "IPHEADER.h"
#include <ctime>

IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::MakeIpPacket(uchar* packet)
{
	MakeEthernetPacket(&packet[0]);
	Version_length = packet[14];
	ToS = packet[15];
	memcpy(TotalLength, &packet[16], 2);
	memcpy(Identifier, &packet[18], 2);
	memcpy(Flags, &packet[20], 2);
	TTL = packet[22];
	Protocol = packet[23];
	memcpy(IP_checksum, &packet[24], 2);
	memcpy(SrcIP, &packet[26], IPSIZE);
	memcpy(DstIP, &packet[30], IPSIZE);
}

uchar* IPHeader::IpToPacket()
{
	return nullptr;
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