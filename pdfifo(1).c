#include<stdio.h>
int pagecheck(int frame[],int refelemnt,int frlen)
{
	int flag=0;
	for(int i=0;i<frlen;i++)
	{
		if(frame[i]==refelemnt)
		{
			flag++;
		}
	}
	return flag;
}

void fifo(int refstr[],int frlen,int n)
{
	int h,frame[frlen],count=0,hits=0;
	for(int i=0;i<frlen;i++)
	{
		frame[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		h=pagecheck(frame,refstr[i],frlen);
		if(h==0)
		{
			frame[(i+frlen)%frlen]=refstr[i];
			count++;
			for(int i=0;i<frlen;i++)
			{
				if(frame[i]== -1)
					printf(" \t");
				else
					printf("%d\t",frame[i]);
			}
			printf("\n");
			
		}
		/*else
		{
			hits++;
		}*/
	}
	printf("system faults= %d",count);
	//printf("hits= %d",hits);
}

void main()
{
	int n,frlen;

	printf("enter the number of pages:\n");
	scanf("%d",&n);
	int refstr[n];
	printf("enter the number of frames;\n");
	scanf("%d",&frlen);
	printf("enter the page nos:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&refstr[i]);
	}
	fifo(refstr,frlen,n);
}


	
