

#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main()
{
        struct sockaddr_in c_addr;                                 
        int c_fd,c_len;
    	char buff[100];
        char buff1[10];   

        if((c_fd=socket(AF_INET,SOCK_STREAM,0))==-1){			 
        	printf("[-]Error in Socket\n");
            exit(0);
        }
        printf("[+]Client Socket created\n");

        c_addr.sin_family=AF_INET;                                    
        c_addr.sin_addr.s_addr=INADDR_ANY;                       
        c_addr.sin_port=3452;                                     
        c_len=sizeof(c_addr); 

        if(connect(c_fd,(struct sockaddr*)& c_addr,c_len)==-1)  {
        	printf("[-]Error in Connect\n");
            exit(0);
        }
        printf("[+]Connected to the Server: \n\n");

        while(1)
        {
            srand(time(0));

            printf("Enter your Frames Mr.Client: ");
            fgets(buff1,sizeof(buff1),stdin);
              
            
            for(int i = 0; i < sizeof(buff1); i++){
                    if(isdigit(buff1[i])){
                        buff[0] = buff1[i];
                        write(c_fd,buff,100);
                        printf("\n[+]Frame %c send successfully!!!\n",buff[0]);
                        printf("\n[.]Waiting for acknowledgement...\n");
                        
                    
                        int randomnumber;
                        randomnumber = rand() % 10 + 1;
                        read(c_fd,buff,100);
                        

                        while(randomnumber > 7){
                            printf("\n[-]Timeout!!!\n");
                            printf("\n[-]Delayed Acknowledgement\n");
                            printf("\n[-]Sending Frame  %c again\n",buff1[i]);
                            bzero(buff,sizeof(buff));
                            buff[0] = buff1[i];
                            write(c_fd,buff,100);
                            printf("\n[+]Frame %c send successfully!!!\n",buff1[i]);
                            printf("\n[.]Waiting for acknowledgement...\n");
                            read(c_fd,buff,100);
                            randomnumber = rand() % 10 + 1;

                        }
                            
                            printf("\n[+]Acknowledgement: %c\n",buff[0]);
                            bzero(buff,sizeof(buff));
                        
                    }
                }
                
        }       
        close(c_fd);                                              
        return 0;
}

