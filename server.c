// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int client_sock;

void* recv_thread(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = recv(client_sock, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Client: %s", buffer);
    }
    return NULL;
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 1);

    printf("Server listening on port %d...\n", PORT);

    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
    printf("Client connected.\n");

    pthread_create(&tid, NULL, recv_thread, NULL);

    char msg[BUFFER_SIZE];
    while (fgets(msg, sizeof(msg), stdin)) {
        send(client_sock, msg, strlen(msg), 0);
    }

    close(client_sock);
    close(server_sock);
    return 0;
}
