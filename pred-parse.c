#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char prod[3][10] = {"A->aBa","B->bB","B->@"};
char first[3][10], follow[3][10];

char table[3][4][10];
char stack[10], input[10], curp[10];
int top=-1, ptr=0;

int isterminal(char c)
{
	if(c=='a'||c=='b'||c=='@')
		return 1;
	return 0;
}

int num(char c)
{
	switch(c)
	{
		case 'A':return 1;
		case 'B':return 2;
		case 'a':return 1;
		case 'b':return 2;
		case '$':return 3;
	}
}

void pop()
{
	top = top -1;
}

void push(char c)
{
	stack[++top] = c;
}

void display()
{
	for(int i=top;i>=0;i--)
		printf("%c",stack[i]);
}

void ComputeFirst()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;prod[i][j]!='\0';j++)
			if(isterminal(prod[i][j]))
				strncpy(first[i],(prod[i]+j),1);
	}
}

void ComputeFollow()
{
	for(int i=0;i<3;i++)
	{
		if(i==0)
			strcpy(follow[i],"$");
		for(int j=3;prod[i][j]!='\0';j++)
			{
				if(prod[i][j]=='A')
					if(isterminal(prod[i][j+1])) 
						strncpy(follow[0],(prod[i]+j+1),1);
				if(prod[i][j]=='B')
					if(isterminal(prod[i][j+1])) 
						strncpy(follow[1],(prod[i]+j+1),1);
				if(prod[i][j]=='@')
					strcpy(follow[2],follow[1]);
			}	
	}
}

void parse()
{
	int i,j;
	printf("Enter string for parsing terminated by $ :");
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++)
		if(!(input[i]=='a' || input[i]=='b' || input[i]=='$'))
		{
			printf("Invalid string\n");
			exit(0);
		}
	if(input[i-1]!='$')
	{
		printf("String has no end marker\n");
		exit(0);
	}
	push('$');
	push('A');
	printf(" Stack\t\tInput\t\tAction\n");
	printf("--------------------------------------------\n");
	ptr=0;
	while(input[ptr]!='$' && stack[top]!='$')
	{
		display();
		printf("\t\t%s\t",(input+ptr));
		if(stack[top]==input[ptr])
		{
			printf("\tmatched %c\n",input[ptr]);
			pop();
			ptr++;
		}
		else
		{
			if(stack[top]>=65 && stack[top]<=92)
			{
				strcpy(curp,table[num(stack[top])][num(input[ptr])]);
				if(!(strcmp(curp,"-")))
				{
					printf("\nString rejected!\n");
					exit(0);
				}
				else
				{
					printf("\tApply rule: %s\n",curp);
					if(curp[3]=='@')
						pop();
					else
					{
						pop();
						int n = strlen(curp);
						for(int j=n-1;j>=3;j--)
							push(curp[j]);
					}
				}
			}
		}
	}
	display();
	printf("\t\t%s\t",input+ptr);
	if(input[ptr]=='$' && stack[top]=='$')
		printf("\nValid string\n");
	else printf("\nInvalid string\n");
}

void maketable()
{
	int i,j;
	for(i=0;i<3;i++)
		for(int j=0;j<4;j++)
			strcpy(table[i][j],"-");
	strcpy(table[0][0]," ");

	for(i=0;i<2;i++)
	{	
		if(prod[i][0]>='A' && prod[i][0]<='Z')
			strncpy(table[i+1][0],prod[i],1);
	}

	for(i=0;i<3;i++)
		if(first[i]!="@")
			strcpy(table[0][i+1],first[i]);
	strcpy(table[0][i],"$");

	for(i=0;i<3;i++)
	{
		if(first[i][0]!='@')
			strcpy(table[num(prod[i][0])][num(first[i][0])], prod[i]);
		else
			strcpy(table[num(prod[i][0])][num(follow[i][0])], prod[i]);
	}
	printf("\n\n\tPredictive Parsing table\n");
	printf("------------------------------------------\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%-10s",table[i][j]);
		printf("\n------------------------------------------\n");
	}
}

int main()
{
	printf("GRAMMAR:\n");
	for(int i=0;i<3;i++)
		printf("%s\n",prod[i]);
	ComputeFirst();
	ComputeFollow();
	printf("\nFirst\n");
	for(int i=0;i<3;i++)
		printf(" %s",first[i]);
	printf("\nFollow\n");
	for(int i=0;i<3;i++)
		printf(" %s",follow[i]); 
	maketable();
	parse();
	return 0;
}