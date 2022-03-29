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
	struct sockaddr_in s_addr,c_addr;    
                          
	int s_fd,c_fd,s_len,c_len;



	if((s_fd=socket(AF_INET,SOCK_STREAM,0))==-1)				
		printf("Error..Socket\n");

	s_addr.sin_family = AF_INET;                                  
	s_addr.sin_port = 3452;                                       
	s_len=sizeof(s_addr); 

	if(bind(s_fd,(struct sockaddr*)& s_addr,s_len)==-1)		   
		printf("Error bind\n");

	if(listen(s_fd,5)==-1)                                     
		printf("Error listen\n");


    c_len=sizeof(c_addr);                                 	
	if((c_fd=accept(s_fd,(struct sockaddr*)&c_addr,&c_len))==-1)	
		printf("Error accept\n");
	printf("New Client Connected: \n");

    char buff[100];
	while(1)
	{
        printf("Enter Your Message Mr.Server: ");
        fgets(buff,sizeof(buff),stdin);
		write(c_fd,buff,100);    
        read(c_fd,buff,100);									  
        printf("From Client: %s\n",buff);           

	}
    close(c_fd);
	return 0;
}
