NAME = push_swap

LIBFT = libft/libft.a

LIBFT_DIR = libft

SOURCES = srcs/push_swap.c \
			srcs/make_stack.c \
			srcs/error_exit.c \
			srcs/checks.c \
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = @cc

all: $(NAME)

$(NAME): $(LIBFT) ${OBJECTS}
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "Project file completed"

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C ./libft
	@rm -f $(OBJECTS)
	@echo "Cleaned files"
	
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Cleaned files and removed project file"

re: fclean all

.PHONY: all clean fclean re