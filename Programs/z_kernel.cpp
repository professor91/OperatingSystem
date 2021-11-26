// Kernel Commands

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  system("clear");
  system("echo");
  system("echo The CPU Model");
  system("cat /proc/cpuinfo | grep model");
  system("echo");
  system("echo the Kernel Version");
  system("cat /proc/sys/kernel/osrelease|cut -c 1-4");
  system("echo");
  system("echo The amount of time CPU has spent in different modes");
  system("echo");
  system("echo User Mode \t:");
  system("cat /proc/stat|grep cpu");
  system("echo");
  system("echo The number of context switches are");
  system("cat /proc/stat|grep 'ctxt' |cut -c 6-12");
  system("echo The number of processes since system was last booted");
  system("cat /proc/stat|grep 'processes' |cut -c 11-15");
  system("echo configured memory details");
  system("echo The total memory in kilobytes is ");
  system("free |grep Mem|cut -c 14-20");
  system("echo The used Memory in kilobytes is ");
  system("free |grep Mem|cut -c 27-32");
  system("echo The list of load average for past -1,5 and 15 minutes");
  system("cat /proc/loadavg");
  return (0);
}
