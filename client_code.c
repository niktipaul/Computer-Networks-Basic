// WRITE A  CLIENT SERVER PROGRAM TO COMMUNICATE BETWEEN THEM (ONE WAY)
// CLIENT:

#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
int main()
{
        struct sockaddr_in c_addr;                                 
        int c_fd,c_len;
	char buff[100];                                               
        if((c_fd=socket(AF_INET,SOCK_STREAM,0))==-1)			 
        	printf("error..socket\n");
        c_addr.sin_family=AF_INET;                                    
        c_addr.sin_addr.s_addr=INADDR_ANY;                       
        c_addr.sin_port=3452;                                     
        c_len=sizeof(c_addr);                                    
        if(connect(c_fd,(struct sockaddr*)& c_addr,c_len)==-1)  
        	printf("error connect\n");
	read(c_fd,buff,100);									  
	printf("%s\n",buff);
	close(c_fd);                                             
      return 0;
}

