/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int clientSocket,lenstr;
	char buffer[1024];
	char name[50],tempname[50];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	printf("enter your name:");
	scanf("%s",name);
	strcat(name,":");
	strcpy(tempname,name);
		
		
	while(1)
	{
		clientSocket = socket(PF_INET, SOCK_STREAM, 0);
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(8080);
		serverAddr.sin_addr.s_addr = inet_addr("127.45.0.2");
		memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
		addr_size = sizeof serverAddr;
		strcpy(name,tempname);
		char message[100],messagein[100];;
		fgets(message, 100, stdin);
		lenstr=strlen(message);
		message[lenstr-1]='\0';
		if(strlen(message) > 0)
		{
			strcat(name,message);
			connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size); 	               
			send(clientSocket, name, 100, 0);
		}
		close(clientSocket);
	}
	return 0;
}
