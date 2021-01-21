/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:50:38 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/21 16:45:36 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define MIN 0.005
# define COEF 4
# define SCREEN "screenshot.bmp"

typedef enum
{
	DEF,
	CY,
	PL,
	SP,
	SQ,
	TR
}	t_type;

typedef enum
{
	SC,
	RES,
	FIGS,
	CAMS,
	LGHTS,
	ALGHT,
	PTR,
	SPH,
	PLA,
	CYL,
	SQU,
	TRI,
	IMG
}	t_mall;

typedef struct		s_scene
{
	void			*m_mlx;
	void			*m_win;
	void			*m_img;
	struct s_res	*res;
	struct s_figs	*figs;
	struct s_cams	*cams;
	struct s_lght	*lghts;
	struct s_lght	*alght;
	struct s_lst	*ptr;
	int				fd;
	struct s_img	*img;
}					t_scene;

typedef struct		s_doub
{
	double			x;
	double			y;
}					t_doub;

typedef struct		s_lst
{
	void			*ptr;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
}					t_clr;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_figs
{
	t_type			type;
	void			*data;
	struct s_figs	*next;
}					t_figs;

typedef struct		s_cams
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	int				fov;
	double			d;
	t_coord			c_scr;
	t_coord			px;
	t_coord			py;
	struct s_cams	*next;
	struct s_cams	*prev;
}					t_cams;

typedef struct		s_lght
{
	struct s_coord	c_crd;
	double			bright;
	t_clr			clr;
	struct s_lght	*next;
}					t_lght;

typedef struct		s_sp
{
	struct s_coord	c_crd;
	double			diam;
	t_clr			clr;
}					t_sp;

typedef struct		s_pl
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	t_clr			clr;
}					t_pl;

typedef struct		s_sq
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	double			side;
	t_clr			clr;
}					t_sq;

typedef struct		s_cy
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	double			diam;
	double			height;
	t_clr			clr;
}					t_cy;

typedef struct		s_tr
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	t_clr			clr;
	struct s_coord	s_crd;
	struct s_coord	t_crd;
}					t_tr;

typedef struct		s_ans
{
	double			d;
	t_coord			s;
	t_figs			*fig;
}					t_ans;

typedef struct		s_two
{
	t_coord			c1;
	t_coord			c2;
}					t_two;

typedef struct		s_img
{
	int				*adr;
	int				fd;
	int				bits;
	int				l_lngth;
	int				endian;
}					t_img;

