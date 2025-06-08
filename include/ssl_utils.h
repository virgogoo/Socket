#ifndef SSL_UTILS_H
#define SSL_UTILS_H

#include <openssl/ssl.h>

SSL_CTX* init_ssl_context();
void configure_ssl_context(SSL_CTX *ctx);

#endif
