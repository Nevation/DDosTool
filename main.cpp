#include "DDoSTool.h"
#include "etc_function.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    DDoS DDoSTool("ens33");
    DDoSTool.Setting();
    //DDoSTool.SetOption();
    const int fork_cnt = 20;

    for (int i=0; i<fork_cnt; i++){
        pid_t pid = fork();
        int status;
        //printf("[%d] \n", pid);
        DDoSTool.ExecuteAttack();
        if (pid != 0)
            wait(&status);
    }


    return 0;
}
