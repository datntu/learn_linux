#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main( int argc,char *argv[]){
	printf("chạy lệnh ls -lah trong 2 s\n");
	sleep(2);
	execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
	return 0;
	}
