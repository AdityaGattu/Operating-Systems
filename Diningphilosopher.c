#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5

#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N

#define THINKING 84
#define HUNGRY 72
#define EATING 69

sem_t stLock,pLock[N];
int state[N];

void *philosopher(void *) ;
void put_forks(int );
void take_forks(int );
void test(int );

void *philosopher(void* p)
{
int i,j;
i =* (int *) p;

while(1)
{
take_forks(i);

 

printf("\n\nP-%d is EATING now...\n",i);
for(j=0;j<5;j++)
printf(" %c",state[j]);

for(j=0;j<1000000000;j++);
//sem_post(&pLock[i]);

put_forks(i);
//sem_post(&pLock[i]);
printf("\nAfter Philosopher %d Putting down the fork",i);
for(j=0;j<5;j++)

printf(" %c",state[j]);
}

}


void take_forks(int i)
{
sem_wait(&stLock);
state[i]=HUNGRY;
test(i);
sem_post(&stLock);
sem_wait(&pLock[i]);
}


void put_forks(int i)
{
sem_wait(&stLock);
state[i]=THINKING;
test(LEFT);
test(RIGHT);
sem_post(&stLock);
}


void test(int i)
{
//sem_wait(&pLock[i]);
if(state[i]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
{
state[i]=EATING;
sem_post(&pLock[i]);
}
}


void main()
{
int i,a[5]={0,1,2,3,4},j;
pthread_t p[5];

sem_init(&stLock,0,1);//unlock initially

for(j=0;j<N;j++)
sem_init(&pLock[j],0,0);//lock initially

for(i=0;+i<5;i++)
pthread_create(&p[i],NULL,philosopher,&a[i]);


for(i=0;i<5;i++)
pthread_join(p[i],NULL);

}0
