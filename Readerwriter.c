#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#define MAX 5
  
int id,SharedData;
sem_t mutex,wLock;
int readcount = 0;

int writeNext()
{static int data=100;
 return data++;
}

void* reader(void *arg)
{int id = (int)arg;
 printf("reader id is %d\n",id);
 while(1)
 {sleep(1);
  sem_wait(&mutex);
	readcount++;
	if(readcount==1){sem_wait(&wLock);}
  sem_post(&mutex);
  printf("\nReader %d Read Value:%d...",id,SharedData);
  sem_wait(&mutex);
	readcount--;
	if(readcount==0){sem_post(&wLock);}
  sem_post(&mutex);
    }
 return 0;
}

void* writer()
{while(1)
 {sem_wait(&wLock);
	printf("\n Writer is now writing...Number of readers: %d \n",readcount);
	SharedData = writeNext();
  sem_post (&wLock);
	sleep(1);
 }
 return 0;
}

int main()
{pthread_t readerthread[MAX],writerthread;
 int i,k;
 sem_init(&mutex,0,1);
 sem_init(&wLock,0,1);
 for(i=0; i<MAX; i++)
 {k = i+1;printf("%d thread created\n",k);
  pthread_create(&readerthread[i],0,reader,(void*)k);
 }pthread_create(&writerthread,0,writer,0);
 pthread_join(writerthread,0);
 for(i=0; i<MAX; i++)
 {pthread_join(readerthread[i],0);}
 sem_destroy (&mutex);
 sem_destroy (&wLock);
 return 0;
}




