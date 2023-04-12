#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc ,char *argv[]){
	execl("/bin/mkdir", "mkdir", "/home/ptit/Desktop/taola", NULL);
	return 0;
	}
