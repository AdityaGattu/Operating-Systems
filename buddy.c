#include<stdio.h>
int main()
{
	int N;
	printf("Enter the partition size:");
	scanf("%d",&N);
	if(N==0)
	{
		printf("We cant allocate mem for you :(");
		return 0;
	}
	else
	{
		int pagesize;
		
		int last=N,sizereq=0;
		
		while(1)
		{
			printf("Enter the page size to insert ");
			scanf("%d",&pagesize);
			if(pagesize>N)
			{
				printf("We cant allocate mem larger for you because availabe is %d\n",N);
				break;
			}
			int allocated=0,i;
			for(i=N;i>=0;i=i/2)
			{
				if(i==pagesize)
				{
					sizereq=i;
					allocated=1;
				}
				if(i<pagesize)
				{
					sizereq=last;
					allocated=1;
					break;
				}
				if(i==0)
				{
					allocated=0;
					break;
				}
				last=i;
			}
			if(allocated==0)
			{
				printf("Cant able to allocate mem\nExiting");
				break;
			}
			else
			{
				printf("The size required is %d\n",sizereq);
				N=N-sizereq;
			}
		}
	}
}
