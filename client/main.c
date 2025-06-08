#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_library_init();
    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    SSL *ssl = SSL_new(ctx);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(4443)};
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);

    char input[1024];
    while (fgets(input, sizeof(input), stdin)) {
        SSL_write(ssl, input, strlen(input));
    }
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
    return 0;
}