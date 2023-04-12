#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MGS_SIZE 16

char *msg1 ="hello 1";
char *msg2 ="hello 2";

static void func(int signum){
    wait(NULL);
    printf("child process termination\n");

}
int main(){
    char in_buff[MGS_SIZE];
    int num_read=0;
    int fds[2];
    pid_t child_pid;

    if(pipe(fds)<0){
        printf("pipe() unsuccessfully\n");
        exit(1);
    }
    child_pid =fork();
    if(child_pid>=0){
        if(child_pid ==0){
            printf("i'm child\n");
            if (close(fds[1]) == -1){ // write end is unused
                printf("close(fds[1]) failed\n");
            }
            while(1){
                num_read=read(fds[0],in_buff,MGS_SIZE);
                if(num_read==-1){
                    printf("read() faild\n");
                    exit(0);
                }else{
                    if(num_read==0){
                        printf("pipe and-of-pipe\n");
                        break;
                    }else{
                        printf("msg: %s\n",in_buff);
                    }
                }
            }
        }else{
            signal(SIGCHLD,func);
            printf("i'm parent\n");
            if(close(fds[0]==-1)){
                printf("close fds[0] faild\n");
            }
            write(fds[1],msg1,MGS_SIZE);
            write(fds[1],msg2,MGS_SIZE);
            if(close(fds[1])==-1){
                printf("close fds[1]\n");
            }
            while(1);
        }
    }else{
        printf("fork() unsuccessfully\n");
    }
        return 0;
}