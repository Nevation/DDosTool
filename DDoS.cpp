#include "DDoS.h"

void DDoS::ExecuteAttack()
{
	
}

bool DDoS::SetOption(){
    string ip;

    printf("Enter Dev: ");
    cin >> Dev;

    try {
        printf("Enter IP: ");
        cin >> ip;


        int size = ip.size();
        string ip_int[4];
        uchar ip_hex[4];
        int index = 0;

        for(int i=0; i < size; i++){
            if (ip[i] == '.') index++;
            else ip_int[index].push_back(ip[i]);
        }

        for(int i=0;i<4;i++){
            ip_hex[i] = atoi(ip_int[i].c_str());
        }

        manager = new PacketManager(ip_hex);
    } catch (exception ew) {
        printf("Check IP Address %s\n", ip.c_str());
        return false;
    }

    while(1){
        PacketType type;
        int cnt;
        printf("1. UDP \t\t 2. TCP \t\t 3. HTTP\n");
        printf("Enter Packet Type: ");
        scanf("%d", &type);

        printf("Packet Count: ");
        scanf("%d", &cnt);

        manager->MakePacket(type, cnt);
    }

    return true;
}
