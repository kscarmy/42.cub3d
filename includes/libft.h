/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
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
# include "../mlx/mlx_int.h"


# include <stdio.h> // A SUPPRIMER

# define BUFFER_SIZE 32

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

int				ft_printf(const char *format, ...);
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
void			ft_printf_s(t_point *ptf);
void			ft_clear_ptf(t_point *ptf);
int				ft_printf_strlen(char *str);
void			ft_printf_percent(t_point *ptf);
void			ft_printf_c(t_point *ptf);
void			ft_printf_d(t_point *ptf);
void			ft_printf_itoa(t_point *ptf);
void			ft_printf_d_disp(t_point *ptf);
void			ft_printf_itoa_init(t_point *ptf);
void			ft_printf_d_incre(int x, t_point *ptf);
void			ft_printf_d_suite(t_point *ptf);
int				ft_printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_p(t_point *ptf);
void			ft_printf_p_suite(t_point *ptf);
void			ft_printf_p_incre(int x, t_point *ptf);
void			ft_printf_itoa_ull(t_point *ptf);
void			ft_printf_p_disp(t_point *ptf);
void			ft_printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u(t_point *ptf);
void			ft_printf_u_suite(t_point *ptf);
void			ft_printf_itoa_u(t_point *ptf);
int				ft_printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u_disp(t_point *ptf);
void			ft_printf_x(t_point *ptf);
void			ft_printf_x_suite(t_point *ptf);
void			ft_printf_itoa_x(t_point *ptf);
void			ft_printf_x_disp(t_point *ptf);
void			ft_printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf);
int				ft_false_type(t_point *ptf);
void			ft_printf_itoa_ll(t_point *ptf);

