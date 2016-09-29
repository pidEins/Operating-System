#include "utils.h"

class page_fault
{
   private:
	
	double avgTime;
	
   public:
		
	double getAverageTime()
	{
		return avgTime;
	}

	void setAverageTime(double num)
	{
		avgTime = num;
	}

	double pagefaultOverhead();
};

double page_fault::pagefaultOverhead()
{
    unsigned int offset = 176777216; //16 MB
    unsigned long int FILESIZE = 16435973836; // 8 GB
    
    int fd = open("dump", O_RDWR);
    if (fd < 0) {
        cout<<"File Open failed. Hint: \"dump\" file might be missing. Please create by running \"touch dump\" command."<<endl;
        exit (-1);
    }
    
    ftruncate(fd, FILESIZE);
    
    char* memory_map =(char*) mmap(NULL, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    char c;
    uint64_t start;
    uint64_t end;
    uint64_t total_time = 0;

    int itr;
    for (itr = 0; itr < 100; itr++)
    {   
    	start = rdtsc();
        c = memory_map[(((itr+1) * offset) % (FILESIZE - 1))]; 
    	end = rdtsc();
    	total_time += end - start;
    }

    double averageTime = (double)(total_time - 123)/(100 - 4);
 
    /*un-map the memory the end of the program */
    munmap(memory_map, FILESIZE);
    close(fd);

    return averageTime;
}

int main() {
    
   SetMaxPriorityToProcessor();

   page_fault pg;

   pg.setAverageTime(pg.pagefaultOverhead());
   cout<<"Page Fault overhead in sec : "<<pg.getAverageTime()/CLOCKS_PER_SEC<<endl;
   cout<<"Page Fault overhead as cpu cycles : "<<pg.getAverageTime()<<endl;

   return 0;
}
