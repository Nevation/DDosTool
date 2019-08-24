#pragma once
#include "Header.h"
#include "UDPHeader.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "PacketManager.h"

struct DDoS {
public:
	DDoS();
    bool SetOption();
	void ExecuteAttack();
private:
    string Dev;
    PacketManager* manager;

};
