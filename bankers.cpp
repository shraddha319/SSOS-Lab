#include<iostream>
 
int n,r; //Number of processes and resource types
int maximum[10][10], allocated[10][10], need[10][10], avail[10];

using namespace std;

bool execute(int process)
{
	int i;
	for(i=0;i<r;i++)
		if(need[process][i]>avail[i])
			break;
	if(i>=r) return true;
	return false;
}

void bankers()
{
	bool finish[n] = {false};
	int count=0;
	cout<<"\nSequnce of execution:\n";
	while(count!=n)
	{
		for(int i=0;i<n;i++)
			if(!finish[i] && execute(i))
			{
				for(int j=0;j<r;j++){
					avail[j] += allocated[i][j];
					need[i][j] = 0;
				}
				count++;
				finish[i]= true;
				cout<<"Process "<<i<<"\n";
			}
	}
}

int main()
{
	printf("Enter number of processes and resource types:");
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<"Process "<<i<<":\n";
		cout<<"Maximum:";
		for(int j=0;j<r;j++)
			cin>>maximum[i][j];
		cout<<"Allocated:";
		for(int j=0;j<r;j++){
			cin>>allocated[i][j];
			need[i][j] = maximum[i][j] - allocated[i][j];
		}
	}
	cout<<"\nAvailable:";
	for(int i=0;i<r;i++)
		cin>>avail[i];
	
	bankers();
	return 0;
}
