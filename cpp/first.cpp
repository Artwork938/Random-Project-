#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#define MYPORT "8080"
#define BACKLOG 1

int main (void) {

     WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }

    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2)
    {
        fprintf(stderr, "Version 2.2 of Winsock not available.\n");
        WSACleanup();
        exit(2);
    }

    struct sockaddr_storage their_addr; //Stores the socket address information
    socklen_t addr_size; //
    struct addrinfo hints, *res;
    int sockfd, new_fd;

    memset(&hints, 0, sizeof hints); // Makes sure the struct is empty
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hints.ai_flags = AI_PASSIVE;   // fill in my ip for me

    getaddrinfo(NULL, MYPORT, &hints, &res);

    sockfd = socket(res->ai_family, 
                    res->ai_socktype,
                    res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);

    listen(sockfd, BACKLOG);

    // now accept an incoming connection:
    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
                                                &addr_size);
                    // ready to communicate on socket descriptor new_fd!

    WSACleanup();
    return 0;    
}

