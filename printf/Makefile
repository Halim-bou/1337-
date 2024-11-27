CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard src/*.c functions_helper/*.c)
OBJS := $(SRCS:.c=.o)
NAME := printf.a
HEADER := $(wildcard headers/*.h)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

# bonus:		$(OBJS) $(BONUS)
# 			ar rcs $(NAME) $(OBJS) $(BONUS)

%.o:		%.c $(HEADER)
			cc $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all bonus

.PHONY:		all bonus clean fclean re


