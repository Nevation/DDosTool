#pragma once
#include "Header.h"
#include "UDP.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "PacketManager.h"
struct DDoS {
public:
	DDoS();
	DDoS(char* dev);
	void ExecuteAttack();
private:
	char* Dev;
	PacketManager manager;

};
