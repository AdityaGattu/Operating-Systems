#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 int p1[2],p2[2];
 pid_t pid;
 char inbuff[20],outbuff[20];
pipe(p1);
pipe(p2);
printf("Inter process 2-way communication PIPE is established........\n");
  pid=fork();
  if(pid>0)//parent process..............
	{
	 printf("\tchild process is created successfully with child ID:-%d",pid);
	 printf("\n This is parent process(parent id:-%d)...",getpid());
	 printf("\n Enter the text to be sent to child:");
	 scanf("%s",outbuff);
	 write(p1[1],outbuff,sizeof(outbuff));
	 
	 read(p2[0],inbuff,sizeof(inbuff));
	 printf("The message from child process(child id:-%d)is...%s\nreceived in parent(parent id:-%d)\n",pid,inbuff,getpid());
	 }
  else if(pid==0) //child process...........
	{
	 printf("\nThis is child process (child id:-%d)...",getpid());
         read(p1[0],inbuff,sizeof(inbuff));
	 printf("\ndata recieved from parent(parent id:-%d): %s....\n",getppid(),inbuff);
	 printf("Enter the text to be sent to parent:");
	 scanf("%s",outbuff);
	 write(p2[1],outbuff,sizeof(outbuff));	
	}
  else  //no child created.........
	{
	printf("\n no child process is created....\n Better Luck next time...");
	return 1;
	}
 
return 0;
}
