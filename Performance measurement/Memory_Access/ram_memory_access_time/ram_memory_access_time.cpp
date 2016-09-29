#include "utils.h"
#include <cstdio>
#include <time.h>

#define MEMSIZE	(1<<24)

int main () {
	register int 	i, count, n;
	register char	*p;
	int		c1, c2, k;
	double		t;

	p = new char[MEMSIZE];
	n = MEMSIZE * 10;
	for (k=1; k<100; k++) {
		count = 0;
		i = 0;
		c1 = clock ();
		while (count < n) {
			p[i] = 0;
			i+=k;
			if (i >= MEMSIZE) i = 0;
			count++;
		}
		c2 = clock ();
		t = c2 - c1;
		t /= CLOCKS_PER_SEC;
		t /= n;
	}
	
	cout<<"RAM Memory access overhead is "<< ( t * 1000000000) <<" nano sec"<<endl;
	fflush (stdout);
	fflush (stderr);
	exit (0);
}
