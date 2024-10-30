SRCS		= ft_atoi.c \
			ft_itoa.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_split.c \
			ft_strmapi.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_isalnum.c \
			ft_memcpy.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_isalpha.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_strrchr.c \
			ft_isascii.c \
			ft_memset.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_isdigit.c \
			ft_putchar_fd.c \
			ft_strlcat.c \
			ft_substr.c \
			ft_isprint.c \
			ft_putnbr_fd.c \
			ft_strlcpy.c \
			ft_tolower.c\
			ft_putendl_fd.c
BONUS_SRCS = ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c
BONUS		= $(BONUS_SRCS:.c=.o)
OBJS		= $(SRCS:.c=.o)

HEADER		= libft.h

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS)
			ar rcs $(NAME) $(OBJS) $(BONUS)

%.o:		%.c $(HEADER)
			gcc $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS) $(BONUS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all bonus

.PHONY:		all bonus clean fclean re
