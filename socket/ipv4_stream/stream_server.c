#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h> //thu vien chua cac hàng số ,cấu trúc khi sử dụng địa chỉ trên internet
#include<arpa/inet.h>
#include<unistd.h>

#define LISTEN_BACKLOG 10
#define BUFF_SIZE 256

void chat_func(int new_socket_fd){
	int numb_read,numb_write;
	char sendbuff[BUFF_SIZE];
	char recvbuff[BUFF_SIZE];
	while(1){
		memset(sendbuff,'0',BUFF_SIZE);
		memset(recvbuff,'0',BUFF_SIZE);
	/* Đọc dữ liệu từ socket */
        /* Hàm read sẽ block cho đến khi đọc được dữ liệu */
	numb_read=read(new_socket_fd,recvbuff,BUFF_SIZE);
	if(numb_read ==-1){
		exit(EXIT_FAILURE);
	}
	if(strncmp("exit", recvbuff, 4)==0){
		system("clear");
		break;
	}
	printf("\nMessage from Client: %s\n", recvbuff);
	//nhap phan hoi tu ban phim
	printf("please,respond the message : ");
	fgets(sendbuff, BUFF_SIZE, stdin);
	//ghi du lieu thong qua ham write
	numb_write =write(new_socket_fd, sendbuff, sizeof(sendbuff));
	if(numb_write==-1){
		exit(EXIT_FAILURE);
		}
	if (strncmp("exit", sendbuff, 4) == 0) {
            system("clear");
            break;
        }
	sleep(2);
}
	close(new_socket_fd);
}
int main(int argc,char *argv[]){
	int port_no,len,opt;
	int server_fd, new_socket_fd;
	struct sockaddr_in serv_addr, client_addr;
	if(argc<2){
		printf("no port \n");
		exit(EXIT_FAILURE);
	}else{
		port_no= atoi(argv[1]);
	memset(&serv_addr, 0,sizeof(struct sockaddr_in));
	memset(&client_addr, 0,sizeof(struct sockaddr_in));
	}
//tao socket
	server_fd=socket(AF_INET, SOCK_STREAM,0);
	if(server_fd ==-1){
		exit(EXIT_FAILURE);
	}
	//ngan loi: adress arlready in use
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
		exit(EXIT_FAILURE);
	}

	//khoi tao dia chi cho servo

	serv_addr.sin_family =AF_INET;
	serv_addr.sin_port =htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	//gan socket voi dia chi servo
	if(bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1){
		exit(EXIT_FAILURE);
	}
	//nghe toi da 10 ket noi
	if(listen(server_fd, LISTEN_BACKLOG)==-1){
		exit(EXIT_FAILURE);
	}
	len=sizeof(client_addr);
	while(1){
	printf("Server is listening at port : %d \n....\n",port_no);
		new_socket_fd  = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t *)&len); 
		if (new_socket_fd == -1){
			exit(EXIT_FAILURE);
			system("clear");
}		
		//char temp[BUFF_SIZE];
		//inet_ntop(client_addr.sin_family, (struct sockaddr*)&client_addr, temp, sizeof(temp));
		printf("Server : got connection \n");
		        chat_func(new_socket_fd);
}
close(server_fd);
return 0;

}

