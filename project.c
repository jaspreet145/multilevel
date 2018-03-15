#include<stdio.h>
#include<unistd.h>
int n;
int main()
{
	
	printf("enter no of processes:-");
	scanf("%d",n);
	pid_t proq1 =(pid_t*)malloc(n*sizeof(pid_t));
	pid_t proq2 =(pid_t*)malloc(n*sizeof(pid_t));
	int * ta,*wt,*bt,*at;
	ta=(int *)malloc(n*sizeof(int));
	wt=(int *)malloc(n*sizeof(int));
	bt=(int *)malloc(n*sizeof(int));
	at=(int *)malloc(n*sizeof(int));
	int avgta,avgw;
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter burst time of process %d :-",i+1);
		scanf("%d",(bt+i));
		printf("enter arrival time of process %d :-",i+1);
		scanf("%d",(at+i);	
	}
	for (i=0;i<n;i++)
	{
		*(proq1+i)=fork();
		switch(proq1)
		{
			case 0: kill(*(proq1+i),SIGSTOP);
					sleep()
		}
	}
}
int childprocess()
