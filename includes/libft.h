/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2022/07/21 15:08:07 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>


# include "../mlx/mlx.h"
// # include "../mlx/mlx_int.h" // LINUX UNIQUEMENT


# include <stdio.h> // A SUPPRIMER

# define BUFFER_SIZE 32 // gnl

# define KEY_MOVE_FRONT 119 // 13 // old 122 ?
# define KEY_MOVE_BACK 115 // 1 // old 100 ?
# define KEY_MOVE_LEFT 97 // 0 // old 113 ?
# define KEY_MOVE_RIGHT 100 // 2 // old 115 ?
# define KEY_ROTATE_LEFT 65361 // 123 // old 65361 ?
# define KEY_ROTATE_RIGHT 65363 // 124 // old 65363 ?
# define KEY_ECHAP 65307 // 53 // old 65307 ?
# define MOVE_SIZE 8
# define FOV_SIZE 60
# define ANG_SIZE 5

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset (void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char	*source, const char *objet, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				ft_gnl_strlen(char *str);
char			*ft_gnl_strnew(int *error);
int				ft_gnl_strchr(char *str);
int				ft_gnl_strcount(char *str);
void			ft_gnl_strjoin
(char **str, const char *buff, int buff_size, int *error);
int				ft_gnl_exerror(char **str, int error);
void			ft_gnl_strdel(char **as);
char			*ft_gnl_strsub
(char const *s, unsigned int start, size_t len, int **error);
void			ft_gnl_read(char **str, char **line, int ret, int *error);
int				ft_get_next_line(int fd, char **line);

typedef struct	s_point
{
	va_list				ap;
	int					ret;
	int					i;
	int					u;
	int					wdh;
	int					pco;
	int					siz;
	char				*str;
	char				*fmt;
	char				c;
	char				typ;
	char				fag;
	char				d[64];
	int					t;
	unsigned long long	ull;
	int					b;
	int					maj;
	int					g;
	unsigned int		ui;
}				t_point;

int				printf(const char *format, ...);
void			ft_init_ptf(t_point	*ptf, char *format);
void			ft_putchar_printf(char c, t_point *ptf);
void			ft_putstr_printf(char *str, t_point *ptf);
void			ft_know_flags(t_point *ptf);
void			ft_know_width(t_point *ptf);
void			ft_know_precision(t_point *ptf);
void			ft_ana_types(t_point *ptf);
int				ft_make_type(char type, t_point *ptf);
int				ft_find_type(t_point *ptf);
void			ft_ana_flags(t_point *ptf);
void			printf_s(t_point *ptf);
void			ft_clear_ptf(t_point *ptf);
int				printf_strlen(char *str);
void			printf_percent(t_point *ptf);
void			printf_c(t_point *ptf);
void			printf_d(t_point *ptf);
void			printf_itoa(t_point *ptf);
void			printf_d_disp(t_point *ptf);
void			printf_itoa_init(t_point *ptf);
void			printf_d_incre(int x, t_point *ptf);
void			printf_d_suite(t_point *ptf);
int				printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			printf_p(t_point *ptf);
void			printf_p_suite(t_point *ptf);
void			printf_p_incre(int x, t_point *ptf);
void			printf_itoa_ull(t_point *ptf);
void			printf_p_disp(t_point *ptf);
void			printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			printf_u(t_point *ptf);
void			printf_u_suite(t_point *ptf);
void			printf_itoa_u(t_point *ptf);
int				printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			printf_u_disp(t_point *ptf);
void			printf_x(t_point *ptf);
void			printf_x_suite(t_point *ptf);
void			printf_itoa_x(t_point *ptf);
void			printf_x_disp(t_point *ptf);
void			printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf);
int				ft_false_type(t_point *ptf);
void			printf_itoa_ll(t_point *ptf);

typedef struct	j_point
{
	int		er; // pas d'erreurs : 0, erreurs : >0
	int 	rx; // résolution : largeur
	int		ry; // résolution : hauteur
	int		x; // tete de lecture utilisé dans : file,
	char	*fl; // contien une copie fichier à lire.
	int 	res; // de base res = 0, si la résolution est définie alors res = 1
	int		fr; // Floor : Red
	int		fg; // Floor : Green
	int		fb; // Floor : Blue
	int		floor; // de base floor = 0, si la couleur du sol est définie alors floor = 1
	int		cr; // Ceiling : Red
	int		cg; // Ceiling : Green
	int		cb; // Ceiling : Blue
	int		ceiling; // de base ceiling = 0, si la couleur du sol est définie alors ceiling = 1
	char	*no; // ./path_to_the_north_texture
	char	*so; // ./path_to_the_south_texture
	char	*we; // ./path_to_the_west_texture
	char	*ea; // ./path_to_the_east_texture
	char	*s; // ./path_to_the_sprite_texture
	char	spawn; // Position de spawn du joueur
	char	**map; // La map mdrr
	int		l; // nombre de lignes de la map
}				m_point;

