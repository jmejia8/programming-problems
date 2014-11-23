#include <stdio.h>

int main(int argc, char const *argv[])
{

	int cont1=0,cont2=0;
	char d, op;
	scanf(" %c", &d);
	while(d=='1' || d=='0'){
		scanf(" %c", &d);
		cont1++;
	}
	op=d;
	scanf(" %c", &d);
	while('\n'!=d && EOF !=d){
		d=getchar();
		cont2++;
	}
	cont1--;
	cont2--;
	int i;
	if (op=='+'){
		if (cont1==cont2){
			printf("2");
			for ( i = 0; i < cont1; ++i) printf("0");
			printf("\n");
		}else if (cont1 < cont2){
			printf("1");
			for ( i = 0; i < cont2; ++i) {
				if (i==cont2-cont1-1) printf("1");
				else printf("0");
			}
			printf("\n");
		}else{
			printf("1");
			for ( i = 0; i < cont1; ++i) {
				if (i==cont1-cont2-1) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}else if (op=='-'){
		if (cont1==cont2){
			printf("0\n");
		}else if (cont1 < cont2){
			printf("-9");
			for ( i = 0; i < cont2-1; ++i) {
				if (i<cont2- cont1-1) printf("9");
				else printf("0");
			}
			printf("\n");
		}else{
			printf("9");
			for ( i = 0; i < cont1-1; ++i) {
				if (i<cont1- cont2-1) printf("9");
				else printf("0");
			}
			printf("\n");
		}
	}else if (op=='*'){
		printf("1");
		for ( i = 0; i < cont1+cont2; ++i)	{
			printf("0");
		}
		printf("\n");
	}else if (op=='/'){
		if (cont1==cont2) printf("1\n");
		else if (cont1 < cont2)	{
			printf("0.");
			for ( i = 0; i < cont2-cont1-1; ++i)	{
				printf("0");
			}
			printf("1\n");
		}else {
			printf("1");
			for ( i = 0; i < cont1-cont2; ++i)	{
				printf("0");
			}
			printf("\n");
		}
	}else{
		if (cont1>=cont2 ) printf("0\n");
		else{
			printf("1");
			for ( i = 0; i < cont1; ++i)	{
				printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}		