CC := cc
CFLAGE := -g -Wall -Wextra -Werror
HEADERS := $(wildcard includes/*.h)
SRCS := $(wildcard *.c && */*.c)
OBJS := $(SRCS:.c=.o)
NAME := push_swap

all:		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I includes -o $(NAME)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -I includes -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

