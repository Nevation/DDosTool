#include "PacketManager.h"

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
	// uchar* IPArray[cnt];
	// �ڷ��� ����[����]
	// ���� = new �ڷ���[����]
}

vector<uchar*> PacketManager::GetPacketArray()
{
	vector<uchar*> result;
	for (int i = 0; i < udp.size(); i++) result.push_back(udp[i].ToPacket());

	return result;
}