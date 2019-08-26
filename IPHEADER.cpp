#include "IPHEADER.h"
#include <ctime>

IPHeader::IPHeader()
{
}

IPHeader::~IPHeader()
{
}

void IPHeader::MakeIpPacket(cv_iphd iphd){
    MakeEthernetPacket(iphd.ether);

    // js think don't need fix member value
    // ex) Version_length, Tos, Flag?

    Version_length = 0x45;
    ToS = 0x00;

    memcpy(TotalLength, iphd.TotalLength, 2);
    memcpy(Identifier, iphd.Identifier, 2);


    Flags[0] = 0x00; // or 0x4000
    Flags[1] = 0x00;

    TTL = 0xff;

    Protocol = iphd.Protocol; // UDP 0x11, TCP 0x06


    memcpy(SrcIP, MakeRandomIP().data(), IPSIZE);
    memcpy(DstIP, iphd.DstIP, IPSIZE);
}
uint16_t IPHeader::IpCheckSum(vector<uchar> packet)
{
    uint8_t chksum=0;
    int sum=0;
    uint16_t buf[10];
    memcpy(&buf[0], &packet[0],20);
    for(int i=0; i<10;i++){
        sum+=static_cast<int>(buf[i]);
    }
    chksum = (sum>>16) + (sum & 0xffff);
    chksum = (chksum^0xffff);
    return chksum;
}
vector<uchar> IPHeader::IpToPacket()
{
    vector<uchar> packet;

    packet = EthernetToPacket();

    packet.push_back(0x45);
    packet.push_back(0x00);
    for(int i=0; i < 2; i++) packet.push_back(TotalLength[i]);
    for(int i=0; i < 4; i++) packet.push_back(Identifier[i]);
    for(int i=0; i < 2; i++) packet.push_back(Flags[i]);
    packet.push_back(TTL);
    packet.push_back(Protocol);

    // checksum init 0x0000
    packet.push_back(0x00);
    packet.push_back(0x00);

    // add check sum
    //for(int i=0; i < 2; i++) packet.push_back(IP_checksum[i]);

    for(int i=0; i < 4; i++) packet.push_back(SrcIP[i]);
    for(int i=0; i < 4; i++) packet.push_back(DstIP[i]);
    uint16_t chk1=IpCheckSum(packet)<<8;
    uint16_t chk2=IpCheckSum(packet)>>8;
    packet[12]=chk1;
    packet[13]=chk2;

    return packet;
}


vector<uchar> IPHeader::MakeRandomIP() {
	int cnt = 0;
	vector<uchar> randomIP;
	uchar tmp;


	for (int i = 0; i < 4; i++) {
        tmp = rand() % 256;
		while (cnt == 0) {
			
			if (tmp != 10 && tmp != 172 && tmp != 192) {
				cnt++;
				break;
			}
            tmp = rand() % 256;
		}
		randomIP.push_back(tmp);
	}

	return randomIP;
 
}
