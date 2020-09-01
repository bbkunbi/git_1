#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#define MAX 80 
#define PORT 8081
#define SA struct sockaddr 

void func(int sockfd) 
{ 
    char buff[MAX];
    int n; 

for (;;) 
{
       printf("send numer from 1 to 5  from server terminal:");
       bzero(buff, sizeof(buff)); 

       printf("server - Choice is : %d\n" , choice);	
     
     
      switch(choice)
     {
     	case 1:
     		ans = 500000;
     		break;
     	case 2:
     		ans = 300000;
     		break;
     	case 3:
     		ans = 200000;
     		break;
     	case 4:
     		ans = 100000;
     		break;
     	case 5 :
 		ans = 5000;
     		break;
     }

    write(sockfd, &ans , sizeof(int));

	printf("Enter the string : "); 
    
   
    
        write(sockfd, buff, sizeof(buff)); 
	
	bzero(buff, sizeof(buff)); 
	
	read(sockfd, buff, sizeof(buff)); 
	
	printf("From Server : %s", buff); 
        
 
} 

}


int main() 
{ 
    
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;   

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sockfd == -1) { 
	
	printf("socket creation failed...\n"); 
	exit(0);
	 
    } 
    else
    printf("Socket successfully created..\n"); 
	
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

    // Connect(sockid,&address,addrlen)
    
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
	
		printf("connection with the server failed...\n"); 
		exit(0); 
    } 
    else
	printf("connected to the server..\n"); 
	
	func(sockfd); 
  	close(sockfd); 
  	}
