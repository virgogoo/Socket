#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <pthread.h>
// #include <netinet/in.h>
// #include <openssl/ssl.h>
// #include "ssl_utils.h"
// #include "chat.h"

#define PORT 4443

void *client_handler(void *arg);

int main() {
    // SSL_CTX *ctx = init_ssl_context();
    // configure_ssl_context(ctx);

    // int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // struct sockaddr_in addr = {AF_INET, htons(PORT), INADDR_ANY};
    // bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    // listen(server_fd, 10);

    // printf("Server listening on port %d...\n", PORT);

    // while (1) {
    //     struct sockaddr_in client_addr;
    //     socklen_t len = sizeof(client_addr);
    //     int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);
    //     SSL *ssl = SSL_new(ctx);
    //     SSL_set_fd(ssl, client_fd);
    //     SSL_accept(ssl);

    //     pthread_t tid;
    //     SSL *arg = ssl;
    //     pthread_create(&tid, NULL, client_handler, (void*)arg);
    // }
    // SSL_CTX_free(ctx);
    // close(server_fd);
    return 0;
}

// void *client_handler(void *arg) {
//     SSL *ssl = (SSL*)arg;
//     char buffer[1024];
//     while (1) {
//         int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
//         if (bytes <= 0) break;
//         buffer[bytes] = '\0';
//         handle_message(ssl, buffer);
//     }
//     SSL_free(ssl);
//     return NULL;
// }