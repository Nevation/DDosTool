#include "PacketManager.h"

PacketManager::PacketManager(uchar* target){
    //Global struct changeValue cv;
    cv->DstIP[0] = target[0];
    cv->DstIP[1] = target[1];
    cv->DstIP[2] = target[2];
    cv->DstIP[3] = target[3];
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


bool PacketManager::MakePacket(int type, int cnt)
{
	switch (type)
	{
	case UDP:
		for (int i = 0; i < cnt; i++) {
			UDPHeader packet;
      packet::MakeUdpPacket(cv);

		}
		break;
	case TCP:
		break;
	default:
		break;
	}
	return false;
}
