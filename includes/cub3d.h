/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/11/20 13:25:39 by guderram		  #+#	#+#			 */
/*   Updated: 2022/08/12 15:04:27 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# include <sys/time.h>

# define BUFFER_SIZE_GNL 32

/*	Touches sur mac book pro m1	*/
/*	Fonctionne potentiellement sur d'autres macs	*/
# define MAC_KEY_MOVE_FRONT 13
# define MAC_KEY_MOVE_BACK 1
# define MAC_KEY_MOVE_LEFT 0
# define MAC_KEY_MOVE_RIGHT 2
# define MAC_KEY_ROTATE_LEFT 123
# define MAC_KEY_ROTATE_RIGHT 124
# define MAC_KEY_ECHAP 53

/*	Touches pour linux (x)ubuntu sur mac de l'ecole	*/
# define KEY_MOVE_FRONT 119
# define KEY_MOVE_BACK 115
# define KEY_MOVE_LEFT 97
# define KEY_MOVE_RIGHT 100
# define KEY_ROTATE_LEFT 65361
# define KEY_ROTATE_RIGHT 65363
# define KEY_ECHAP 65307

/*	Bonus keys	*/
# define BONUS_KEY_ZOOM_IN 65451
# define BONUS_KEY_ZOOM_OUT 65453
# define BONUS_KEY_TEXTURE_MORE 61
# define BONUS_KEY_TEXTURE_LESS 45

/*	Distance de deplacement lors d'une pression de touche	*/
# define MOVE_SIZE 16
/*	Taille de la FOV, le champ de vision, en degre	*/
# define FOV_SIZE 60
/*	Angle de rotation lors d'une pression de touche	*/
# define ANG_SIZE 10
/*	Resolution de la fenetre	*/
# define RES_X 800
# define RES_Y 600
/*	Taille des murs	*/
# define WALL_SIZE 64

# define PIXEL_SIZE 8

# define PI_VAL 3.141

/*	BONUS	*/
# define CROSSAIR_PATH "./ress/bonus_crossair.xpm"
# define GUN_S_PATH "./ress/bonus_gun_small.xpm"
# define GUN_N_PATH "./ress/bonus_gun_normal.xpm"
# define GUN_X 320
# define GUN_Y 181

/*	******	*/
/*	 GNL	*/
/*	******	*/

/*	get_next_line.c	*/
char	*ft_strsub_bis(int **error);
char	*ft_strsub(char const *s, unsigned int start, size_t len, int **error);
void	ft_read(char **str, char **line, int ret, int *error);
int		get_next_line_bis(int error, int ret, char *str);
int		get_next_line(int fd, char **line);

/*	get_next_line_bis.c	*/
int		ft_exerror(char **str, int error);
void	ft_strdel(char **as);

/*	get_next_line_utils.c	*/
int		ft_strlen(char *str);
char	*ft_strnew(int *error);
int		ft_strchr(char *str);
int		ft_strcount(char *str);
void	ft_strjoin(char **str, const char *buff, int buff_size, int *error);

typedef struct j_point
{
	int		er;
	int		x;
	char	*fl;
	int		res;
	int		fr;
	int		fg;
	int		fb;
	int		floor;
	int		cr;
	int		cg;
	int		cb;
	int		ceiling;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	spawn;
	char	**map;
	int		l;
}				t_m_point;

typedef struct ver_point
{
	double	vr;
	double	vx;
	double	vy;
	double	vcr;
	double	vcx;
	double	vcy;

}				t_v_point;

typedef struct hor_point
{
	double	hr;
	double	hx;
	double	hy;
	double	hcr;
	double	hcx;
	double	hcy;

}				t_h_point;

typedef struct rgb_point
{
	int		r;
	int		g;
	int		b;
	int		s;
	int		bbp;
	int		sl;
	int		end;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		h;
	int		i;
}				t_c_point;