typedef struct	j_point
{
	int		error; // pas d'erreurs : 0, erreurs : >0
	int 	rx; // résolution : largeur
	int		ry; // résolution : hauteur
	int		x; // tete de lecture utilisé dans : file, 
	char	*file; // contien une copie fichier à lire.
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

int				ft_exor_nfn(int error); // exit error no free need, int error où error correspond au numéro du message à afficher en sortie.
int				ft_check_file_name(char *argv, int extension); // check l'extension si extension = 1 puis si le fichier spécifié existe en l'ouvrant.
int 			ft_check_open(char *argv); // Ouvre le fichier passé en argument.
void			ft_init_map(m_point *map); // Initialise la structe "map".
void			ft_disp_verif(m_point *map);  // Permet un affichage des valeurs contenues dans la structure.
int				ft_exit_free_map(m_point *map, int ret); // Fonction qui est censé free absolument tout, avec ou sans erreurs.
int				ft_parsing_map(m_point *map, char *argv); // comme son nom l'indique ...
void			ft_parsing_open_fd(m_point *map, char *argv); // stockage du fichier dans map.
void			ft_strfreejoin_newline(m_point *map, char *buff); // rajoute toutes les lignes lues par gnl dans map->file.
void			ft_parsing_path_to(m_point *map); // cherche le nom des données.
char			*ft_parsing_get_path(m_point *map, int z); // remplis la struct du nom trouvé et de ses infos.
void			ft_parsing_ceiling(m_point *map); // replis la struct des données concernant le plafond.
void			ft_parsing_floor(m_point *map); // replis la struct des données concernant le sol.
void			ft_parsing_resolution(m_point *map); // replis la struct des données concernant la résolution.
int				ft_incre_spaces(m_point *map, int backn, int h);  // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
int				ft_is_space(char c, int backn, int end, m_point *map); // classe tout caractère pouvant être classé comme espace.
int				ft_is_color(int color); // Si color faux return 1, sinon 0
void			ft_check_file_half(m_point *map); // vérification des datas du fichiers
void			ft_check_map(m_point *map); // call toutes les merdes pour la map
void			ft_found_map(m_point *map); // cherche la map.
int				ft_is_not_map(char c, int one); // liste les caractères appartenant à la map.
void			ft_set_world_spawn(m_point *map, int u); // tout est dans le nom.
void			ft_create_mapping(m_point *map); // malloc de la map.
void			ft_fill_map(m_point *map); // remplis la map de son contenus.
void			ft_fill_line_map(m_point *map, int l); // l est la ligne à malloc :)
void			ft_parse_map(m_point *map); // parse toute la map à la recherche d'erreurs
void			ft_next_zero_map(m_point *map, int l, int x); // cherche une erreur dans la map et l'indique à map disp error;
void			ft_map_disp_error(m_point *map, int l, int x, int erreur); // indique où se situe l'erreur dans la map.
int				ft_next_zero_char(char c); // Liste des caractères valides dans map.
void			ft_error_detected(m_point *map); // affiche ou est l'erreur.

typedef	struct v_point // structure de calcul
{
	int		set; // 1 = set, 0 = non set
	double	deg; // variable temporaire de calcul en degree
	double	rad; // variable temporaire de calcul en radians
	double		x; // variable x de calcul du pythagore du rayon					triangle
	double		y; // variable y de calcul du pythagore du rayon					triangle
	int		posxr; // position x du vecteur rayon ex : le perso sur la map		point où se situe le vecteur sur la map
	int		posyr; // position y du vecteur rayon ex : le perso sur la map		point où se situe le vecteur sur la map
	int		px; // position dans la case en x du vecteur rayon					point où se trouve le vecteur dans la case
	int		py; // position dans la case en y du vecteur rayon					point où se trouve le vecteur dans la case
	int		ray; // taille d'un vecteur rayon.
	int		oray; // taille d'un vecteur rayon précédent. OBSOLETE ?
	int		p; // nombre de pytha à appliquer.
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
	// c_point	*calc; // structure de calculs contenue dans calc. // old
	c_point	*hc; // struct de calculs honrizontaux
	c_point	*vc; // struct de calculs verticaux
}				w_point;

void			ft_windows(m_point *map); // Fonction de base de la gestion de la fenetre
void			ft_exit_free_all(w_point *win, int ret); // Sortie avec free de win et de map, le ret correspond à la valeur retournée : -1 = erreurs, 0 = tout est bon.
void			ft_init_win(w_point *win, m_point *mapi, c_point *hca, c_point *vca); // fonction d'initialisation de la structure win
int				ft_entry_keyboard(int key, void *p); // fonction qui recois les entrées claviers et les attribues à leurs fonctions respectives.
int				ft_move_zqsd(int key, w_point *win); // déplacement du joueur dans ka casa : pos_x et pox_y sont modifiés.
void			ft_found_worldspawn(w_point *win); // trouve le point de spawn et le stock dans X et Y
void			ft_move_in_casa(w_point *win); // déplace sur x et y de casa et réafece pos_x et pos_y
void    		ft_map_disp_pos(w_point *win); // affichage de la map
int				ft_is_worldspawn(char c); // détection d'un caractère de spawn
void			ft_screen(w_point *win); // soccupe de l'écran
void			ft_set_screen(w_point *win); // soccupe de définir des variables pour l'écran
double			ft_radian_to_degrees(double rad); // converti win->calc->rad en degrées dans win->calc->deg
double			ft_degrees_to_radian(double deg); // converti win->calc->deg en radians dans win->calc->rad
int				ft_found_range(w_point *win, double d); // cherche la valeur d'un rayon
void			ft_first_inter(w_point *win); // cherche la première intersection d'un rayon
int				ft_right_angle(w_point *win, double d); // calcul du rayon avec un angle droit
void			ft_reset_calc(w_point *win); // init et reset des structures de calculs vc et hc
int				ft_is_wall(w_point *win, int x, int y); // return 0 si mur, 1 sinon.
void			ft_thales(w_point *win, double a); // applique thales sur un rayon donné en structure hc ou vc et affiche la colone, a = angle en degrés en partant du milieu
void			ft_disp_screen(w_point *win); // call thales autant de fois que de colones présentes.
void			ft_red_pixel(w_point *win, int h, int x); // permet de tester l'affichage, h = hauteur du mur, x = colone où print


#endif
