#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
int count =2;


struct dat{
	char name[30];
	int tuoi;
	};
typedef struct dat dat;

static void *handle_th1(void *args)
{
	dat *data= (dat *)args;
	pthread_mutex_lock(&lock1);
	printf("hello %s\n",data->name);
	printf("thread1 handler, counter: %d\n",++count);
	sleep(5);
	pthread_mutex_unlock(&lock1);
	pthread_exit(NULL);
}

static void *handle_th2(void *args)
{
	pthread_mutex_lock(&lock1);
	printf("thread2 handler,counter: %d\n",++count);
	pthread_mutex_unlock(&lock1);
	pthread_exit(NULL);
}

int main(int argc,char *argv[]){

	int ret;
	dat data;
	pthread_t thread_id1,thread_id2;
	memset(&data, 0x0, sizeof(dat));
	strncpy(data.name, "dat", sizeof(data.name));
	if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &data)) {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &handle_th2, NULL)) {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    
    // used to block for the end of a thread and release
    pthread_join(thread_id1,NULL);  
    pthread_join(thread_id2,NULL);

    return 0;
}

