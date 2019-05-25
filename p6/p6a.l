%{

#include<stdio.h>
int ml=0,sl=0;
	
%}

%%
"/*"[a-zA-Z0-9' '\t\n]+"*/"	{ml++;}
"//".*	{sl++;}

%%

int yyerror()
{
	return 0;
}

void main(int argc,char **argv)
{
	if(argc<3)
	printf("enter ./a.out input_file output_file\n");
	else
	{
		yyin = fopen(argv[1],"r");
		yyout = fopen(argv[2],"w");
		yylex();
		printf("Number of sl comments=%d, ml=%d\n",sl,ml);
	}
}