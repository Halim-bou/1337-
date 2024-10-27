CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCLUDE = libft.h
SRCS = ./ft_*.c
OBJS = $(SRCS:.c:.o)
LIB1 = ar -rcs
LIB2 = ranlib

all:	$(NAME)
$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME)	$(OBJS)
			$(LIB2) $(NAME)
.c.o:
		$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)
clean:
		$(CC) $(OBJS)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all
.PHONY: all clean fclean re