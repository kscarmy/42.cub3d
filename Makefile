## Executables name
NAME		= cub3D


## LINUX
MLXFLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -Lmlx -lmlx  -lXext -lX11 -lm


## MAC
# MLXFLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -Lmlx -lmlx -framework OpenGL -framework AppKit

## Sources

SRC =srcs/move/ft_entry_key.c \
		srcs/move/ft_position.c \
		srcs/parsing/ft_check_file_name.c \
		srcs/parsing/ft_parsing_map_data.c \
		srcs/parsing/ft_parsing_map_data_bis.c \
		srcs/parsing/ft_parsing_map_map.c \
		srcs/parsing/ft_parsing_map_utils.c \
		srcs/parsing/ft_parsing_map.c \
		srcs/parsing/ft_parsing_utils.c \
		srcs/parsing/ft_structs.c \
		srcs/utils/ft_error_1.c \
		srcs/utils/ft_utils.c \


MAIN_C = srcs/main.c\


## Objects (patsubst = path substitute)
OBJ	= ${patsubst srcs/%, obj/%, $(SRC:.c=.o)}

## LIBFT config
LIBFT		= -L libft/libft.a
LIBFT_DIR	= ./libft/
LIB_FLAGS	= -L $(LIBFT_DIR)
INC		= -I ./inc/ -I $(LIBFT_DIR)

## Compiling config
CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra
## -fsanitize=address -g3
## Output messages
DONE = @echo "libft compiled successfully!"
CLEAN_O = @echo "Object files removed!"
CLEAN_A = @echo "Executables removed!"
DONE = @echo "cub3D ready to use!"

all:	obj $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(MAIN_C) $(CFLAGS)  $(OBJ) $(MLXFLAGS) ./mlx/libmlx_Linux.a ./mlx/libmlx.a   ./libft.a -o $(NAME)
	$(DONE)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

obj:
	@mkdir -p obj
	@mkdir -p obj/calc
	@mkdir -p obj/disp
	@mkdir -p obj/move
	@mkdir -p obj/utils
	@mkdir -p obj/parsing


obj/%.o: srcs/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make clean -sC $(LIBFT_DIR)
	@${RM} obj ${OBJ}
	$(CLEAN_O)

fclean:	clean
	@make fclean -sC $(LIBFT_DIR)
	@${RM} ${NAME}
	$(CLEAN_A)

re: fclean all

.PHONY:	all clean fclean re obj
