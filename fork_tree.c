#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main ()
 {
	int i;
	pid_t ppid;
	pid_t pid1, pid2, pid3, pid4;
    
	printf("my tree\n	(A)\n      /	   \\\n   (a)       (b)\n /     \\       \\\n(a1)    (b1)    (b2)\n");
    printf("Parent of all 'A': %d\n",getpid());

	pid1 = fork();
    
	if(pid1 == 0)
	{
		printf("Child 'b' id: %d and its Parent id: %d \n", getpid(),getppid());
		pid2=fork();
		
		if(pid2==0)
		{
			printf("Child 'b2' id: %d and its Parent id: %d \n", getpid(),getppid());
			sleep(3);
			exit(0);
		}
		if(pid2>0)
		{
			exit(0);  ///убиваем сразу при старте соседа b2
		}


		wait(NULL);
		exit(0);

	}
	if(pid1 > 0)
	{
		printf("Child 'a' id: %d and its Parent id: %d \n", getpid(),getppid());
		pid3 = fork();
		
		if(pid3==0)
		{
			printf("Child 'b1' id: %d and its Parent id: %d \n", getpid(),getppid());
			sleep(3);
			exit(0);
		}
		if(pid3>0)
		{
			printf("Child 'a1' id: %d and its Parent id: %d \n", getpid(),getppid());
			sleep(3);
			
			exit(0);

		}
		wait(NULL);
		exit(0);
	}
	wait(NULL);
    exit(0);

}


