#include "PacketManager.h"

PacketManager::PacketManager(uchar* target){
    target_ip[0] = target[0];
    target_ip[1] = target[1];
    target_ip[2] = target[2];
    target_ip[3] = target[3];
}

bool PacketManager::MakePacket(int type, int cnt)
{
	switch (type)
	{
	case UDP:
		for (int i = 0; i < cnt; i++) {
			UDPHeader packet;


			udp.push_back(packet);
		}
		break;
	case TCP:
		break;
	default:
		break;
	}
	return false;
}

void PacketManager::MakeIPArray(int cnt)
{
}

vector<uchar*> PacketManager::GetPacketArray()
{
	vector<uchar*> result;
	for (int i = 0; i < udp.size(); i++) result.push_back(udp[i].ToPacket());

	return result;
}
