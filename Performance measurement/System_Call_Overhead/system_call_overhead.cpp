#include "utils.h"

#define COUNT 1000000

#define DO_SYSCALL_GET_PID syscall(SYS_getpid) 

class system_call_overhead
{
   private:
	
	uint64_t total_cycles;

   public:
	
	uint64_t getTotalCycles()
	{
		return total_cycles;
	}

	void setTotalCycles(uint64_t num)
	{
		total_cycles = num;
	}

	uint64_t getpidSystemCallOverhead();
	
	uint64_t timeSystemCallOverhead();
};

uint64_t system_call_overhead::timeSystemCallOverhead()
{
   uint64_t start_cycles, end_cycles;
   
   uint64_t sum = 0;
    
   for (int i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     clock(); 
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   return (sum/COUNT);
}

uint64_t system_call_overhead::getpidSystemCallOverhead()
{
   uint64_t start_cycles, end_cycles;
   
   uint64_t sum = 0;
    
   for (int i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     syscall(getpid()); 
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   return (sum/COUNT);
}

int main()
{
   std::string str;

   SetMaxPriorityToProcessor();

   system_call_overhead sc;

   str = "time()";
   sc.setTotalCycles(sc.timeSystemCallOverhead());
   cout<<"System call overhead for system call "<<str<<" is "<<sc.getTotalCycles()<<" cpu cycles"<<endl;

   str = "getpid()";
   sc.setTotalCycles(sc.getpidSystemCallOverhead());
   cout<<"System call overhead for system call "<<str<<" is "<<sc.getTotalCycles()<<" cpu cycles"<<endl;

   return 1;
}

