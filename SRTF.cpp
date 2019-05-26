#include<stdio.h>

int at[20],bt[20],tat[20],wt[20],n,t=0,ct[20];

void display()
{
	printf("pid\tat\tbt\tct\ttat\twt\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
}

int LeastRT(int * rt,int current)
{
	int process=-1,minrt=999;
	for(int i=0;i<n;i++)
	{
		if(at[i]<=t && rt[i]>0)
			if(rt[i]<minrt){
				process = i;
				minrt = rt[i];
			}
	}
	if(rt[process]==rt[current])
		return current;
	return process;
}

void srtf()
{
	int count=0, nextp=0,t;
	int rt[n];
	for(int i=0;i<n;i++){
		ct[i]=0;
		rt[i]=bt[i];
		if(at[i]<at[nextp])
			nextp = i;
	}
	t = at[nextp];
	//printf("%d\n",nextp);
	while(count!=n)
	{
		rt[nextp] -= 1;
		t += 1;
		printf("%d %d %d\n",nextp,t,rt[nextp]);
		if(rt[nextp]==0){
			ct[nextp] = t;
			tat[nextp] = ct[nextp]-at[nextp];
			wt[nextp] = tat[nextp]-bt[nextp];
			count += 1;
		}
		nextp = LeastBT(rt,nextp);
	}
}

int main()
{
	float avg_tat=0, avg_wt=0;
	printf("Enter number of processes:\n");
	scanf("%d",&n);
	printf("Enter arrival time and burst time:\n");
	for(int i=0;i<n;i++)
	{
		printf("process %d: ",i);
		scanf("%d%d",&at[i],&bt[i]);
	}
	srtf();
	display();
	for(int i=0;i<n;i++)
	{
		avg_tat += tat[i];
		avg_wt += wt[i];
	}
	avg_tat /= n;
	avg_wt /= n;
	printf("Avg TAT = %f\nAvg WT = %f\n",avg_tat,avg_wt);
	return 0;
}