#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 int p[2];
 pid_t pid;
 char inbuff[20],outbuff[20];
 if(pipe(p)==-1)
 {
  printf("\n PIPE creation failed............\n");
  return 1;
 }
 else
 {
  printf("Inter process communication PIPE is established........\n");
  pid=fork();
  if(pid>0)//parent process........
	{
	 printf("child process is created successfully with child ID:-%d",pid);
	 printf("\n we are in parent process with parent id:-%d",getpid());
	 printf("\nEnter the text to be sent to child:");
	 scanf("%s",outbuff);
	 write(p[1],outbuff,sizeof(outbuff));
	
	}
  else if(pid==0) //child process..........
	{sleep(4);
	 printf("\n we are in child process (child id:-%d) waiting for data from parent....",getpid());
	 read(p[0],inbuff,sizeof(inbuff));
	 printf("\ndata recieved from parent(parent id:-%d) is %s....\n",getppid(),inbuff);
	}
  else  //no child created.........
	{
	printf("\n no child process is created....\n Better Luck next time...");
	return 1;
	}
 }
return 0;
}
