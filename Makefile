## Executables name
NAME		= cub3D

## Sources
SRC =srcs/move/trigo.c \
		srcs/parsing/ft_check_file_name.c \
		srcs/parsing/ft_parsing_map_data.c \
		srcs/parsing/ft_parsing_map_data_bis.c \
		srcs/parsing/ft_parsing_map_map.c \
		srcs/parsing/ft_parsing_map_map_bis.c \
		srcs/parsing/ft_parsing_map_utils.c \
		srcs/parsing/ft_parsing_map.c \
		srcs/parsing/ft_parsing_map_bis.c \
		srcs/parsing/ft_parsing_utils.c \
		srcs/parsing/ft_structs.c \
		srcs/utils/ft_error_1.c \
		srcs/utils/ft_utils.c \
		srcs/gnl/get_next_line.c \
		srcs/gnl/get_next_line_bis.c \
		srcs/gnl/get_next_line_utils.c \
		srcs/disp/ft_windows.c \
		srcs/disp/ft_init_img.c \
		srcs/disp/ft_draw.c \
		srcs/disp/ft_draw_bis.c \
		srcs/calc/ft_calc_init.c \
		srcs/calc/ft_calc_add.c \

SRC_NON_BONUS=srcs/move/ft_position.c \
		srcs/move/ft_entry_key.c \
		srcs/disp/ft_screen.c \
		srcs/calc/ft_calc_thales.c \

SRC_BONUS =bonus/ft_position.c \
		bonus/ft_screen.c \
		bonus/ft_crossair.c \
		bonus/ft_fps.c \
		bonus/ft_calc_thales.c \
		bonus/ft_entry_key.c \

MAIN_C = srcs/main.c\


## Objects (patsubst = path substitute)
OBJ	= ${patsubst srcs/%, obj/%, $(SRC:.c=.o)}
OBJ_NB	= ${patsubst srcs/%, obj/%, $(SRC_NON_BONUS:.c=.o)}
OBJ_B	= ${patsubst srcs/%, obj/%, $(SRC_BONUS:.c=.o)}

## MLX config
MR_MLX = make -sC $(MLX_DIR)
MLX	= ./mlx/libmlx_Linux.a ./mlx/libmlx.a
MLX_DIR	= ./mlx/
MLX_FLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -Lmlx -lmlx  -lXext -lX11 -lm
## MAC
# MLX_FLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -Lmlx -lmlx -framework OpenGL -framework AppKit

## LIBFT config
MR_LIBFT = make -sC $(LIBFT_DIR)
LIBFT		= libft/libft.a
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

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_NB)
	$(MR_MLX)
	$(MR_LIBFT)
	$(CC)  $(MAIN_C)  $(CFLAGS) $(OBJ) $(OBJ_NB) $(MLX_FLAGS) $(LIBFT) $(MLX) -o $(NAME)
	# @$(CC) $(MAIN_C) $(CFLAGS)  $(MLX_FLAGS) ./libft/libft.a ./mlx/libmlx.a $(OBJ) -o $(NAME)
	$(DONE)

obj/%.o: srcs/%.c
	@mkdir -p obj obj/calc obj/disp obj/move obj/utils obj/parsing obj/gnl obj/bonus
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make clean -sC $(LIBFT_DIR)
	@${RM} obj ${OBJ} $(OBJ_NB) $(OBJ_b)
	@${RM} ./bonus/*.o
	$(CLEAN_O)

fclean:	clean
	@make fclean -sC $(LIBFT_DIR)
	@${RM} ${NAME}
	$(CLEAN_A)

re: fclean all

bonus:$(OBJ) $(OBJ_B)
	$(MR_MLX)
	$(MR_LIBFT)
	$(CC)  $(MAIN_C)  $(CFLAGS) $(OBJ) $(OBJ_B) $(MLX_FLAGS) $(LIBFT) $(MLX) -o $(NAME)
	$(DONE)

.PHONY:	all clean fclean re obj
