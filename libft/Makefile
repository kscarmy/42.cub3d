NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_C = ./ft_atoi.c\
		./ft_bzero.c\
		./ft_calloc.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isascii.c\
		./ft_isdigit.c\
		./ft_isprint.c\
		./ft_itoa.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_putchar_fd.c\
		./ft_putendl_fd.c\
		./ft_putnbr_fd.c\
		./ft_putstr_fd.c\
		./ft_split.c\
		./ft_strchr.c\
		./ft_strdup.c\
		./ft_strjoin.c\
		./ft_strlcat.c\
		./ft_strlcpy.c\
		./ft_strlen.c\
		./ft_strmapi.c\
		./ft_strncmp.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strtrim.c\
		./ft_substr.c\
		./ft_tolower.c\
		./ft_toupper.c\
		./ft_get_next_line.c\
		./ft_get_next_line_utils.c\

SRC_C =	./ft_printf.c\
			./ft_printf_disp.c\
			./ft_printf_x.c\
			./ft_printf_c.c\
			./ft_printf_ana.c\
			./ft_printf_know.c\
			./ft_printf_s.c\
			./ft_printf_percent.c\
			./ft_printf_u.c\
			./ft_printf_d.c\
			./ft_printf_itoa.c\
			./ft_printf_p.c\

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



all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT_C)-c
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
