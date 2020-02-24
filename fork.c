#include <unistd.h>
#include <stdio.h>
 
int main (void) {
 
        pid_t p;
	printf("origin proc pid=%d\n\n",getpid());
	p=fork();
	if(p==0){
	printf("chield proc pid=%d ppid=%d\n\n", getpid(),getppid());
	}
	else {
	printf("parent pid=%d fork=%d\n\n ",getpid(),p);
	}
 
}
