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
    DDoS(string dev){
        Dev = dev;
    }
    ~DDoS();
    bool Setting();
    bool SetOption();
	void ExecuteAttack();
    void Attack(int start, int end);
private:
    string Dev;
    pcap_t* handle;
    PacketManager* manager;

};
