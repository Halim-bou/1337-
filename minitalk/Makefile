CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c ft_putnbr.c
CLIENT_SRC = client.c ft_atoi.c
SERVER_SRC_BONUS = server_bonus.c ft_putnbr.c
CLIENT_SRC_BONUS = client_bonus.c ft_atoi.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)
			$(CC) $(SERVER_OBJ_BONUS) -o $(SERVER_NAME)
			$(CC) $(CLIENT_OBJ_BONUS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
			$(CC) $(SERVER_OBJ) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
			$(CC) $(CLIENT_OBJ) -o $(CLIENT_NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)
fclean: clean
			rm -rf $(SERVER_NAME) $(CLIENT_NAME)
re: fclean all

.SECONDARY : $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)

.PHONY: clean fclean re all bonus
