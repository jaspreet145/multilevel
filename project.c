#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
int n;
//ta and wt are turnaround and waiting time 
//bt and at are burst time and waiting time ;
//pri is the priority
int bt[10],at[10],pri[10];
int processno[10];
int ta[10],wt[10],flag[10]={0},exec[10];
int avgta,avgw,wait,turn;
int a[10];
int display()
{
  	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("P[%d]\t|\t%d\t|\t%d\n",processno[i],ta[i],wt[i]); 
	}
	printf("\nAverage Waiting Time= %f\n",wait*1.0/n); 
  printf("Avg Turnaround Time = %f",turn*1.0/n); 
}
void
 prisort(int n)		//this function is correct
{
	int i=0,j=0,k=n-1,max;
	while(j<n)
	{
		max=-1;
		for(i=0;i<n;i++)
		{
			if(max<pri[i] && flag[i]==0)
			{
				max=pri[i];
				a[k]=i;
			}
		}
		for(i=0;i<n;i++)
		{
			if(max==pri[i])
			{
				flag[i]=1;
			}
		}
		j++;
		k--;
	}
}
int isin(int c,int b)			//this is correct
{
	int  i;
	i=-1;
	int j;
	if(b!=-1)
	{
	for(j=0;j<n;j++)
	{
		if(at[j]==at[b])
		{
			continue;
		}
		else
		{if(at[j]==c)
		{
			return j;
		}
		}
		
	}
}
	else
	{
		for(j=0;j<n;j++)
	{
		if(at[j]==a)
		{
			return j;
		
		}
	}
}
	return i;
}

int min(int time,int n)    //this function is correct
{
	int i,j=-1;
	for(i=0;i<n;i++)
	{
		if(at[i]==time && flag[i] ==0)
		{
			j=i;
			break;
		}
	}
	if(j!=-1)
	{
		flag[j]=1;
	}
	return j;

}
int main()
{
	int i=0,j,temp,temp1=0;
	printf("enter no of processes:-");
	scanf("%d",&n);
	int rt[n];
	int queue2[n];
	int q2size=0;
	for(i=0;i<n;i++)
	{
		processno[i]=i;
	}
	for(i=0;i<n;i++)
	{
		printf("enter burst time of process %d :-",i);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
		printf("enter arrival time of process %d :-",i);
		scanf("%d",&at[i]);	
		printf("enter priority of process %d :-",i);
		scanf("%d",&pri[i]);	
	}
	int timeline=0;
	int remaining = n;
	int checker[10];
	int k=0;
	prisort(n);
	int index;
	for(i=0;i<n;i++)
		flag[i]=0;
	i=0;
	while(remaining!=0)
	{
		printf("%d\n",remaining);
		while((k = min(timeline,n))!=-1)
		{
			checker[i]=k;
			i++;
		
		}
		if(i==0)
		{
			timeline++;
			continue;
		}
		int index= INT_MAX;
		for(j=0;j<i;j++)			//this is correct
		{
			if(exec[j]!=1)
				{
			for(k=0;k<n;k++)
			{
				if(checker[j]==a[k])
			{
				
					
						if(k<index)			
						{
							index=k;		//change her3e
							break;
						}
					}
				}
				
			
			}else
					continue;
		}

		temp1=a[index];	
		index=temp1;
		temp=rt[index];		//think on this
			
//change here
	for(j=0;j<=temp && (isin(timeline,index))==-1&& rt[index]>0;j++)   //change in this line
		{
			rt[index]--;
			timeline++;
		}
		if(rt[index]==0)	//this is correct
		{
			wt[index]=wait+timeline-at[index]-bt[index];   
			wait=wait+wt[index];
			ta[index]=timeline-at[index];
			turn=turn+ta[index];
			exec[index]=1;
			remaining--;
		}	
	}
	display();
}


