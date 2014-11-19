#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,l, lo,d,d0=0,r,g,i,s=0;
	scanf("%d", &n);
	scanf("%d", &lo);
	//s=l;
	for ( i = 0; i < n; ++i){
		scanf("%d", &d);
		scanf("%d", &r);
		scanf("%d", &g);
		s+=d-d0;
		l=r+g;
		if (s%l<=r)	s+=r-s%l;
		d0=d;
		//printf("%d - - %d === %d\n",i, s, d%l);
	}
	s+=lo-d0;
	printf("%d\n", s);
	return 0;
}



