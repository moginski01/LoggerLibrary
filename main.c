#include <stdio.h>
#include <unistd.h>
#include "log.h"


int main() {

    printf("Przyklad użycia biblioteki log:\n");
    logger_init(MAX,SIGRTMIN,SIGRTMIN+1);
//    int res = load_dump("dumpfile_16_1_2023_14_27_51.bin",0);
//    int res = load_dump("dumpfile_16_1_2023_14_27_51.bin",1);
//    printf("%d\n",res);
    for(int i=0;i<10;i++){
        log(LOW,"LOW Testowy log maina nr lini:%d",__LINE__);
        log(NORMAL,"NORMAL Testowy log maina nr lini:%d",__LINE__);
        log(HIGH,"HIGH Testowy log maina nr lini:%d",__LINE__);
        if(i==2){
            log(1,"Zrobienie dumpa %d",__LINE__);
            send_signal(getpid(),SIGRTMIN+1,0);

        }
        if(i==3){
            log(1,"Wyłączenie log nr lini:%d",__LINE__);
            send_signal(getpid(),SIGRTMIN,OFF);

        }
        if(i==6){
            //zmiana poziomu istotności
            send_signal(getpid(),SIGRTMIN,STANDARD);

        }
//        sleep(1);
//        send_signal(getpid(),SIGRTMIN+1,1);
        sleep(1);
    }

    logger_destroy();

    return 0;
}
