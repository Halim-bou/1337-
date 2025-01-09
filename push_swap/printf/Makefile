CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard src/*.c functions_helper/*.c)
OBJS := $(SRCS:.c=.o)
NAME := libftprintf.a
HEADERS := $(wildcard headers/*.h)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.c $(HEADERS)
			cc $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re


