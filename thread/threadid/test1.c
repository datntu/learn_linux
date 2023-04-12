#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

pthread_t thread_id1,thread_id2;

struct dat{
	char name[30];
	int  tuoi;
	};
typedef struct dat dat;

static void *dat_handle(void *argd){
	pthread_t tid =pthread_self();
	dat *data = (dat *)argd;

	if(pthread_equal(tid,thread_id1)){
		printf("i'm thread_id1\n");
	}else{

		printf("i'm thead_id2\n");
		printf("hello %s ,tuoi cua toi la: %d\n",data->name,data->tuoi);
	}
}

int main(int argc,char *argv[]){
	int luu;
	dat data={0};
	strncpy(data.name,"dat",sizeof(data.name));
	data.tuoi=22;
	if(luu=pthread_create(&thread_id1,NULL,&dat_handle,NULL)){
		printf("pthread create error %d\n",luu);
		return -1;
		}
	sleep(5);
	if(luu=pthread_create(&thread_id2,NULL,&dat_handle,&data)){
		printf("pthread create error %d\n",luu);
		return -1;
	}
	sleep(4);
	return 0;

}
