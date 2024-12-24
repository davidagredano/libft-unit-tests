SRCS = main.c \
	   utils/ft_log_result.c \
       tests/ft_isalpha.c \
       tests/ft_isdigit.c \
       tests/ft_isalnum.c \
       tests/ft_isascii.c \
       tests/ft_isprint.c \
       tests/ft_strlen.c \
       tests/ft_memset.c \
       tests/ft_bzero.c \
       tests/ft_memcpy.c \
       tests/ft_memmove.c \
       tests/ft_strlcpy.c \
       tests/ft_strlcat.c \
	   tests/ft_toupper.c \
	   tests/ft_tolower.c \
	   tests/ft_strchr.c \
	   tests/ft_strrchr.c \
	   tests/ft_strncmp.c \
	   tests/ft_memchr.c \
	   tests/ft_memcmp.c \
	   tests/ft_strnstr.c \
	   tests/ft_atoi.c \
	   tests/ft_calloc.c \
	   tests/ft_strdup.c \
	   tests/ft_substr.c \
	   tests/ft_strtrim.c \
	   tests/ft_split.c

OBJS =	$(SRCS:.c=.o)

NAME =	libft_tests

CC = 	cc

WOPTS =	-Wall -Wextra -Werror

LOPTS =	-L../libft -lft

.PHONY: all clean fclean re test

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $^ $(LOPTS) -o $@ -lbsd

%.o: %.c libft.h Makefile
	$(CC) -c $(WOPTS) -o $@ $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

t: re
	./$(NAME)
