#include "utils.h"

#define COUNT 1000000

using namespace std;

class ProcedureCall
{
  public:
	
	void Function1(int a)
	{}


	void Function2(int a, int b)
	{}

	void Function3(int a, int b, int c)
	{}

	void Function4(int a, int b, int c, int d)
	{}

	void Function5(int a, int b, int c, int d, int e)
	{}

	void Function6(int a, int b, int c, int d, int e, int f)
	{}

	void Function7(int a, int b, int c, int d, int e, int f, int g)
	{}

	void Function8(int a, int b, int c, int d, int e, int f, int g, int h)
	{}

	void Function9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
	{}

	void Function10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
	{}

};

int main()
{

   SetMaxPriorityToProcessor();
   
   uint64_t start_cycles, end_cycles;
   uint64_t total_cycles;
   
   int i;
   int data1,data2 = 0;
 
   uint64_t sum = 0;
    
   ProcedureCall pCall;
   
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function1(1);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procdure overhead with one Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function2(1,2);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procdure overhead with two Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function3(1,2,3);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procedure overhead with three Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function4(1,2,3,4);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procdeure overhead with four Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function5(1,2,3,4,5);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procedure overhead with five Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function6(1,2,3,4,5,6);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procedure overhead with six Arg as cpu cycles"<<" "<<total_cycles<<endl;;


   sum = 0;
   for (i = 0; i < COUNT; i++) {
     start_cycles = rdtsc();
     pCall.Function7(1,2,3,4,5,6,7);
     end_cycles = rdtsc();
     sum = sum + (end_cycles - start_cycles);
   }

   total_cycles = ((double)sum) / ((double)(COUNT));
   
   cout<<"Procedure overhead with seven Arg as cpu cycles"<<" "<<total_cycles<<endl;;

   return 1;
}
