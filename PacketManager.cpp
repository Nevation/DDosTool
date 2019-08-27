#include "PacketManager.h"

PacketManager::~PacketManager(){

}

PacketManager::PacketManager(uchar* target){
    target_ip[0] = target[0];
    target_ip[1] = target[1];
    target_ip[2] = target[2];
    target_ip[3] = target[3];
    packet_cnt = 0;
}

vector<uchar> PacketManager::MakeDummy(){
  vector<uchar> dummy;
  uchar tmp;

  for (int i = 0; i < 1440; i++) {
    tmp = rand() % 256;
    dummy.push_back(tmp);
  }

  return dummy;
}

bool PacketManager::MakePacket(int type, int cnt)
{
    packet_cnt += cnt;
	switch (type)
	{
	case UDP:
		for (int i = 0; i < cnt; i++) {
            UDPHeader packet;
            // packet make function
            packets.push_back(packet.UdpToPacket());
        }
		break;
	case TCP:
        for (int i = 0; i < cnt; i++) {
            TCPHeader packet;
            // packet make function
            packets.push_back(packet.TcpToPacket());
        }

		break;
	default:
		break;
	}
	return false;
}

vector<vector<uchar>> PacketManager::GetPackets(){
    return packets;
}


int PacketManager::GetPacketCnt(){
    return packet_cnt;
}

uint16_t PacketManager::tcpCheckSum(uint16_t len_tcp, uint16_t src_addr[], uint16_t dest_addr[], BOOL padding, uint16_t buff[]){
    uint16_t prot_tcp=6;
    uint16_t padd=0;
    uint16_t word16;
    uint32_t sum;

    	// Find out if the length of data is even or odd number. If odd,
    	// add a padding byte = 0 at the end of packet
    	if (padding&1==1){
    		padd=1;
    		buff[len_tcp]=0;
    	}

    	//initialize sum to zero
    	sum=0;

    	// make 16 bit words out of every two adjacent 8 bit words and
    	// calculate the sum of all 16 vit words
    	for (i=0;i<len_tcp+padd;i=i+2){
    		word16 =((buff[i]<<8)&0xFF00)+(buff[i+1]&0xFF);
    		sum = sum + (unsigned long)word16;
    	}
    	// add the TCP pseudo header which contains:
    	// the IP source and destinationn addresses,
    	for (i=0;i<4;i=i+2){
    		word16 =((src_addr[i]<<8)&0xFF00)+(src_addr[i+1]&0xFF);
    		sum=sum+word16;
    	}
    	for (i=0;i<4;i=i+2){
    		word16 =((dest_addr[i]<<8)&0xFF00)+(dest_addr[i+1]&0xFF);
    		sum=sum+word16;
    	}
    	// the protocol number and the length of the TCP packet
    	sum = sum + prot_tcp + len_tcp;

    	// keep only the last 16 bits of the 32 bit calculated sum and add the carries
        	while (sum>>16)
    		sum = (sum & 0xFFFF)+(sum >> 16);

    	// Take the one's complement of sum
    	sum = ~sum;

    return ((unsigned short) sum);
}


uint16_t PacketManager::udpCheckSum(uint16_t len_udp, uint16_t src_addr[], uint16_t dest_addr[], BOOL padding, uint16_t buff[])
{
    uint16_t prot_udp=17;
    uint16_t padd=0;
    uint16_t word16;
    uint32_t sum;

    	// Find out if the length of data is even or odd number. If odd,
    	// add a padding byte = 0 at the end of packet
    	if (padding&1==1){
    		padd=1;
    		buff[len_udp]=0;
    	}

    	//initialize sum to zero
    	sum=0;

    	// make 16 bit words out of every two adjacent 8 bit words and
    	// calculate the sum of all 16 vit words
    	for (i=0;i<len_udp+padd;i=i+2){
    		word16 =((buff[i]<<8)&0xFF00)+(buff[i+1]&0xFF);
    		sum = sum + (unsigned long)word16;
    	}
    	// add the UDP pseudo header which contains the IP source and destinationn addresses
    	for (i=0;i<4;i=i+2){
    		word16 =((src_addr[i]<<8)&0xFF00)+(src_addr[i+1]&0xFF);
    		sum=sum+word16;
    	}
    	for (i=0;i<4;i=i+2){
    		word16 =((dest_addr[i]<<8)&0xFF00)+(dest_addr[i+1]&0xFF);
    		sum=sum+word16;
    	}
    	// the protocol number and the length of the UDP packet
    	sum = sum + prot_udp + len_udp;

    	// keep only the last 16 bits of the 32 bit calculated sum and add the carries
        	while (sum>>16)
    		sum = (sum & 0xFFFF)+(sum >> 16);

    	// Take the one's complement of sum
    	sum = ~sum;

    return ((uint16_t) sum);
}
