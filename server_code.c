// WRITE A  CLIENT SERVER PROGRAM TO COMMUNICATE BETWEEN THEM (ONE WAY)
// SERVER:

#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
int main()
{
	struct sockaddr_in s_addr,c_addr;                           //TAKING STRUCTURE TYPE VARIABLE
	int s_fd,c_fd,s_len,c_len;
	if((s_fd=socket(AF_INET,SOCK_STREAM,0))==-1)				//USING SOCKET() SYSTEM CALL
		printf("error..socket\n");
	s_addr.sin_family=AF_INET;                                  //INITIALISING VALUE OF THE STRUCTURE
	s_addr.sin_addr.s_addr=INADDR_ANY;                          //INITIALISING VALUE OF THE STRUCTURE
	s_addr.sin_port=3452;                                       //INITIALISING VALUE OF THE STRUCTURE
	s_len=sizeof(s_addr);                                       //STORING THE SIZE OF THE VARIABLE
	if(bind(s_fd,(struct sockaddr*)& s_addr,s_len)==-1)		   //USING BIND() SYSTEM CALL
		printf("error bind\n");
	if(listen(s_fd,5)==-1)                                     //CHECKING CONDITION USING LISTEN() SYSTEM CALL
		printf("error listen\n");
	while(1)
	{
		c_len=sizeof(c_addr);                                 //STORING THE SIZE OF THE VARIABLE 
		char buff[100];
		if((c_fd=accept(s_fd,(struct sockaddr*)&c_addr,&c_len))==-1)	//USING ACCEPT() SYSTEM CALL
			printf("erroe accept\n");
		printf("connected\n");
		write(c_fd,"from server..........",100);          //WRITING THE CONTENT FROM c_fd TO 100 USING WRITE() SYSTEM CALL
		close(c_fd);                                      //USING CLOSE() SYSTEM CALL
	}
	return 0;
}
