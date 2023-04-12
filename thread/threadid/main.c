#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

pthread_t thread_id1, thread_id2;

typedef struct {
	char name[20];
	char msg[20];
} thr_data_t;

static  void *thr_handle(void *args)
{
	pthread_t tid =pthread_self();
	thr_data_t *data =(thr_data_t *)args;
	
	if(pthread_equal(tid,thread_id1)){
		printf("i'm thread_id1\n");
	}else{
		printf("i'm thread_id2\n");
		printf("hello %s ,welcome to join %s\n",data->name,data->msg);
	}
}

int main(int argc,char *argv[]){

	int ret;
	thr_data_t data={0};
	strncpy(data.name, "dat",sizeof(data.name));
	strncpy(data.msg,"thread program\n",sizeof(data.msg));
	if(ret =pthread_create(&thread_id1,NULL,&thr_handle,NULL)){
		printf("pthread create error %d\n",ret);
		return -1;
	}
	sleep(3);
	if(ret=pthread_create(&thread_id2,NULL,&thr_handle,&data)){
		printf("pthread create error %d\n",ret);
		return -1;
	}
	sleep(6);
	return 0;
}