typedef struct k_point
{
	void		*mlx;
	void		*win1;
	int			er;
	t_m_point	*map;
	double		pos_x;
	double		pos_y;
	int			x;
	int			y;
	double		d;
	double		sr;
	t_h_point	*h;
	t_v_point	*v;
	t_c_point	*c;
	double		dirx;
	double		diry;
	int			or;
	t_img		*no;
	t_img		*so;
	t_img		*ea;
	t_img		*we;
	t_img		*screen;
	t_img		*crossair;
	t_img		*gun;
	char		*gu;
	char		*cr;
	char		*str;
	long		time;
	int			i;
	int			fps;
	int			opti;
	double		zoom;
	double		deg;
}				t_w_point;

/*	main.c	*/
int		main(int argc, char **argv);
/*	*******	*/
/*	 UTILS	*/
/*	*******	*/

/*	ft_error_1.c	*/
int		ft_exor_nfn(int error);
void	ft_map_disp_error(t_m_point *m, int l, int x, int erreur);
void	ft_show_error_file_bis(t_m_point *m, int u, int i, int j);
void	ft_show_error_file(t_m_point *m);
void	ft_error_detected(t_m_point *m);

/*	ft_utils.c	*/
double	ft_degrees_to_radian(double deg);
double	ft_radian_to_degrees(double rad);
void	ft_red_pixel(t_w_point *w, int h, int x);
int		ft_str_size(char *str);
int		ft_is_entier(double a);
double	ft_double_abs(double val);
void	ft_put_pixel_floor(t_w_point *w, int i);
void	ft_put_pixel_ceiling(t_w_point *w, int i);

/*	**********	*/
/*	 PARSING	*/
/*	**********	*/

/*	ft_check_file_name.c	*/
int		ft_check_open(char *argv);
int		ft_check_file_name_end(int extension, int exist, int u);
int		ft_check_file_name(char *argv, int extension);

/*	ft_parsing_map_data.c	*/
int		ft_parsing_while(t_m_point *m, int z);
void	ft_parsing_floor(t_m_point *m);
void	ft_parsing_ceiling(t_m_point *m);
char	*ft_parsing_get_path(t_m_point *m, int z);

/*	ft_parsing_map_data_bis.c	*/
void	ft_parsing_path_to_bis(t_m_point *m, int y, int z);
void	ft_parsing_path_to(t_m_point *m);

/*	ft_parsing_map_map.c	*/
void	ft_create_mapping_bis(t_m_point *m, int u);
void	ft_create_mapping(t_m_point *m);
void	ft_found_map_bis(t_m_point *m, int u);
void	ft_found_map(t_m_point *m);
void	ft_fill_map(t_m_point *m);

/*	ft_parsing_map_map_bis.c	*/
void	ft_fill_line_map(t_m_point *m, int l);
void	ft_parse_map_bis(t_m_point *m, int l, int x);
void	ft_parse_map(t_m_point *m);
void	ft_check_map(t_m_point *m);

/*	ft_parsing_map_utils.c	*/
void	ft_set_world_spawn(t_m_point *m, int u);
int		ft_is_not_map(char c, int one);
int		ft_next_zero_char(char c);
void	ft_next_zero_map(t_m_point *m, int l, int x);

/*	ft_parsing_map.c	*/
void	ft_check_fl_half(t_m_point *m);
void	ft_strfreejoin_newline_bis(t_m_point *m, char *buff, int i, int u);
void	ft_strfreejoin_newline(t_m_point *m, char *buff);
void	ft_parsing_open_fd(t_m_point *m, char *argv);
int		ft_parsing_map_bis(t_m_point *m);
int		ft_parsing_map(t_m_point *m, char *argv);

/*	ft_parsing_utils.c	*/
int		ft_incre_spaces(t_m_point *m, int backn, int h);
int		ft_is_space(char c, int backn, int end, t_m_point *m);
int		ft_is_color(int color);

