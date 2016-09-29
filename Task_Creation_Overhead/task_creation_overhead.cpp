#include "utils.h"

#define COUNT 100

class task_creation_overhead
{
   private:
	
	uint64_t thread_cpu_cycles;
	uint64_t process_cpu_cycles;

   public:
	
	uint64_t getThreadCreationOverhead()
	{
		return thread_cpu_cycles;
	}

	void setThreadCreationOverhead(uint64_t num)
	{
		thread_cpu_cycles = num;
	}
	
	uint64_t getProcessCreationOverhead()
	{
		return process_cpu_cycles;
	}

	void setProcessCreationOverhead(uint64_t num)
	{
		process_cpu_cycles = num;
	}

	uint64_t process_creation_overhead();	
	
	uint64_t thread_creation_overhead();	
};

void *threadFunction(void *)
{ 
     pthread_exit(NULL);
}

uint64_t task_creation_overhead::thread_creation_overhead()
{
   pthread_t td;
   uint64_t start_cycles, end_cycles;
 
   uint64_t sum = 0;
  
   rdtsc();
   for (int i = 0; i < COUNT; i++) {
    	start_cycles = rdtsc();

    	pthread_create(&td, NULL, threadFunction, NULL);
    	pthread_join(td, NULL);

    	end_cycles = rdtsc();
    	sum += end_cycles - start_cycles;
   }
  
   return (sum/COUNT); 
}

uint64_t task_creation_overhead::process_creation_overhead()
{
   uint64_t start_cycles, end_cycles;
   
   uint64_t sum = 0;
  
   pid_t pid;
   
   for(int i=0; i<COUNT; i++)
   {
   	start_cycles = rdtsc();
   	pid = fork();
   
   	if( pid == 0)
   	{
      		exit(1);
   	}
   	else
   	{
    		end_cycles = rdtsc();
      		sum += (end_cycles - start_cycles);
       		wait(NULL);
   	}
    }
 
   return (sum/COUNT);
}

int main()
{
    SetMaxPriorityToProcessor();

    task_creation_overhead ts;

    ts.setProcessCreationOverhead(ts.process_creation_overhead()); 
    cout<<"Process creation overhead as cpu cycles:"<<ts.getProcessCreationOverhead()<<endl;;

    ts.setThreadCreationOverhead(ts.thread_creation_overhead()); 
    cout<<"Thread creation overhead as cpu cycles:"<<ts.getThreadCreationOverhead()<<endl;;

   return 1;
}

