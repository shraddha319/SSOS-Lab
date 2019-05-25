%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token num
%left '+' '-'
%left '*' '/'

%%

input:exp	{ $$=$1; printf("result = %d\n",$$); exit(0);}
exp:exp'+'exp	{$$ = $1+$3;}
|exp'-'exp	{ $$ = $1-$3;}
|exp'*'exp	{$$ = $1*$3; }
|exp'/'exp	{if($3!=0) $$=$1/$3; else { printf("division by zero error\n"); exit(0);}}
|'('exp')'	{ $$ = $2;}
|num	{ $$ = $1; }

%%

int yyerror()
{
	return 0;
}

void main()
{
	printf("enter an expr:\n");
	yyparse();
}
