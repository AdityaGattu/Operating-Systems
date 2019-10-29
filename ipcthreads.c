#include<iostream>
#include<stdio.h>
using namespace std;
struct process
{
int id;
int at;
int bt,ct;int st;
int nt;
int tat,wt;
bool flag;
struct thread
{
int st;}t[10];
}p[10],temp;


int main()
{
int n;
cout<<"enter the no of processes";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"enter the arrivaltime of process "<<(i+1)<<endl;
cin>>p[i].at;
p[i].flag=false;
cout<<"enter the no of threads in process "<<(i+1)<<endl;
cin>>p[i].nt;
p[i].bt=0;
cout<<"enter "<<p[i].nt<<" bursttimes of process "<<(i+1)<<endl;
for(int j=0;j<p[i].nt;j++)
{
cin>>p[i].t[j].st;
p[i].bt+=p[i].t[j].st;
}
}

for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}}}
int time=0,j,k,min;
for(int i=0;i<n;i++)
{k=0;min=1000;j=-1;

while(k<n && p[k].at<=time)
{
if(p[k].nt<min && p[k].flag==false)
{
min=p[k].nt;
j=k;
}
k++;}
if(j==-1)
{
cout<<"process is idle between "<<time<<" and "<<(time+1);
i--;time++;
continue;
}


p[j].flag=true;
p[j].st=time;
p[j].wt=time-p[j].at;
time=time+p[j].bt;
p[j].ct=time;
p[j].tat=p[j].ct-p[j].at;

}
float mean=0;
cout<<"\nprocess\tat\tbt\tnt\tst\twait\tfinish\ttat\n";
for(int i=0;i<n;i++)
{
cout<<(i+1)<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].nt<<"\t"<<p[i].st<<"\t"<<p[i].wt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<endl;
mean+=p[i].tat;
}
mean=mean/n;
cout<<"\nmean of tat  is "<<mean<<endl;

return 0;
}
