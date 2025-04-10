CC := cc
CFLAGS := -Wall -Wextra -Werror -g
MLX_DIR = /usr/include/minilibx-linux
MLX_LIB = -lmlx -L$(MLX_DIR) -lXext -lX11
NAME := fractol
HEADERS := $(wildcard headers/*.h)
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

