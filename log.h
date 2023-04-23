//
// Created by root on 1/15/23.
//

#ifndef LOGGERPROJECT_LOG_H
#define LOGGERPROJECT_LOG_H

#include <signal.h>
#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdarg.h>
#include <string.h>

enum LogLevel{
    OFF,
    MIN,
    STANDARD,
    MAX
};

enum ImportanceLevel{
    NONE,
    HIGH,
    NORMAL,
    LOW
};

int logger_init(int logging_level, int sig_no_1, int sig_no_2);
void send_signal(int pid, int signo, int value);
int log(int level, char *msg,...);
void *dump(void *arg);
int load_dump(char *dump_filename,int option);
void logger_destroy();
#endif //LOGGERPROJECT_LOG_H
