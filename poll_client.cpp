#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <poll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

#define MAXLINE     1024
#define IPADDRESS   "127.0.0.1"
#define SERV_PORT   8787

#define max(a, b) ((a > b) ? a : b)

static void handle_connection(int sockfd){
    char sendline[MAXLINE], recvline[MAXLINE];
    int maxfdp, stdineof;
    struct pollfd pfds[2]; // 发 + 接
    int n;

    // 添加连接描述符
    pfds[0].fd = sockfd;
    pfds[0].events = POLLIN;
    pfds[1].fd = STDIN_FILENO;
    pfds[1].events = POLLIN;

    for(;;){
        poll(pfds, 2, - 1);

        if(pfds[0].revents & POLLIN){
            n = read(sockfd, recvline, MAXLINE);
            if( n == 0){
                std::cerr << "client: server is closed.\n";
                close(sockfd);
            }

            write(STDIN_FILENO, recvline, n);
        }

        if(pfds[1].revents & POLLIN){
            n = read(STDIN_FILENO, recvline, MAXLINE);
            if(n == 0){
                shutdown(sockfd, SHUT_WR);
                continue;
            }
            write(sockfd, sendline, n);
        }
    }
}

/*
 *
int main(int argc, char *argv[]){
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, IPADDRESS, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    handle_connection(sockfd);
    return 0;
}

 * */
