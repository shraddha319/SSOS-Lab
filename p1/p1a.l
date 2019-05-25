%{
	#include<stdio.h>
	int id=0,op=0, v=0, flag=0;
%}

%%
[0-9]+	{id++; printf("Identifier: %s\n",yytext);}
[\+\*]	{op++; printf("Operator: %s\n",yytext);}
[(]		{v++;}
[)]		{v--;}
.		{flag=1;}

%%

int yyerror()
{
	return 0;
}

int main()
{
	printf("Enter expression:\n");
	yylex();
	if(flag==0 && (id==op+1) && v==0)
	printf("Valid expression\nIdentifiers= %d\nOperators= %d\n",id,op);
	else
	printf("Invalid expression\n");
	return 0;
}