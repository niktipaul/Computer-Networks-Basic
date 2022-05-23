printf("\n[-]Timeout!!!\n");
                        printf("\n[-]NAK %d\n",k);
                        printf("\n[-]Frame  %d sent again\n",k);
                        sprintf(buff1,"%d",k);
                        buff[0] = buff1[0];
                        write(c_fd,buff,100);