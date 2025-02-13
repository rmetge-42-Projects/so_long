NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -rf

SRC = main.c\
	parsing.c\

OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm

all: ${NAME}

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_PATH) -I$(LIBFT_PATH) -I. -c $< -o $@

valgrind: re all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)


${NAME}: $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) bonus

$(MLX):
	make -C $(MLX_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

norminette:
	@-norminette | grep -E --color=always "Error" || echo "Norminette: Everything is fine!"

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re libft