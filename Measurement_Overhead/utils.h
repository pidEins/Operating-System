#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <inttypes.h>
#include <sys/wait.h>

using namespace std;

uint64_t GetDifference(uint64_t first, uint64_t second) {
    uint64_t abs_diff = (first > second) ? (first - second): (second - first);
    return abs_diff;
}

static inline uint64_t rdtsc(void) {
	uint32_t lo, hi;
	__asm__ __volatile__("xor %%eax, %%eax;" "cpuid;" "rdtsc;": "=a" (lo), "=d" (hi));
	return (((uint64_t)hi << 32) | lo);
}

void perror(std::string str)
{
    cout<<str<<endl;
}

pid_t getpid( void )
{
    return syscall( __NR_getpid );
}

// Set the CPU Affinity to make sure that program runs on the one processor 
void SetCPUAffinityForCurrentProcess()
{
    cpu_set_t set;

    CPU_ZERO( &set );

    // Assign the CPU having id : 0
    CPU_SET( 0, &set );

    if (sched_setaffinity( getpid(), sizeof( cpu_set_t ), &set ))
    {
        perror( "sched_setaffinity" );
        exit(EXIT_FAILURE);
    }
}

void SetMaxPriorityToProcessor()
{
    /*********************************************************************************************
        To make sure context-switching processes are located on the same processor :
        1. Bind a process to a particular processor using sched_setaffinity.    
        2. To get the maximum priority value (sched_get_priority_max) that can be used with 
           the scheduling algorithm identified by policy (SCHED_FIFO).** 
    **********************************************************************************************/

    struct sched_param prio_param;
    int prio_max;

    memset(&prio_param,0,sizeof(struct sched_param));

    SetCPUAffinityForCurrentProcess();

    if( (prio_max = sched_get_priority_max(SCHED_FIFO)) < 0 )
    {
                perror("sched_get_priority_max");
        }

    prio_param.sched_priority = prio_max;
    if( sched_setscheduler(getpid(),SCHED_FIFO,&prio_param) < 0 )
    {
                perror("sched_setscheduler");
                exit(EXIT_FAILURE);
    }
}
