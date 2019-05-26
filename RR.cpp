#include<stdio.h>
#include<stdio.h>

int at[20],bt[20],tat[20],wt[20],n,t=0,ct[20];

void display()
{
	printf("\npid\tat\tbt\tct\ttat\twt\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
}

bool present(int process,int * cirq)
{
	for(int i=0;i<n;i++)
		if(cirq[i]==process)
			return true;
	return false;
}

void rr(int quantum)
{
	int cirq[n], rear=-1,front=-1, count=0, rt[n],nextp=0;
	for(int i=0;i<n;i++)
	{
		cirq[i]=-1;
		rt[i]=bt[i];
		if(at[i]<at[nextp])
			nextp=i;
	}
	t = at[nextp];
	cirq[++rear] = nextp;
	front++;

	while(count!=n)
	{
		nextp = cirq[front];
		front = (front+1)%n;

		if(rt[nextp]<=quantum){
			t += rt[nextp];
			rt[nextp] = 0;
			ct[nextp] = t;
			tat[nextp] = ct[nextp]-at[nextp];
			wt[nextp] = tat[nextp] - bt[nextp];
			count++;
		}

		else{
			t += quantum;
			rt[nextp] -= quantum;
		}

		for(int i=0;i<n;i++)
			if(at[i]<=t && rt[i]>0 && !present(i,cirq)){
				rear = (rear+1)%n;
				cirq[rear] = i;
		}

		if(rt[nextp]>0){
			rear = (rear+1)%n;
			cirq[rear] = nextp;
		}
	}
}

int main()
{
	float avg_tat=0, avg_wt=0;
	int quantum;
	printf("Enter number of processes and quantum time:\n");
	scanf("%d%d",&n,&quantum);
	printf("Enter arrival time and burst time:\n");
	for(int i=0;i<n;i++)
	{
		printf("process %d: ",i);
		scanf("%d%d",&at[i],&bt[i]);
	}
	rr(quantum);
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