void				add_cam(t_scene **t, char **s);
t_clr				add_clr(t_clr c1, t_clr c2);
void				add_fig(t_scene **t, char **s, t_type type);
void				add_lght(t_scene **t, char **s);
void				add_next_cam(t_scene **t, char **s);
void				add_next_lght(t_scene **t, char **s);
void				calc_br(t_scene **t, t_ans *ans, t_clr *clr);
int					calc_col(t_scene **t, t_ans *ans, t_clr clr);
double				calc_ang_sp(t_ans *ans, t_lght *light);
double				calc_ang_pl(t_ans *ans, t_lght *light);
double				calc_ang_cy(t_ans *ans, t_lght *light);
int					check_atoi(char *s);
int					check_figs(char *s, t_type *type);
int					check_file(char *s);
void				check_n_tr(t_two d, t_coord *n, t_tr *tr);
void				cross_pl(t_scene **t, t_two cd, t_pl *pl, t_ans *ans);
void				cross_sp(t_scene **t, t_two cd, t_sp *sp, t_ans *ans);
void				cross_sq(t_scene **t, t_two cd, t_sq *sq, t_ans *ans);
void				cross_cy(t_scene **t, t_two cd, t_cy *sq, t_ans *ans);
void				cross_tr(t_scene **t, t_two cd, t_tr *sq, t_ans *ans);
t_coord				dots_to_vec(t_coord a, t_coord b);
void				find_cross(t_scene **t, t_two d, t_ans *ans);
t_coord				find_n_tr(t_tr *tr);
int					finish_it(void *t);
void				free_lst(t_scene **t);
void				free_ans(t_ans **ans);
int					free_split(char **s);
int					free_str(char *s1, char *s2);
double				ft_atof(char *s);
int					ft_atoi(char *s);
int					ft_isdigit(char c);
void				ft_figadd_back(t_scene **t, void *fig, t_type type);
void				ft_lstadd_back(t_lst **ptr, void *p, t_scene **t);
size_t				ft_numlen(long n);
void				ft_putcahr(char c);
int					ft_putstr(char *s);
char				**ft_split(char *s, char c);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(char *s);
char				*ft_strchr(char *s, char c);
char				*ft_strdup(char *s);
char				*ft_strjoin(char *s1, char *s2);
double				get_angle(t_ans *ans, t_lght *light);
int					get_clr(t_scene **t, t_coord d);
t_clr				get_clr_fig(t_ans *ans);
int					get_next_line(int fd, char **line);
void				get_scr_param(t_cams *c, t_res *res);
int					in_tr(t_coord p, t_tr *tr);
void				init_alght(t_lght **t);
void				init_cams(t_cams **t);
void				init_figs(t_figs **t);
void				init_lghts(t_lght **t);
void				init_objs(void **p, t_mall type);
void				init_pl(t_pl **t);
void				init_res(t_res **t);
void				init_sc(t_scene **t);
void				init_sp(t_sp **t);
void				init_sq(t_sq **t);
void				init_cy(t_cy **t);
void				init_tr(t_tr **t);
void				init_win_img(t_scene *t, int save);
int					key_hook(int key, void *param);
t_coord				loc_to_glob(int x, int y, t_cams *c);
t_clr				make_clr(int r, int g, int b);
void				malloc_ans(t_scene **t, t_ans **ans);
void				malloc_scene(t_scene **t);
void				manage_loop(t_scene **t, int save);
void				move_cam_fwrd(t_cams *cam);
void				move_cam_back(t_cams *cam);
int					mrt_doerr(char *s, char *str, t_scene **t);
void				mrt_clear_win(t_scene **t);
t_coord				mrt_get_c_screen(t_cams *cam);
void				mrt_malloc(void **p, t_mall type, t_scene **t);
int					mrt_parse_scene(char *s, int save);
void				mrt_paint(t_scene **t, int save);
void				mrt_saver(t_scene **t, t_doub xy, int clr);
t_clr				parse_color(char *s, float br);
int					parse_coord(t_coord *c, char *s);
void				parse_cy(t_scene **t, char **s);
int					parse_fov(int *fov, char *s);
int					parse_orient(t_coord *c, char *s);
void				parse_pl(t_scene **t, char **s);
void				parse_sp(t_scene **t, char **s);
void				parse_sq(t_scene **t, char **s);
void				parse_tr(t_scene **t, char **s);
t_coord				pnts_to_vec(double x, double y, double z);
void				put_pixel(t_scene **t, t_doub xy, int clr, int save);
void				recognize_figs(t_scene **t, t_two d, t_figs *fig,
									t_ans *ans);
int					rgb_to_int(t_clr clr);
void				set_alght(t_scene **t, char **s);
void				set_res(t_scene **t, char **s);
t_clr				use_bright(t_clr clr, double br);
int					validate_scene(t_scene **t);
t_coord				vec_div_scal(t_coord v, double d);
double				vec_len(t_coord v);
t_coord				vec_mult_scal(t_coord v, double d);
t_coord				vec_mult_vec(t_coord v1, t_coord v2);
void				vec_norm(t_coord *v);
double				vec_scal_vec(t_coord v1, t_coord v2);
t_coord				vec_substr(t_coord v1, t_coord v2);
t_coord				vec_sum(t_coord v1, t_coord v2);

#endif
