#include <string.h>
#include "auth.h"
#include "storage.h"
#include <openssl/sha.h>

void hash_password(const char *password, char *hashed) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password, strlen(password), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&hashed[i*2], "%02x", hash[i]);
}

bool register_user(const char *username, const char *password) {
    if (user_exists(username)) return false;
    char hashed[65] = {0};
    hash_password(password, hashed);
    store_user(username, hashed);
    return true;
}

bool authenticate_user(const char *username, const char *password) {
    char hashed[65] = {0};
    hash_password(password, hashed);
    const char *stored = get_stored_password(username);
    return stored && strcmp(stored, hashed) == 0;
}
