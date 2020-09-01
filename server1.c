#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 80 
#define PORT 8082 
#define SA struct sockaddr 

//this comment for git change test
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int m; 
    
for (;;) 
{ 

  m = write(connfd,"Enter position to check price from 01 to 05:",strlen("Enter position to check price from 1 to 5:"));    //Ask for choice    
    
     read(connfd, &choice, sizeof(int)); //Read choice
   
 
        bzero(buff, MAX);
	
	// read(file descripter,buffer to read data from,length of buffer))
	read(sockfd, buff, sizeof(buff));
	
	printf("From client: %s\t To client : ", buff);
	 
	bzero(buff, MAX);
	  
	write(sockfd, buff, sizeof(buff)); 
	
} 

} 


int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli;
    
    // Create the Socket 
    // sockid = socket(family,type, protocol)
    // family: IPV4 Internet protocols
    // Sock_Stream: reliable, 2 Way, connection-basic service
    // IPPROTO_TCP, IPPROTO_UDP, usually set to 0 default
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	
    if (sockfd == -1) 
    { 
		printf("socket creation failed...\n"); 
		exit(0); 
    } 
    else
		printf("Socket successfully created..\n"); 

	bzero(&servaddr, sizeof(servaddr));
	
	// Internet Protocol 
	servaddr.sin_family = AF_INET;
	// Address Port 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	// Internet Address 
	servaddr.sin_port = htons(PORT); 
	
	
	// status = bind(sockid,&addrport, size)
	
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) 
    { 
		printf("socket bind failed...\n"); 
		exit(0); 
    } 
    else
		printf("Socket successfully binded..\n");
	
	// status = listen(sockid, queuelimit)
    if ((listen(sockfd, 5)) != 0) 
    { 
		printf("Listen failed...\n"); 
		exit(0); 
    } 
    else            	
    	printf("Server listening..\n"); 

	len = sizeof(cli);
	
	// s = accept(sockid, &clientaddr, $addrlen)
	connfd = accept(sockfd, (SA*)&cli, &len); 
	
    if (connfd< 0) 
    { 
		printf("server acccept failed...\n"); 
		exit(0); 
    } 
    else
		printf("server acccept the client...\n"); 

	func(connfd); 

    close(sockfd); 
    
}
