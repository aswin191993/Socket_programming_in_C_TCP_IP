/****************** SERVER CODE ****************/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.45.0.2");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    if(listen(welcomeSocket,5)==0)
    {
        printf("Listening\n");
    }
    while(1)
    {
        newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
        if(newSocket > 0)
        {
            char message[100];
            recv(newSocket,message, 100, 0);
            printf("Received packet from %s:%d\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));
            send(newSocket,message,strlen(message),0);
            printf("%s\n",message);
        }
        close(newSocket);
    }
    return 0;
}
