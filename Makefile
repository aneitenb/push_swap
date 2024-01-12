NAME = push_swap

LIBFT = libft/libft.a

LIBFT_DIR = libft

SOURCES = srcs/push_swap.c \
			srcs/make_stack.c \
			srcs/ft_atol.c \
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(LIBFT) ${OBJECTS}
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)
	
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re