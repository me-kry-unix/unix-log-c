#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum) {
   printf("Caught signal %d, coming out...\n", signum);
   closelog();
   exit(1);
}

int main(int argc, char **argv) {
   signal(SIGINT, sighandler);
   openlog("syslogTestDaemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
   syslog(LOG_NOTICE, "Program started by User %d", getuid());
   syslog(LOG_INFO, "A tree falls in a forest");

   int counter = 1;
   while (1) {
       syslog(LOG_EMERG, "log LOG_EMERG %d", counter);
       syslog(LOG_ALERT, "log LOG_ALERT %d", counter);
       syslog(LOG_CRIT, "log LOG_CRIT %d", counter);
       syslog(LOG_ERR, "log LOG_ERR %d", counter);
       syslog(LOG_WARNING, "log LOG_WARNING %d", counter);
       syslog(LOG_NOTICE, "log LOG_NOTICE %d", counter);
       syslog(LOG_INFO, "log LOG_INFO %d", counter);
       syslog(LOG_DEBUG, "log LOG_DEBUG %d", counter);

       printf("Going to sleep for a second...\n");
       sleep(1);
       counter++;
   }

   closelog();
}
