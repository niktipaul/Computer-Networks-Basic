

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
        char buff1[2]; 

        if((c_fd=socket(AF_INET,SOCK_STREAM,0))==-1){			 
        	printf("[-]Error in Socket\n");
            exit(0);
        }
        printf("[+]Client Socket created\n");

        c_addr.sin_family=AF_INET;                                    
        c_addr.sin_addr.s_addr=INADDR_ANY;                       
        c_addr.sin_port=3452;                                     
        c_len=sizeof(c_addr); 

        if(connect(c_fd,(struct sockaddr*)& c_addr,c_len)==-1) { 
        	printf("[-]Error in Connect\n");
            exit(0);
        }
        printf("[+]Connected to the Server: \n\n");

        while(1)
        {
            srand(time(0));
            int framesize;
            int windowsize;
            printf("Enter Frames Size Mr.Client: ");
            scanf("%d",&framesize);
            printf("Enter Window Size Mr.Client: ");
            scanf("%d",&windowsize);
              
            int i = 1;
            while(i <= framesize){
                
                int z = 0;
                for(int k = i; k < i+windowsize && k <= framesize; k++){
                    sprintf(buff1,"%d",k);
                    buff[0] = buff1[0];
                    write(c_fd,buff,100);
                    printf("\n[+]Frame %c send successfully!!!\n",buff[0]);
                }

                for(int k = i; k < i+windowsize && k <= framesize; k++){
                    int randomnumber;
                    randomnumber = rand() % 10 + 1;

                    if(randomnumber <= 8){
                        // read(c_fd,buff,100);
                        printf("\n[+]Acknowledgement: %d\n",k);
                        // bzero(buff,sizeof(buff));
                        z++;
                    }
                    else
                    {
                        printf("\n[-]Timeout!!!\n");
                        printf("\n[-]Delayed Acknowledgement\n");
                        printf("\n[-]Frame  %d not recieved\n",k);
                        printf("\n[+]Retrensmitting Window\n");
                        break;
                    }
                }

                printf("\n");
                i = i + z;
            }
                
        }       
        close(c_fd);                                              
        return 0;
}