typedef	struct v_point // structure de calcul : ca
{
	int	i;
}				c_point;

typedef struct k_point
{
	void	*mlx; // Le mlx requis pour utiliser la mlx
	void	*win1; // Première fenetre d'affichage
	int		error; // Pas d'erreurs = 0, erreurs = >0
	m_point	*map; // Lien direct vers la structure map
	int		pos_x; // position dans la case en x du perso
	int		pos_y; // position dans la case en y du perso
	// char	**casa; // position globale sur la map ( la case ) // old
	int		x; // position sur la map du perso
	int		y; // position sur la map du perso
	double	d; // angle où se situe la vue du perso (d pour degré) : entre 0 et 359, où 0 regarde totalement direction nord
	int		move_size; // définis la taille d'un déplacement dans une case /!\ move_size < 100 && > 0 !
	int		d_size; // définis la taille de degrés de rotation de d lorsque la touche est pressée
	int		screen_range; // distance entre la camera et lecran.
	int		max_x; // max de x dans la ligne
	int		max_y; // max de y dans la map
	c_point *ca; // struct de calculs
	int		orient; // orientation de langle de vue
}				w_point;









/*	main.c	*/
int		main(int argc, char **argv);




/*	******	*/
/*	 MOVE	*/
/*	******	*/

/*	ft_entry_key.c	*/
int		ft_entry_keyboard(int key, void *p);

/*	ft_position.c	*/
void	ft_map_disp_pos(w_point *win);
void	ft_move_in_casa(w_point *win);
int		ft_move_zqsd(int key, w_point *win);


/*	*******	*/
/*	 UTILS	*/
/*	*******	*/

/*	ft_error_1.c	*/
int		ft_exor_nfn(int error);
void	ft_map_disp_error(m_point *m, int l, int x, int erreur);
void	ft_show_error_file_bis(m_point *m, int u, int i, int j);
void	ft_show_error_file(m_point *m);
void	ft_error_detected(m_point *m);

/*	ft_utils.c	*/
double	ft_degrees_to_radian(double deg);
double	ft_radian_to_degrees(double rad);
void	ft_red_pixel(w_point *w, int h, int x);
int		ft_str_size(char *str);
int		ft_is_entier(double a); // retourne 1 si le nombre n'est pa entier sinon 0


/*	**********	*/
/*	 PARSING	*/
/*	**********	*/

/*	ft_check_file_name.c	*/
int	ft_check_open(char *argv); // renvoie 0 si fd ok, 1 si erreur.
int	ft_check_file_name_end(int extension, int exist, int u);
int	ft_check_file_name(char *argv, int extension);

/*	ft_parsing_map_data.c	*/
void ft_parsing_resolution(m_point *m);
int	ft_parsing_while(m_point *m, int z);
void    ft_parsing_floor(m_point *m);
void    ft_parsing_ceiling(m_point *m);
char    *ft_parsing_get_path(m_point *m, int z);

/*	ft_parsing_map_data_bis.c	*/
void	ft_parsing_path_to_bis(m_point *m, int y, int z);
void    ft_parsing_path_to(m_point *m);

/*	ft_parsing_map_map.c	*/
void ft_create_mapping_bis(m_point *m, int u);
void    ft_create_mapping(m_point *m);
void	ft_found_map_bis(m_point *m, int u);
void    ft_found_map(m_point *m);
void    ft_fill_map(m_point *m);

/*	ft_parsing_map_map_bis.c	*/
void    ft_fill_line_map(m_point *m, int l); // l est la ligne à malloc :)
void	ft_parse_map_bis(m_point *m, int l, int x);
void    ft_parse_map(m_point *m);
void    ft_check_map(m_point *m); // call toutes les merdes pour la map

/*	ft_parsing_map_utils.c	*/
void    ft_set_world_spawn(m_point *m, int u);
int     ft_is_not_map(char c, int one);
int     ft_next_zero_char(char c);
void     ft_next_zero_map(m_point *m, int l, int x);

/*	ft_parsing_map.c	*/
void    ft_check_fl_half(m_point *m);
void	ft_strfreejoin_newline_bis(m_point *m, char *buff, int i, int u);
void	ft_strfreejoin_newline(m_point *m, char *buff);
void    ft_parsing_open_fd(m_point *m, char *argv);
int	ft_parsing_map_bis(m_point *m);
int		ft_parsing_map(m_point *m, char *argv);

/*	ft_parsing_utils.c	*/
int		ft_incre_spaces(m_point *m, int backn, int h); // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
int		ft_is_space(char c, int backn, int end, m_point *m);
int		ft_is_color(int color); // Si color faux return 1, sinon 0

/*	ft_structs.c	*/
void	ft_init_map(m_point *m);
void	ft_disp_verif(m_point *m);
void	ft_exit_free_map_paths(m_point *m);
int		ft_exit_free_map(m_point *m, int ret);







#endif
