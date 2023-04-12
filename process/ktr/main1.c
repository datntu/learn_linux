#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	printf("số  lượng truyền vào: %d",argc);
	for(int i=0;i<argc;i++){
		printf("argv[%d]: %s",i+1,argv[i]);
	}
}
