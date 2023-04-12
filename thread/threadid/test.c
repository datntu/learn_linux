#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

//khai bao thread
	pthread_t thread_id1,thread_id2;
struct dat{
	char name[30];
	int tuoi;
	};

typedef struct dat dat;

static void *thr_handle(void *argc)
{
	pthread_t tid=pthread_self();
	dat *data =(dat *)argc;
	if(pthread_equal(tid,thread_id1)){
		printf("i'm thread_id1\n");
	}else{
		printf("i'm thread_id2\n");
		printf("hello %s, tuoi %d\n",data->name,data->tuoi);
	}
}

int main(int argc,char *argv[]){
	int  ret;
	dat data={0};
	strncpy(data.name, "dat",sizeof(data.name));
	data.tuoi=22;
	if(ret=pthread_create(&thread_id1,NULL,&thr_handle,NULL)){
		printf("pthread create error %d\n",ret);
		return -1;
	}
	sleep(2);
	if(ret=pthread_create(&thread_id2,NULL,&thr_handle,&data)){
		printf("Pthread create error %d\n",ret);
		return -1;
	}
	sleep(6);
	return 0;
}
