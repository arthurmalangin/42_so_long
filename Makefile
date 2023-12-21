NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror -g

MLX_FILE	=	libmlx.a

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./mlx/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c				\
				utils.c				\
				parsing.c			\
				parsing_read.c		\
				exit.c				\
				exit_many.c			\
				libft.c				\
				display.c			\
				map_check.c			\
				map_check_utils.c	\
				display_string.c	\
				itoa.c				\
				utils_helper.c		\
				ft_calloc.c			\

SRC_DIR		=	./

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

./mlx/libmlx.a:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME): ./mlx/libmlx.a $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ) $(NAME)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re