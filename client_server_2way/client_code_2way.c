

#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
int main()
{
        struct sockaddr_in c_addr;                                 
        int c_fd,c_len;
	char buff[100];   

        if((c_fd=socket(AF_INET,SOCK_STREAM,0))==-1)			 
        	printf("[-]Error in Socket\n");
        printf("[+]Client Socket created\n");

        c_addr.sin_family=AF_INET;                                    
        c_addr.sin_addr.s_addr=INADDR_ANY;                       
        c_addr.sin_port=3452;                                     
        c_len=sizeof(c_addr); 

        if(connect(c_fd,(struct sockaddr*)& c_addr,c_len)==-1)  
        	printf("[-]Error in Connect\n");
        printf("[+]Connected to the Server: \n\n");

        while(1)
        {
            read(c_fd,buff,100);									  
            printf("From Server: %s\n",buff);
            printf("Enter your Message Mr.Client: ");
            fgets(buff,sizeof(buff),stdin);
              
            if (strcmp(buff, "Exit\n") == 0){
                printf("[-]Disconneted from Server");
                write(c_fd,"Disconnected\n",100);
                break;
            }
            else{
                write(c_fd,buff,100);
            }
        }       
        close(c_fd);                                              
        return 0;
}

