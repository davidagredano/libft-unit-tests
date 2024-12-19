SRCS = main.c \
       tests/ft_isalpha.c \
       tests/ft_isdigit.c \
       tests/ft_isalnum.c

OBJS =	$(SRCS:.c=.o)

NAME =	libft_tests

CC = 	cc

WOPTS =	-Wall -Wextra -Werror

LOPTS =	-L../libft -lft

.PHONY: all clean fclean re test

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $^ $(LOPTS) -o $@

%.o: %.c
	$(CC) -c $(WOPTS) -o $@ $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)
