#pragma once
#include "Header.h"
#include "UDPHeader.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "PacketManager.h"
#include <pcap.h>

struct DDoS {
public:
    DDoS() {};
    bool SetOption();
	void ExecuteAttack();
private:
    string Dev;
    pcap_t* handle;
    PacketManager* manager;

};
