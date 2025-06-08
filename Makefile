CC = gcc
CFLAGS = -Wall -pthread -Iinclude
LDFLAGS = -lssl -lcrypto

SRV_SRC = server/main.c server/auth.c server/chat.c server/session.c server/ssl_utils.c server/storage.c
SRV_OBJ = $(SRV_SRC:.c=.o)

CLI_SRC = client/main.c
CLI_OBJ = $(CLI_SRC:.c=.o)

all: server client

server: $(SRV_OBJ)
	$(CC) $(CFLAGS) -o server.out $(SRV_OBJ) $(LDFLAGS)

client: $(CLI_OBJ)
	$(CC) $(CFLAGS) -o client.out $(CLI_OBJ) $(LDFLAGS)

clean:
	rm -f server/*.o client/*.o server.out client.out
