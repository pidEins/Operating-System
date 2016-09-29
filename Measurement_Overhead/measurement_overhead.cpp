#include "utils.h"

#define COUNT 1000000

class measurement_overhead
{
    private: 
	uint64_t loop_overhead_cycles;
	uint64_t read_overhead_cycles;
		 
    public:

	uint64_t getLoopOverheadCycles()
	{
		return loop_overhead_cycles;
	}

	void setLoopOverheadCycles(uint64_t num)
	{
		loop_overhead_cycles = num;
	}
	
	uint64_t getReadOverheadCycles()
	{
		return read_overhead_cycles;
	}

	void setReadOverheadCycles(uint64_t num)
	{
		read_overhead_cycles = num;
	}

	uint64_t loopOverhead();

	uint64_t readOverhead();

}; 

uint64_t measurement_overhead::readOverhead()
{
   uint64_t start_cycles, end_cycles;
   uint64_t total_cycles;
   
   uint64_t sum = 0;
    
   for (int i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   return (sum/COUNT);
}

uint64_t measurement_overhead::loopOverhead()
{
   uint64_t start_cycles, end_cycles;
   uint64_t total_cycles;
   
   start_cycles = rdtsc();
   for (int i = 0; i < COUNT; i++) {
   }
   end_cycles = rdtsc();
   total_cycles = end_cycles - start_cycles;

   return (total_cycles/COUNT);
}

int main()
{
    SetMaxPriorityToProcessor();

    measurement_overhead mo;

    mo.setLoopOverheadCycles(mo.loopOverhead()); 
    cout<<"Loop overhead as cpu cycles "<<mo.getLoopOverheadCycles()<<endl;

    mo.setReadOverheadCycles(mo.readOverhead()); 
    cout<<"Read overhead as cpu cycles "<<mo.getReadOverheadCycles()<<endl;

    return 0;
}

