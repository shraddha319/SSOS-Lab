%{
	#include<stdio.h>
	#include<stdlib.h>
	int count=0, n;
%}
%token A B
%%
S:X B
X:X A	{ count++; }
|	{;}

%%

int yyerror()
{
	return 0;
}	

void main()
{
	printf("Enter value of n\n");
	scanf("%d",&n);
	printf("enter expression:\n");
	yyparse();
	if(count!=n)
	printf("invalid\n");
	else
	printf("valid expression\n");
}