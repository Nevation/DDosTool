#include "Header.h"
#include "ETHERNET.h"
#include "IPHEADER.h"
#include "UDP.h"
#include "DDoS.h"
#include "PacketManager.h"
int main() {
	char dev[24];
	scanf("%s", dev);
	printf("%s\n", dev);
	EthernetHeader eth;
	return 0;
	DDoS ddos(dev);
	ddos.ExecuteAttack();
}