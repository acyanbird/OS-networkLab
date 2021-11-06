/*
	send tcp messages
	This sends a text message entered by a user

        usage:  tcp-send
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFLEN 2048
#define PORTNO 8888

int findlen(char *str){
	int i=0;
	while (str[i]!='\n'){
		i++;
	}
	return i;
}


int main(int argc,char **argv)
{
	struct sockaddr_in myaddr, remaddr;  // structs to define the addresses of client and server
	int clientSocket, len;
	char buf[BUFLEN];	/* message buffer */
	int recvlen;		/* # bytes in acknowledgement message */
	long long sum;
	unsigned short port_num=PORTNO;


	/* create a socket
		socket(AF_INET, SOCK_STREAM, 0) creates a TCP socket
	*/

	if ((clientSocket=socket(AF_INET, SOCK_STREAM, 0))<0){
		printf("Error: socket creation failed\n");
		exit(1);
	}



	

	/* now define remaddr, the address to whom we want to send messages */
	/* For convenience, the host address is expressed as a numeric IP address */
	/* that we will convert to a binary format via inet_aton */

	// memset((char *) &remaddr, 0, sizeof(remaddr));
	remaddr.sin_family = AF_INET;
	remaddr.sin_port = htons(port_num); // this specifies the server port. look up htons
	remaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // this specifies the server address


	// connect client socket to the connection socket created by the server
	if(connect(clientSocket,(struct sockaddr *)&remaddr,sizeof(remaddr))<0){
		printf("Error: Could not connect to server\n");
		exit(1);
	}

	
	


	/* now let's send the messages */

	long long num=atoll(argv[1]);

	if (write(clientSocket,&num,sizeof(num)) < 0) {
		printf("Error: could not send message");
		exit(1);
	}
	printf("Sent number: %lld\n",num);


		/* now receive a mesage from the server */
	recvlen = read(clientSocket, &sum, sizeof(sum));
  if (recvlen >= 0){
          printf("received sum: %lld\n", sum);
  }
	close(clientSocket);
	return 0;
}