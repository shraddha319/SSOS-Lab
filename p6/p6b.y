%{
	#include<stdlib.h>
	#include<stdio.h>
	int digit=0,key=0,id=0,op=0;
	extern FILE * yyin;
%}
%token DIGIT KEY OP ID
%%
input:DIGIT input	{digit++;}
|KEY input	{ key++; }
|OP input	{ op++ ;}
|ID input	{ id++; }
|DIGIT 	{digit++;}
|KEY 	{key++;}
|OP 	{op++;}
|ID 	{id++;}

%%
int yyerror()
{
	return 0;
}

void main(int argc, char **argv)
{
	if(argc!=2)
	printf("error\n");
	else
	{
		yyin = fopen(argv[1],"r");
		yyparse();
		printf("number of id= %d,keywords= %d, digits= %d, operators= %d\n",id,key,digit,op);
	}
}