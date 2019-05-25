#include<stdio.h>
#include<string.h>

char stk[20],a[20];
int top=-1,i=0;

void check()
{
	if(stk[top-1]=='i' && stk[top]=='d')
	{
		top -= 1;
		stk[top] = 'F';
		stk[top+1] = '\0';
		printf("$%s\t%s$\tREDUCE TO F\n",stk,a);
		check();
	}

	if(stk[top-2]=='E' && stk[top-1]=='+' && stk[top]=='T')
	{
		if(a[i+1]=='*')
			return;
		else
		{
			top -= 2;
			stk[top] = 'E';
			stk[top+1] = '\0';
			stk[top+2] = '\0';
			printf("$%s\t%s$\tREDUCE TO E\n",stk,a);
			check();

		}
	}

	else if(stk[top]=='T' && a[i+1]!='*')
	{
		stk[top] = 'E';
		printf("$%s\t%s$\tREDUCE TO E\n",stk,a);
		check();

	}

	if(stk[top-2]=='T' && stk[top-1]=='*' && stk[top]=='F')
	{
		top = top-2;
		stk[top] = 'T';
		stk[top+1] = '\0';
		stk[top+2] = '\0';
		printf("$%s\t%s$\tREDUCE TO T\n",stk,a);
		check();
	}

	if(stk[top]=='F')
	{
		stk[top]='T';
		printf("$%s\t%s$\tREDUCE TO T\n",stk,a);
		check();
	}

	if(stk[top-2]=='(' && stk[top-1]=='E' && stk[top]==')')
	{
		top -= 2;
		stk[top] = 'E';
		stk[top+1] = '\0';
		stk[top+2] = '\0';
		printf("$%s\t%s$\tREDUCE TO F\n",stk,a);
		check();
	}

}

int main()
{
	printf("Enter the string\n");
	scanf("%s",a);
	printf("\nstack \t input \t action\n");
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='i' && a[i+1]=='d')
		{
			stk[++top] = a[i];
			stk[++top] = a[i+1];
			stk[top+1] = '\0';
			a[i] = ' ';
			a[i+1] = ' ';
			i++;
			printf("$%s\t%s$\tSHIFT->id\n",stk,a);
			check();
		}
		else
		{
			stk[++top] = a[i];
			stk[top+1] = '\0';
			char c = a[i];
			a[i] = ' ';
			printf("$%s\t%s$\tSHIFT->%c\n",stk,a,c);
			check();
		}
	}
	return 0;
}


