%{
	#include<stdio.h>
	#include "y.tab.h"
%}
%%
[0-9]+	{ printf("digit: %s\n",yytext); return DIGIT;}
[\+\-\*\/\=\<\>]	{ printf("operator: %s\n",yytext); return OP; }
int|void|float|char|return|main|include|printf	{ printf("keyword: %s\n",yytext); return KEY; }
[a-zA-Z][a-zA-Z0-9]*	{ printf("identifier: %s\n",yytext); return ID; }
.	{;}
%%