#include "utils.h"

#define COUNT 100

int	firstpipe[2];

class context_switch
{
   private:
	
	uint64_t thread_cpu_cycles;
	uint64_t process_cpu_cycles;

   public:
	
	uint64_t getTotalCPUCyclesForThreadContextSwitch()
	{
		return thread_cpu_cycles;
	}

	void setTotalCPUCyclesForThreadContextSwitch(uint64_t num)
	{
		thread_cpu_cycles = num;
	}
	
	uint64_t getTotalCPUCyclesForProcessContextSwitch()
	{
		return process_cpu_cycles;
	}

	void setTotalCPUCyclesForProcessContextSwitch(uint64_t num)
	{
		process_cpu_cycles = num;
	}
	uint64_t cpuCyclesPerProcessContextSwitch();

	uint64_t cpuCyclesPerThreadContextSwitch();

	uint64_t process_context_switch_overhead();	
	
	uint64_t thread_context_switch_overhead();	
};

void *threadFunction(void *)
{
    uint64_t end_cycles = rdtsc();
    
    write(firstpipe[1], (void *)&end_cycles, sizeof(end_cycles));
   
    pthread_exit(NULL);    
}

uint64_t context_switch::cpuCyclesPerThreadContextSwitch()
{
    int     ret=-1;

    uint64_t start_cycles = 0;
    uint64_t end_cycles = 0;   
   
    pthread_t tid;

    // Create an unnamed first pipe
    if (pipe(firstpipe) == -1) 
    {
            cout<<"Failed to create pipe"<<endl;
            exit(-1);
    }

    pthread_create(&tid, NULL, threadFunction, NULL);

    start_cycles = rdtsc();
    
    pthread_join(tid, NULL);
    
    read(firstpipe[0], (void *)&end_cycles, sizeof(end_cycles));
 
    if ( end_cycles >=0 && start_cycles >=0 )   
    {
	return GetDifference(end_cycles, start_cycles) ;
    }
    
    return 0;
}

uint64_t context_switch::cpuCyclesPerProcessContextSwitch()
{
    int     ret=-1;
    int     firstpipe[2];

    uint64_t start_cycles = 0;
    uint64_t end_cycles = 0;   
    
    // Create an unnamed first pipe
    if (pipe(firstpipe) == -1) 
    {
            cout<<"parent: Failed to create pipe"<<endl;
            exit(-1);
    }

    ret = fork();
    if( ret < 0 )
    {
        cout<<"Fork failed"<<endl;
        exit(-1);
    }
    else if( ret == 0 )
    {
        end_cycles = rdtsc();

	write(firstpipe[1], (void *)&end_cycles, sizeof(uint64_t));
        exit(1);
    }
    else 
    {
        start_cycles = rdtsc();
        
        wait(NULL);
        read(firstpipe[0], (void *)&end_cycles, sizeof(uint64_t));
    }   

    if ( end_cycles >=0 && start_cycles >=0 )   
    {
	return GetDifference(end_cycles, start_cycles) ;
    }
    
    return 0;
}

uint64_t context_switch::process_context_switch_overhead()
{
    uint64_t sum = 0;

    int i = 0;
    while(i<COUNT)
    {
	sum += cpuCyclesPerProcessContextSwitch();
        i++;
    }

    return (sum/COUNT); 
}


uint64_t context_switch::thread_context_switch_overhead()
{
    uint64_t sum = 0;

    int i = 0;
    while(i<COUNT)
    {
	sum += cpuCyclesPerThreadContextSwitch();
        i++;
    }

    return (sum/COUNT); 
}

int main()
{
    
    SetMaxPriorityToProcessor();

    context_switch cs;

    cs.setTotalCPUCyclesForThreadContextSwitch(cs.thread_context_switch_overhead()); 
    cout<<"context switch overhead between two threads as CPU cycles :"<<cs.getTotalCPUCyclesForThreadContextSwitch()<<endl;;

    cs.setTotalCPUCyclesForProcessContextSwitch(cs.process_context_switch_overhead()); 
    cout<<"context switch overhead between two process as CPU cycles :"<<cs.getTotalCPUCyclesForProcessContextSwitch()<<endl;;

    return 0;
}


