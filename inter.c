#include<stdio.h>
#include<string.h>

int main()
{
	char res[5],arg1[5],op[5],arg2[5];
	FILE * fp1=fopen("input.txt","r");
	FILE * fp2=fopen("output.txt","w");
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s",res,arg1,op,arg2);
		if(strcmp(op,"+")==0)
		{
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nADD R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"-")==0)
		{
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nSUB R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"*")==0)
		{
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nMUL R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"/")==0)
		{
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nDIV R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"=")==0)
		{
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nMOV %s,R0",res);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}