/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/09 16:40:27 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		cross_sp(t_scene **t, t_coord cd, t_sp *sp, double *c_min)
{
	t_coord	s;
	t_coord	c;
	t_coord	cs;
	double	cross;
	double	rad;

	c = (*t)->cams->c_crd;
	s = sp->c_crd;
	cs = dots_to_vec(c, s);
	rad = sp->diam / 2;
	cross = vec_len(vec_mult_vec(cs, cd)) / vec_len(cd);
	if (cross < rad)
	{
		*c_min = sqrt(pow(vec_len(cs), 2) - pow(cross, 2)) -
					sqrt(pow(rad, 2) - pow(cross, 2));
		rad = *c_min / vec_len(cd);
		cd = vec_mult_scal(cd, rad);
		s = vec_sum(cd, c);
		return (calc_col(t, sp, s));
	}
	return (0);
}

int		get_clr(t_scene **t, t_cams cam, t_coord d)
{
	double	c_min;
	double	dist;
	int		clr;
	int		tmpclr;
	t_figs	*fig;

	clr = 0;
	fig = (*t)->figs;
	c_min = INFINITY;
	d = dots_to_vec(cam.c_crd, d);
	while (fig)
	{
		dist = INFINITY;
		if (fig->type == SP)
			tmpclr = cross_sp(t, d, (t_sp *)fig->data, &dist);
		if (dist < c_min)
		{
			c_min = dist;
			clr = tmpclr;
		}
		fig = fig->next;
	}
	return (clr);
}

int		key_hook(int key, void *param)
{
	t_scene	**t;

	t = (t_scene **)param;
	if (key == 53)
		mrt_doerr(0x0, 0x0, t);
	else if (key == 123)
		(*t)->cams = (*t)->cams->prev;
	else if (key == 124)
		(*t)->cams = (*t)->cams->next;
	mrt_paint(t);
	return (0);
}

void	mrt_paint(t_scene **t)
{
	void	*m_win;
	double	x, resx;
	double	y, resy;
	int		clr;
	t_coord	d;

	m_win = mlx_new_window((*t)->m_mlx, (*t)->res->x, (*t)->res->y, "");
	resx = (*t)->res->x / 2;
	resy = (*t)->res->y / 2;
	x = 0;
	y = 0;
	while (x++ < resx * 2)
	{
		while (y++ < resy * 2)
		{
			d = loc_to_glob(x - 1 - resx, resy - y + 1, (*t)->cams);
			if (0 < (clr = get_clr(t, *((*t)->cams), d)))
				mlx_pixel_put((*t)->m_mlx, m_win, x - 1, y - 1, clr);
		}
		y = 0;
	}
	printf("Done\n");
	mlx_key_hook(m_win, &key_hook, t);
	mlx_loop((*t)->m_mlx);
}
