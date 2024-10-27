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

# SRCS		= ft_find_biggest_square.c \
# 			  ft_is_valid.c \
# 			  ft_file_load.c \
# 			  main.c

# OBJS		= $(addprefix srcs/, ${SRCS:.c=.o})

# SRC_HEADERS	= ft.h
# HEADERS		:= $(addprefix includes/, ${SRC_HEADERS})

# NAME		= bsq

# CFLAGS		= -Wall -Wextra -Werror -Ofast

# all:		${NAME}

# ${NAME}:	${OBJS} ${HEADERS}
# 			gcc ${CFLAGS} ${OBJS} -o $@

# .c.o:		${HEADERS}
# 			gcc ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

# clean:
# 			rm -f ${OBJS}

# fclean:		clean
# 			rm -f ${NAME}

# re:			fclean all

# .PHONY:		all clean fclean re