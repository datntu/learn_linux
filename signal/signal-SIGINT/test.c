#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_handler1(int num){
	printf("i'm sig_hander1: %d\n",num);
	exit(EXIT_SUCCESS);
}
void sig_handler2(int num){
	printf("i'm sig_handler2: %d\n",num);
}
int main(){
	if(signal(SIGINT, sig_handler2)==SIG_ERR){
		fprintf(stderr,"cannot handler signalint\n");
		exit(EXIT_FAILURE);
	}
	printf("process ID:%d\n",getpid());
	sleep(4);
	while(1){
		printf("who are you\n");
		sleep(3);
	}
}
