#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

bool register_user(const char *username, const char *password);
bool authenticate_user(const char *username, const char *password);

#endif