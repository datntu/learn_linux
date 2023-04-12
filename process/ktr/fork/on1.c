#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char * argv[]){

	pid_t child_pid;
	int counter =1;
	printf("gia tri khoi tao cuar counter laf: %d\n",counter);
	child_pid =fork();
	if(child_pid >=0){
		if(child_pid ==0){
			printf("i'm childrent process,counter %d\n",++counter);
			printf("my pid is %d, my parent pid %d\n",getpid(),getppid());
		}else{
			printf("\nIm the parent process, counter: %d\n", ++counter);
            printf("My PID is: %d\n", getpid());
            while (1);
		}
	}else{
		 printf("fork() unsuccessfully\n"); 
}
	return 0;
}
