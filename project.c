#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int n;
//ta and wt are turnaround and waiting time 
//bt and at are burst time and waiting time ;
//pri is the priority
int bt[10],at[10],pri[10];
int processno[10];
int ta[10],wt[10];
int avgta,avgw;
int isin(int a)
{
	int  i;
	for(i=0;i<n;i++)
	{
		if(at[i]==a)
		{
			return i;
		}
	}
}
int min()
{
	int a=at[0];
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]<a)
		{
			j=i;
		}
	}
	return j;
}
int main()
{
	int i;
	printf("enter no of processes:-");
	scanf("%d",&n);
	int rt[n];
	for(i=0;i<n;i++)
	{
		processno[i]=i;
	}
	for(i=0;i<n;i++)
	{
		printf("enter burst time of process %d :-",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
		printf("enter arrival time of process %d :-",i+1);
		scanf("%d",&at[i]);	
		printf("enter priority of process %d :-",i+1);
		scanf("%d",&pri[i]);	
	}
	int timeline=0;
	int remaining = n;
	//what if two processes arrive at same time 
	//what should be the loop
}

