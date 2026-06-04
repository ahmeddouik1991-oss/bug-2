#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
/* Init: einmalig beim iocInit */
static long sysmonInit(aSubRecord *prec) {
return 0;
}
/* Process: bei jedem SCAN-Zyklus */
static long sysmonProcess(aSubRecord *prec) {
/* Load Average */
double loadavg[3] = {0.0, 0.0, 0.0};
getloadavg(loadavg, 3);
*(double *)prec->vala = loadavg[0]; /* LOAD1 */
*(double *)prec->valb = loadavg[1]; /* LOAD5 */
*(double *)prec->valc = loadavg[2]; /* LOAD15 */
/* CPU-Anzahl */
long ncpu = sysconf(_SC_NPROCESSORS_ONLN);
*(epicsInt32 *)prec->vald = (epicsInt32)ncpu;
/* Physischer RAM via sysctl */
uint64_t memsize = 0;
size_t len = sizeof(memsize);
sysctlbyname("hw.memsize", &memsize, &len, NULL, 0);
*(double *)prec->vale = (double)memsize / (1024.0*1024.0*1024.0);
/* Uptime */
struct timeval boottime = {0, 0};
len = sizeof(boottime);
sysctlbyname("kern.boottime", &boottime, &len, NULL, 0);
struct timeval now;
gettimeofday(&now, NULL);
*(double *)prec->valf = (double)(now.tv_sec - boottime.tv_sec);
return 0;
}
epicsRegisterFunction(sysmonInit);
epicsRegisterFunction(sysmonProcess);
