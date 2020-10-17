NAME_LIBFT = libft.a

NAME_MLX_LIBFT = ./mlx/libmlx.a

NAME = Cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CMLXFLAGS = -L./libft -I/usr/local/include -L/usr/local/lib -L/usr/include -lm -lbsd -lX11 -lXext ./mlx/libmlx_Linux.a 

LIBFT_C = libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_itoa.c\
		libft/ft_memccpy.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_split.c\
		libft/ft_strchr.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_strmapi.c\
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_strtrim.c\
		libft/ft_substr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\
		libft/ft_get_next_line.c\
		libft/ft_get_next_line_utils.c\

PRINTF_C =	libft/ft_printf.c\
			libft/ft_printf_disp.c\
			libft/ft_printf_x.c\
			libft/ft_printf_c.c\
			libft/ft_printf_ana.c\
			libft/ft_printf_know.c\
			libft/ft_printf_s.c\
			libft/ft_printf_percent.c\
			libft/ft_printf_u.c\
			libft/ft_printf_d.c\
			libft/ft_printf_itoa.c\
			libft/ft_printf_p.c\

SRC_C = srcs/ft_error_1.c\
		srcs/ft_check_file_name.c\
		srcs/ft_structs.c\
		srcs/ft_parsing_map_data.c\
		srcs/ft_parsing_map.c\
		srcs/ft_parsing_utils.c\
		srcs/ft_parsing_map_map.c\
		srcs/ft_parsing_map_utils.c\
		srcs/ft_window.c\
		srcs/ft_entry_key.c\
		srcs/ft_position.c\
		srcs/ft_range.c\
		srcs/ft_screen.c\

MAIN_C = srcs/main.c\

OBJS =	ft_printf.o\
			ft_printf_u.o\
			ft_printf_c.o\
			ft_printf_x.o\
			ft_printf_p.o\
			ft_printf_itoa.o\
			ft_printf_d.o\
			ft_printf_disp.o\
			ft_printf_ana.o\
			ft_printf_know.o\
			ft_printf_s.o\
			ft_atoi.o\
			ft_bzero.o\
			ft_calloc.o\
			ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_isdigit.o\
			ft_isprint.o\
			ft_itoa.o\
			ft_memccpy.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_memcpy.o\
			ft_memmove.o\
			ft_memset.o\
			ft_putchar_fd.o\
			ft_putendl_fd.o\
			ft_putnbr_fd.o\
			ft_putstr_fd.o\
			ft_split.o\
			ft_strchr.o\
			ft_strdup.o\
			ft_strjoin.o\
			ft_strlcat.o\
			ft_strlcpy.o\
			ft_strlen.o\
			ft_strmapi.o\
			ft_strncmp.o\
			ft_strnstr.o\
			ft_strrchr.o\
			ft_strtrim.o\
			ft_substr.o\
			ft_tolower.o\
			ft_toupper.o\
			ft_get_next_line.o\
			ft_get_next_line_utils.o\
			ft_printf_percent.o\
			ft_error_1.o\
			ft_check_file_name.o\
			ft_structs.o\
			ft_parsing_map.o\
			ft_parsing_utils.o\
			ft_parsing_map_data.o\
			ft_parsing_map_map.o\
			ft_parsing_map_utils.o\
			ft_window.o\
			ft_entry_key.o\
			ft_position.o\
			ft_range.o\
			ft_screen.o\


all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(PRINTF_C) $(LIBFT_C) $(SRC_C) -c
	@ar -rc $(NAME_LIBFT) $(OBJS)
	@ranlib $(NAME_LIBFT)
	@$(CC) $(CFLAGS) $(MAIN_C) -g3 -fsanitize=leak $(NAME_LIBFT) $(NAME_MLX_LIBFT) -o $(NAME) $(CMLXFLAGS)
#-g3 -fsanitize=leak
# $(CMLXFLAGS)
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_LIBFT)

re : fclean all
	@rm -rf $(OBJS)
