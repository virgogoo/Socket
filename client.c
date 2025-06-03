// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int sock;

void* recv_thread(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = recv(sock, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        printf("Server: %s", buffer);
    }
    return NULL;
}

int main() {
    struct sockaddr_in server_addr;
    pthread_t tid;
    char msg[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to server.\n");

    pthread_create(&tid, NULL, recv_thread, NULL);

    while (fgets(msg, sizeof(msg), stdin)) {
        send(sock, msg, strlen(msg), 0);
    }

    close(sock);
    return 0;
}
