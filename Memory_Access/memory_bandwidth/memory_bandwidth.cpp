
#include "utils.h"

#define loops 1000
#define	counts 1000

int counter = ( 1 << 10 );
	
using namespace std;

class memory_bandwidth
{
    private:
	
	double read_time;
	double write_time;

    public:

	memory_bandwidth()
	{
		read_time = 0;
		write_time = 0;
	}
	
	double getReadTime()
	{
		return read_time;
	}

	void setReadTime(double num)
	{
		read_time = num;
	}

	double getWriteTime()
	{
		return write_time;
	}

	void setWriteTime(double num)
	{
		write_time = num;
	}

	double writeTime(int *);
	
	double readTime(int *);
};

double memory_bandwidth::writeTime(int *A)
{
	double start = 0;
	double end = 0;
	int i = 0;
	int j = 0;
	int ofset = 3*pow(2,10);

	clock_t c1, c2;
	double total_time = 0;
	while(j < loops)
	{
		j++;
		start = rdtsc();
		for (int k = 0; k < counter; k++){
			A[k] = 0;
		}
		end = rdtsc();
		total_time += end - start;
	}
	
	double cost = 4 * counter * loops;
	return (100* cost * CLOCKS_PER_SEC * loops / total_time);
}

double memory_bandwidth::readTime(int *A)
{
	uint64_t start = 0;
	uint64_t end = 0;
	int a = 0;
	int i = 0, j = 0;
	int ofset = 3*pow(2,10);
	
	clock_t c1, c2;
	double total_time = 0;
	while (j < loops)
	{
		j++;
		i = i + ofset;
		i = i % counter;
		start = rdtsc();
		for (int k = 0; k < counter; k++) {
			a = A[k];
		}
		end = rdtsc();
		total_time += end - start;
	}
	
	total_time/=CLOCKS_PER_SEC;
	total_time/=counter;
	double cost = 4 * counter * loops;
	return (100* cost / total_time);
}

int main(int argc, char const *argv[])
{
	int *A = (int *)malloc(counter * sizeof(int));
	bzero(A, counter * sizeof(int));
	
    	SetMaxPriorityToProcessor();
	
	memory_bandwidth mb;	
	mb.setWriteTime(mb.writeTime(A));
	std::cout<<"Write Bandwidth in Bytes per sec : "<<mb.getWriteTime()/pow(10,9)<<std::endl;
	
	mb.setReadTime(mb.readTime(A));
	std::cout<<"Read time in Bytes per sec : "<<mb.getReadTime()/pow(10,9)<<std::endl;

	free(A);

	return 0;
}
