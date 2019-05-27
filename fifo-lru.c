#include<stdio.h>

int pages[10],psize=0,fsize=0;

void display(int *frames)
{
	for(int i=0;i<fsize;i++)
		printf("%d ",frames[i]);
	printf("\n");
}

int shift(int index, int top, int *frames)
{
	for(int i=index+1;i<=top;i++)
		frames[i-1] = frames[i];
}

int found(int page,int *frames)
{
	for(int i=0;i<fsize;i++)
		if(page==frames[i])
			return i;
	return -1;
}

int fifo()
{
	int frames[fsize], pf=0, rear=-1, front=0;
	for(int i=0;i<fsize;i++)
		frames[i]=-1;
	for(int i=0;i<psize;i++)
	{
		int index = found(pages[i],frames);
		if(index==-1)
		{
			if(rear<(fsize-1))
				frames[++rear] = pages[i];
			else
			{
				frames[front] = pages[i];
				front =(front+1)%fsize;
			}
			pf++;
		}
		display(frames);
	}
	return pf;
}

int lru()
{
	int frames[fsize], pf=0, top=-1;
	for(int i=0;i<fsize;i++)
		frames[i]=-1;
	for(int i=0;i<psize;i++)
	{
		int index = found(pages[i],frames);
		if(index==-1)
		{
			if(top<fsize-1)
				frames[++top] = pages[i];
			else
			{
				shift(0,top,frames);
				frames[top] = pages[i];
			}
			pf++;
		}
		else
		{
			shift(index,top,frames);
			frames[top] = pages[i];
		}
		display(frames);
	}
	return pf;
}


int main()
{
	int pf_fifo,pf_lru;
	printf("enter num of pages and num of frames");
	scanf("%d%d",&psize,&fsize);
	printf("enter pages:\n");
	for(int i=0;i<psize;i++)
		scanf("%d",&pages[i]);
	printf("\nFIFO:\n");
	pf_fifo = fifo();
	printf("\nLRU:\n");
	pf_lru = lru();
	printf("Page faults: FIFO = %d, LRU = %d\n",pf_fifo,pf_lru);
	return 0;
}