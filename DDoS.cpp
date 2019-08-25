#include "DDoS.h"
#include "etc_function.h"

DDoS::~DDoS(){
    delete manager;
    pcap_close(handle);
}

void DDoS::ExecuteAttack()
{
	
}

bool DDoS::Setting(){
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(Dev.c_str(), BUFSIZ, 1, 1, errbuf);
}

bool DDoS::SetOption(){
    /*
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

    printf("-<protocol1> <count1> <size1> -<protocol2> <count2> <size2> ...\n");
    printf("Enter Command: ");
    string command;
    char vue;
    while(true){
        vue = getchar();
        cout << vue << endl;
        if (vue == '\n') break;
        else command += vue;
    }
    vector<string> options = str_split(command, '-');
    for (auto k: options){
        cout << k << endl;
    }
    */
    return true;
}
