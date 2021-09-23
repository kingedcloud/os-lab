#include<stdio.h>
void print(int frame[],int frlen)
{
	for(int i=0;i<frlen;i++)
	{
		if(frame[i]== -1)
			printf(" \t");
		else
			printf("%d\t",frame[i]);
	}
	printf("\n");
}
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
void lru(int n,int refstr[],int frlen)
{
	int k=0,h,frame[frlen],index,temp,count=0;
	for(int k=0;k<frlen;k++)
	{
		frame[k]=-1;
	}
	//reference string loop
	for(int i=0;i<n;i++)
	{
		//checking if the loop is atleast filled once	
		if(k<frlen)
		{
			h=pagecheck(frame,refstr[i],frlen);
			if(h==0)
			//not full also no match
			{
				frame[k]=refstr[i];
				count++;
				int p=k;
				while(p!=0)
				{
					temp=frame[p];
					frame[p]=frame[p-1];
					frame[p-1]=temp;
					p--;
				}
				print(frame,frlen);
			}
			else if(h==1)
			//not full but match
			{
				
				for(int j=0;j<k;j++)
				{
					
					if(frame[j]==refstr[i])
						index=j;
				}
				while(index!=0)
				{
					temp=frame[index];
					frame[index]=frame[index-1];
					frame[index-1]=temp;
					index--;
				}	
				print(frame,frlen);
			}
			k++;
		}
		else if(k>=frlen)
		//full
		{
			h=pagecheck(frame,refstr[i],frlen);
			
				if(h==0)
			
				
				{
					int q=frlen-1;
					count++;
					/*while(q!=0)
					{
						temp=frame[q];
						frame[q]=frame[q-1];
						frame[q-1]=temp;
						q--;
					}*/
						
					frame[frlen-1]=refstr[i];
					while(q!=0)
					{
						temp=frame[q];
						frame[q]=frame[q-1];
						frame[q-1]=temp;
						q--;
					}
					
					print(frame,frlen);
				}
				else if(h==1)
				{
					
					for(int j=0;j<frlen;j++)
					{
					
						if(frame[j]==refstr[i])
							index=j;
					}
					while(index!=0)
					{
						temp=frame[index];
						frame[index]=frame[index-1];
						frame[index-1]=temp;
						index--;
					}	
					print(frame,frlen);
				}
		}
	}
	printf("\nsystem count:%d\n",count);
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
	lru(n,refstr,frlen);
}


		
		
