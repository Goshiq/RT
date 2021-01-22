/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:26:04 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/22 11:23:58 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_res(t_scene **t, char **s)
{
	int	gotx;
	int	goty;
	int	resx;
	int	resy;

	if ((*t)->res->x > 0 || (*t)->res->y > 0)
		mrt_doerr("Got a resolution twice\n", 0x0, t);
	if (!s[1] || !s[2] || s[3])
		mrt_doerr("Wrong input resolution format\n", 0x0, t);
	if (check_atoi(s[1]) || check_atoi(s[2]))
		mrt_doerr("Wrong input resolution format\n", 0x0, t);
	gotx = ft_atoi(s[1]);
	goty = ft_atoi(s[2]);
	if (gotx <= 0 || goty <= 0 || s[3])
		mrt_doerr("Wrong input resolution format\n", 0x0, t);
	mlx_get_screen_size((*t)->m_mlx, &resx, &resy);
	if (gotx > resx)
		gotx = resx;
	if (goty > resy)
		goty = resy;
	(*t)->res->x = gotx;
	(*t)->res->y = goty;
}

void	set_alght(t_scene **t, char **s)
{
	t_clr	clr;
	float	br;

	if (0 < (*t)->alght->bright)
		mrt_doerr("Got an ambient lightning twice\n", 0x0, t);
	if (!s[1] || !s[2] || s[3])
		mrt_doerr("Wrong input ambient lightning format\n", 0x0, t);
	br = atof(s[1]);
	if (br < 0 || br > 1)
		mrt_doerr("Wrong ambient lightning brightness:\n", s[1], t);
	(*t)->alght->bright = br;
	clr = parse_color(s[2], br);
	if (0 > clr.r)
		mrt_doerr("Wrong ambient lightning color:\n", s[2], t);
	(*t)->alght->clr = clr;
}

void	add_cam(t_scene **t, char **s)
{
	if (!s[1] || !s[2] || !s[3] || s[4])
		mrt_doerr("Wrong input camera format\n", 0x0, t);
	if (0 > (*t)->cams->fov)
	{
		if (0 > (parse_coord(&((*t)->cams->c_crd), s[1])))
			mrt_doerr("Wrong camera's coordinates format:\n", s[1], t);
		if (0 > (parse_orient(&((*t)->cams->n_crd), s[2])))
			mrt_doerr("Wrong camera's orientation format:\n", s[2], t);
		if (0 > (parse_fov(&((*t)->cams->fov), s[3])))
			mrt_doerr("Wrong camera's FOV format:\n", s[3], t);
		get_scr_param((*t)->cams, (*t)->res);
		(*t)->cams->next = (*t)->cams;
		(*t)->cams->prev = (*t)->cams;
	}
	else
		add_next_cam(t, s);
}

void	add_lght(t_scene **t, char **s)
{
	t_clr	clr;
	float	br;

	if (!s[1] || !s[2] || !s[3] || s[4])
		mrt_doerr("Wrong input light format\n", 0x0, t);
	if (0 > (*t)->lghts->bright)
	{
		if (0 > (parse_coord(&((*t)->lghts->c_crd), s[1])))
			mrt_doerr("Wrong light's coordinates format:\n", s[1], t);
		br = atof(s[2]);
		if (br < 0 || br > 1)
			mrt_doerr("Wrong light brightness:\n", s[2], t);
		(*t)->lghts->bright = br;
		clr = parse_color(s[3], br);
		if (0 > clr.r)
			mrt_doerr("Wrong light color:\n", s[3], t);
		(*t)->lghts->clr = clr;
	}
	else
		add_next_lght(t, s);
}

void	add_fig(t_scene **t, char **s, t_type type)
{
	if (type == CY)
		parse_cy(t, s);
	else if (type == SP)
		parse_sp(t, s);
	else if (type == SQ)
		parse_sq(t, s);
	else if (type == TR)
		parse_tr(t, s);
	else if (type == PL)
		parse_pl(t, s);
}
