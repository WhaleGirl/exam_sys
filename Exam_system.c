#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
int V = 0;
int X = 0;
void handle(int s)
{
	printf("time out\n");
	printf("V=%d,X=%d\n",V,X);
	alarm(0);
}
int main(){
	if(signal(SIGALRM,handle)==SIG_ERR)	{
		perror("signal");
	}
	alarm(20);
	int a =0;
	int b= 0;
	int i;
	for( i =0;i<10;i++)	{
		a = rand()%10;
		b = rand()%10;
		int ret = 0;
		printf("%d+%d =",a,b);
		scanf("%d",&ret);
		if(ret==a+b)
			V++;
		else
			X++;
	}
	printf("V=%d,X=%d\n",V,X);
	return 0;
}
