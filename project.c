#include<stdio.h>
#include<unistd.h>
int n;
//ta and wt are turnaround and waiting time 
//bt and at are burst time and waiting time ;
//pri is the priority
int *bt,*at,*pri;
char **name;
int * ta,*wt;
int avgta,avgw;
int main()
{
	int i;
	printf("enter no of processes:-");
	scanf("%d",n);
	char buff[10]={0};
	name=(char *)malloc(n*sizeof(char));
	for(i=0;i<n;i++)
	name[i]=malloc(4*sizeof(char));
	for(i=0;i<n;i++)
	{
		itoa(i,buff,10);
		name[i]=strcat("P",buff);
	}
	//this code seems to be at wrong place 
	ta=(int *)malloc(n*sizeof(int));
	wt=(int *)malloc(n*sizeof(int));
	//till here
	bt=(int *)malloc(n*sizeof(int));
	at=(int *)malloc(n*sizeof(int));
	pri=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("enter burst time of process %d :-",i+1);
		scanf("%d",bt[i]);
		printf("enter arrival time of process %d :-",i+1);
		scanf("%d",at[i]);	
	}
	//sorting these on bases of arrival
}