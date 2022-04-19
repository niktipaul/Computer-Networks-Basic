// Client Code

#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#define SIZE 1024

void write_file(int c_fd){

    int n;
    FILE* output_file;
    char *filename = "output_file.txt";
    char buffer[SIZE];

    output_file = fopen(filename,"w");
    if(output_file == NULL){
        printf("[-]Error opening file.\n");
    }

    while(1){
        n = recv(c_fd,buffer,SIZE,0);
        if (n <= 0){
            break;
            return;
        }

        fprintf(output_file, "%s", buffer);
        bzero(buffer, SIZE);
    }

}

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
        c_addr.sin_port=4000;                                     
        c_len=sizeof(c_addr); 


        if(connect(c_fd,(struct sockaddr*)& c_addr,c_len)==-1){
            printf("[-]Error in Connect\n");
            exit(0);
        }  
        	
        printf("[+]Connected to the Server!!! \n\n");

        int g;
        scanf("%d",&g);
        if(g == 5){
            write_file(c_fd);  
            printf("[+]Data written in text file successfully!!!."); 
        }    
        close(c_fd);                                              
        return 0;
}

// Server Code


#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#define SIZE 1024



void send_file(FILE* fp, int s_fd){
    int n;
    char* data[SIZE] = {0};
    while(fgets(data, SIZE, fp) != NULL){
        if(send(s_fd,data,SIZE,0) == -1){
            printf("[-]Error sending file");
            break;
        }
        bzero(data, SIZE);

    }
}



int main()
{
        
	    struct sockaddr_in s_addr,c_addr;                      
	    int s_fd,c_fd,s_len,c_len;
   
        FILE* input_file;

        if((s_fd=socket(AF_INET,SOCK_STREAM,0))==-1)			 
        	printf("[-]Error in Socket\n");
        printf("[+]Client Socket created\n");

        s_addr.sin_family = AF_INET;                                  
	    s_addr.sin_port = 4000;                                       
	    s_len=sizeof(s_addr); 

	    if(bind(s_fd,(struct sockaddr*)& s_addr,s_len)==-1)		   
		    printf("[-]Error in binding\n");
	    printf("[+]Binding successfull\n");

	    if(listen(s_fd,5)==-1)                                     
		    printf("[-]Error in listen\n");
    	printf("[+]Listening... \n"); 

        c_len=sizeof(c_addr);                                 	
    	if((c_fd=accept(s_fd,(struct sockaddr*)&c_addr,&c_len))==-1){
            printf("[-]Error in accept\n");
            exit(0);
    	
        }	
	    printf("[+]New Client Connected!!! \n\n");

        while(1)
        {
            char filename[20];
            printf("Please Enter file name: ");
            fgets(filename,20,stdin);
            input_file = fopen(filename,"r");

            if(input_file == NULL){
                printf("[-]Error opening file.\n");
                break;
            }

            send_file(input_file, s_fd);
            printf("[+]File send successfully");
        }       
        close(s_fd);                                              
        return 0;
}

