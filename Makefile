NAME = fractol

SRC_PATH = srcs
SRC = main.c 
SRCS = $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH = obj
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH = includes
INC = fractol.h
INCS = $(addprefix $(INC_PATH)/, $(INC))

LIB_PATH = libft
LIB = libft.a
LIBS = $(addprefix $(LIB_PATH)/, $(LIB))

MLX_PATH = minilibx-mac-osx
MLX = libmlx.a
MLXS = $(addprefix $(MLX_PATH)/, $(MLX))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBS) $(MLXS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLXS) 

$(LIBS):
	make -C $(LIB_PATH)

$(MLXS):
	make -C $(MLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

clean:
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re