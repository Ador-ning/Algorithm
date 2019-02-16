#include<iostream>
#include<cstring>
#include<cerrno>
#include<stdlib.h>

#include<netinet/in.h>
#include <arpa/inet.h>
#include<sys/socket.h>
#include<poll.h>
#include<unistd.h>
#include<sys/types.h>

#define IPADRESS    "127.0.0.1"
#define PORT        8787
#define MAXLINE     1024
#define LISTENQ     5
#define OPEN_MAX    1000
#define INFTIM      -1

static int socket_bind(const std::string &ip, int port) {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1) {
		std::cerr << "bind error: listenfd error -  ";
		exit(1);
	}

	// configure the server address
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof server_addr);
	server_addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr);
	server_addr.sin_port = htons(port);

	// bind socket fd and server address
	if (bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		std::cerr << "bind error: bind error - ";
		exit(1);
	}
	return listenfd;
}

static void handle_connection(struct pollfd *connfds, int num) {
	int i, n;
	char buf[MAXLINE];
	memset(buf, 0, MAXLINE);

	for (i = 1; i <= num; ++i) {
		if (connfds[i].fd < 0)
			continue;

		if (connfds[i].revents & POLLIN) {
			// 接收客户端发送的消息
			n = read(connfds[i].fd, buf, MAXLINE);
			if (n == 0) {
				close(connfds[i].fd);
				connfds[i].fd = -1;
				continue;
			}
			write(STDOUT_FILENO, buf, n);
			// std::cout << "received %d message !" << n << std::endl;
			write(connfds[i].fd, buf, n);
		}
	}
}

static void do_poll(int listenfd) {
	int connfd;

	// client address
	struct sockaddr_in client_addr;
	socklen_t client_addr_len;

	struct pollfd clientfds[OPEN_MAX];
	int maxi, i, nready;

	// 添加监听描述符
	clientfds[0].fd = listenfd;
	clientfds[0].events = POLLIN;

	// 初始化客户连接描述符
	for (i = 1; i < OPEN_MAX; ++i)
		clientfds[i].fd = -1;
	maxi = 0;

	for (;;) {
		// 获取可用描述符个数
		nready = poll(clientfds, maxi + 1, INFTIM); // timeout == -1  无线超时，一直等
		if (nready == -1) {
			std::cerr << "poll error: ";
			exit(1);
		}

		// 监听
		if (clientfds[0].revents & POLLIN) {
			client_addr_len = sizeof(client_addr);
			// 接收新连接
			if (connfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_addr_len) == -1) {
				if (errno == EINTR) //  /* Interrupted system call */
					continue;
				else {
					std::cerr << "accept error: ";
					exit(1);
				}
			}

			std::cout << "accept a new client: " << inet_ntoa(client_addr.sin_addr) <<
			          ":" << client_addr.sin_port << std::endl;

			// 将新接收的连接描述符添加到数组中
			for (int i = 1; i < OPEN_MAX; ++i) {
				if (clientfds[i].fd < 0) {
					clientfds[i].fd = connfd;
					break;
				}
			}

			if (i == MAXLINE) {
				std::cerr << "Too many clients." << std::endl;
				exit(1);
			}

			clientfds[i].events = POLLIN;

			maxi = i > maxi ? i : maxi;
			if (--nready <= 0)
				continue;
		}

		// 处理连接
		handle_connection(clientfds, maxi);
	}
}

/*
 * struct pollfd {
 *      int fd; // 文件描述符
 *      short events; // 等待的事件      POLLIN / POLLOUT / and so on
 *      short revents; // 实际发生事件
 * };
 * */

// socket --> socket_fd
// bind -> bind socket_fd and address
// accept ->

/*
 *

int main(int argc, char *argv[]) {
	int listenfd;

	listenfd = socket_bind(IPADRESS, PORT);

	// 监听
	listen(listenfd, LISTENQ);
	do_poll(listenfd);
	return 0;
}

 * */
