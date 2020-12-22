/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:50:38 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/18 18:23:46 by jmogo            ###   ########.fr       */
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
	TRI
}	t_mall;

typedef struct		s_scene
{
	void			*m_mlx;
	void			*m_win;
	struct s_res	*res;
	struct s_figs	*figs;
	struct s_cams	*cams;
	struct s_lght	*lghts;
	struct s_lght	*alght;
	struct s_lst	*ptr;
}					t_scene;

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
	struct s_cams	*next;
	struct s_cams	*prev;
}					t_cams;

typedef struct		s_lght
{
	struct s_coord	c_crd;
	double			bright;
	int				clr;
	struct s_lght	*next;
}					t_lght;

typedef struct		s_sp
{
	struct s_coord	c_crd;
	double			diam;
	int				clr;
}					t_sp;

typedef struct		s_pl
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	int				clr;
}					t_pl;

typedef struct		s_sq
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	double			side;
	int				clr;
}					t_sq;

typedef struct		s_cy
{
	struct s_coord	c_crd;
	struct s_coord	n_crd;
	double			diam;
	double			height;
	int				clr;
}					t_cy;

typedef struct		s_tr
{
	struct s_coord	f_crd;
	struct s_coord	s_crd;
	struct s_coord	t_crd;
	int				clr;
}					t_tr;

void				add_cam(t_scene **t, char **s);
void				add_fig(t_scene **t, char **s, t_type type);
void				add_lght(t_scene **t, char **s);
void				add_next_cam(t_scene **t, char **s);
void				add_next_lght(t_scene **t, char **s);
int					check_atoi(char *s);
int					check_figs(char *s, t_type *type);
void				free_lst(t_scene **t);
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
int					get_next_line(int fd, char **line);
void				init_alght(t_lght **t);
void				init_cams(t_cams **t);
void				init_figs(t_figs **t);
void				init_lghts(t_lght **t);
void				init_res(t_res **t);
void				init_scene(t_scene **t);
int					mrt_doerr(char *s, char *str, t_scene **t);
void				mrt_malloc(void **p, t_mall type, t_scene **t);
int					mrt_parse_scene(char *s);
void				mrt_paint(t_scene **t);
int					mrt_saveimg(char *s);
int					parse_color(char *s);
int					parse_coord(t_coord *c, char *s);
void				parse_cy(t_scene **t, char **s);
int					parse_fov(int *fov, char *s);
int					parse_orient(t_coord *c, char *s);
void				parse_pl(t_scene **t, char **s);
void				parse_sp(t_scene **t, char **s);
void				parse_sq(t_scene **t, char **s);
void				parse_tr(t_scene **t, char **s);
void				set_alght(t_scene **t, char **s);
void				set_res(t_scene **t, char **s);

#endif