/*	ft_structs.c	*/
void	ft_init_map(t_m_point *m);
void	ft_disp_verif(t_m_point *m);
void	ft_exit_free_map_paths(t_m_point *m);
int		ft_exit_free_map(t_m_point *m, int ret);

/*	*******	*/
/*	 DISP	*/
/*	*******	*/

/*	ft_init_img.c	*/
void	ft_xpm_file_to_image(t_w_point *w, t_m_point *m);
void	ft_init_no(t_w_point *w);
void	ft_init_so(t_w_point *w);
void	ft_init_ea(t_w_point *w);
void	ft_init_we(t_w_point *w);

/*	ft_windows.c	*/
void	ft_init_w(t_w_point *w, t_m_point *m);
int		ft_is_worldspawn(char c);
void	ft_found_worldspawn(t_w_point *w);
void	ft_exit_free_all(t_w_point *w, int ret);
void	ft_windows(t_m_point *m);
void	ft_xpm_file_to_image(t_w_point *w, t_m_point *m);

/*	ft_screen.c	*/
void	ft_screen_bis(t_w_point *w, double i, double r, double d);
void	ft_screen(t_w_point *w);
void	ft_swap_pos(t_w_point *w);
void	ft_screen_init(t_w_point *w);

/*	ft_draw.c	*/
void	ft_put_texture(t_w_point *w, char *img, int xx, int yy);
void	ft_red_pixel(t_w_point *w, int h, int x);
void	ft_red_pixel_up(t_w_point *w, int h, int x);
void	ft_red_pixel_bord(t_w_point *w, int h, int x);

/*	ft_draw_bis.c	*/
void	ft_put_pixel_ceiling(t_w_point *w, int i);
void	ft_put_pixel_floor(t_w_point *w, int i);
int		ft_get_centieme(double x);

/*	*******	*/
/*	 CALC	*/
/*	*******	*/

/*	ft_calc_thales.c	*/
double	ft_thales_range_or(t_w_point *w);
double	ft_thales_angle_conv(t_w_point *w, double d);
double	ft_thales_pytha(double x, double y);
void	ft_thales_init(t_w_point *w, double d);
int		ft_thales_wall(t_w_point *w, double x, double y);
double	ft_thales_range(t_w_point *w, double d);

/*	ft_calc_init.c	*/
void	ft_re_set_calc(t_w_point *w);
double	ft_vc_pytha(t_w_point *w, double y, double d);
void	ft_vc_init(t_w_point *w, double d);
double	ft_hc_pytha(t_w_point *w, double x, double d);
void	ft_hc_init(t_w_point *w, double d);

/*	ft_calc_add.c	*/
void	ft_vc_add(t_w_point *w);
void	ft_hc_add(t_w_point *w);

/*	******** */
/*	MOVE	 */
/*	******** */

/*	trigo.c		*/
double	convert_to_radian(double degree);
double	find_y(double d, double h);
double	find_x(double d, double h);

/*	ft_entry_key.c	*/
int		ft_entry_keyboard(int key, void *p);
int		ft_cross_is_red(void *p);

/*	ft_position.c	*/
void	ft_map_disp_pos(t_w_point *win);
void	ft_move_in_casa(t_w_point *win);
int		ft_move_zqsd(int key, t_w_point *win);

/*	******** */
/*	BONUS	 */
/*	******** */
void	ft_put_crossair(t_w_point *w);
void	ft_put_pixel_cross(t_w_point *w, int x, int y);
long	ft_get_time(void);
void	ft_init_fps(t_w_point *w);
void	ft_opti(t_w_point *w, int h, int x);
void	ft_bonus_key(int key, t_w_point *w);
void	ft_move_in_casa_bis(t_w_point *win);
void	ft_put_pixel_gun(t_w_point *w, int x, int y);
void	ft_put_gun(t_w_point *w);
void	ft_init_gun(t_w_point *w);

#endif
