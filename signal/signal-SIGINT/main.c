#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

void signal_handler(int num){

	printf("Im signal handler1:%d\n",num);
	exit(EXIT_SUCCESS);
}
void signal_handler1(int num){
	printf("im signal handler2:%d\n",num);
}

int main()
{
	if(signal(SIGINT, signal_handler) == SIG_ERR){
		fprintf(stderr, "cannot handle sigint\n");
		exit(EXIT_FAILURE);
	}
	printf("process id:%d\n",getpid());
	signal(SIGTERM, signal_handler1);
	printf("sao se ngu trong 7s\n");
	sleep(7);
	kill(getpid(), SIGINT);
	while(1){

	printf("chuan bi ngu trong 5s\n");
	sleep(5);
}
	return 0;
}
