#include "PacketManager.h"

PacketManager::PacketManager(uchar* target){
    target_ip[0] = target[0];
    target_ip[1] = target[1];
    target_ip[2] = target[2];
    target_ip[3] = target[3];
}

vector<uchar> PacketManager::MakeDummy(){
  vector<uchar> dummy;
  uchar tmp;

  for (int i = 0; i < 1440; i++) {
    tmp = rand() % 255;
    dummy.push_back(tmp);
  }

  return dummy;
}

vector<uchar> PacketManager::MakeDummy(){
  vector<uchar> dummy;
  uchar tmp;

  for (int i = 0; i < 1440; i++) {
    tmp = rand() % 255;
    dummy.push_back(tmp);
  }

  return dummy;
}

uchar PacketManager::MakerandomPort(){
  uchar tmp;
  tmp = rand() * 65535
  return tmp;
}


bool PacketManager::MakePacket(int type, int cnt)
{
	switch (type)
	{
	case UDP:
		for (int i = 0; i < cnt; i++) {
			UDPHeader packet;

		}
		break;
	case TCP:
		break;
	default:
		break;
	}
	return false;
}
