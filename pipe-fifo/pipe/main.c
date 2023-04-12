#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MSG_SIZE 30

char *msg1 = "hello 1";
char *msg2 = "hello 2";
char *msg3 = "hello 3";
char *msg4 = "hello 4";

char pipe_buff[MSG_SIZE];
int fds[2],i;

int main(int argc,char *argv[]){
	if(pipe(fds)<0){
	printf("pipe() unsucessfully\n");
	exit(1);
	}
	write(fds[1],msg1, MSG_SIZE);
	write(fds[1],msg2, MSG_SIZE);
	write(fds[1],msg3, MSG_SIZE);
	write(fds[1],msg4, MSG_SIZE);
	printf("ngu trong 4 s\n");
	sleep(4);
	for(int i=0;i<4;i++){
		read(fds[0],pipe_buff, MSG_SIZE);
		printf("msg[%d]: %s\n",i,pipe_buff);
	}
	return 0;
}
