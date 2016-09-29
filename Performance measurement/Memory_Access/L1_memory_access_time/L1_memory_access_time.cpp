#include "utils.h"
#include <cstdio>

#define L1_MEMSIZE 40000

int main()
{
    	SetMaxPriorityToProcessor();

	register int 	i, count, n;
	register char	*p1,*p2;
	int		c1, c2, k;
	double		t;

	p1 = new char[L1_MEMSIZE];
	
	n = L1_MEMSIZE;
	for (k=1; k<L1_MEMSIZE; k++) {
		count = 0;
		i = 0;
		c1 = clock ();
		while(count < n)
		{
			p1[i] = 0;
			count++;
		}
		c2 = clock ();
		t += c2 - c1;
	}
	t /= CLOCKS_PER_SEC;
	t /= n;
	t /= (L1_MEMSIZE/2);
	cout<<"L1 Memory access overhead is "<< ( t * 1000000000) <<" nano sec"<<endl;
	fflush (stdout);
	fflush (stderr);
	
	delete p1;
	exit (0);
}
