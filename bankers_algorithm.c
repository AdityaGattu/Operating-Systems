#include<stdio.h>
void main()
{
int claim[50][50],alloc[50][50],avail[50],status[50],max[50],all[50]={0};
int i,j,r,p,flag=1,safe=0,count;
printf("Enter no.of processes\n");
scanf("%d",&p);
printf("Enter no.of resources\n");
scanf("%d",&r);
printf("Enter maximum instances of each resource\n");
for(i=0;i<r;i++)
{
printf("Resource %d:",(i+1));
scanf("%d",&max[i]);
}
for(i=0;i<p;i++)
status[i]=1;
count=p;
printf("Enter maximum no.of resources of each resource instance required by
each process\n");
for(i=0;i<p;i++)
{
printf("process %d:",(i+1));
for(j=0;j<r;j++)
scanf("%d",&claim[i][j]);
}
printf("Enter allocated resources of each resource instance required by each
process\n");
for(i=0;i<p;i++)
{
printf("Process %d:",(i+1));
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
}
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
all[j]+=alloc[i][j];
}
for(i=0;i<r;i++)
avail[i]=max[i]-all[i];
printf("Total number of instances of each resource:");
for(i=0;i<r;i++)
printf("%d ",max[i]);
printf("\nMax claim matrix:");
for(i=0;i<p;i++)
{
printf("\n");
for(j=0;j<r;j++)
printf("%d ",claim[i][j]);
}
printf("\nAllocation matrix:");
for(i=0;i<p;i++)
{
printf("\n");
for(j=0;j<r;j++)
printf("%d ",alloc[i][j]);
}
printf("\nAllocated resources:");
for(i=0;i<r;i++)
printf("%d ",all[i]);
printf("\nAvailable resources:");
for(i=0;i<r;i++)
printf("%d ",avail[i]);
while(count!=0)
{
safe=0;
for(i=0;i<p;i++)
{
if(status[i])
{
flag=1;
for(j=0;j<r;j++)
{
if((claim[i][j]-alloc[i][j])>avail[j])
{
flag=0;
break;
}
}
if(flag)
{
safe=1;
status[i]=0;
count--;
printf("\nprocess %d is executing",(i+1));
for(j=0;j<r;j++)
avail[j]+=alloc[i][j];
break;
}
}
}
if(!safe)
{
printf("\nUnsafe state\n");
break;
}
else
{
printf("\nprocess in safe state");
printf("\nAvailable resources:");
for(i=0;i<r;i++)
printf("%d ",avail[i]);
}
printf("\n");
}
}
