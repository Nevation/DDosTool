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
