/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/07 15:18:35 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		cross_sp(t_coord c, t_coord d, t_sp *sp, double *c_max)
{
	t_coord	s;
	t_coord	cs;
	t_coord	cd;

	(void)c_max;
	s = sp->c_crd;
	cs = dots_to_vec(c, s);
	cd = dots_to_vec(c, d);
	if (vec_len(vec_mult_vec(cs, cd)) / vec_len(cd) < (sp->diam / 2))
		return (sp->clr);
	return (0);
}

int		get_clr(t_scene *t, t_cams cam, t_coord d)
{
	double	c_max;
	int		clr;
	t_figs	*f_closest;

	clr = 0;
	c_max = INFINITY;
	f_closest = t->figs;
	while (f_closest)
	{
		if (f_closest->type == SP)
			clr = cross_sp(cam.c_crd, d, (t_sp *)f_closest->data, &c_max);
		if (clr > 0)
			return (clr);
		f_closest = f_closest->next;
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
			if (0 < (clr = get_clr(*t, *((*t)->cams), d)))
				mlx_pixel_put((*t)->m_mlx, m_win, x - 1, y - 1, clr);
		}
		y = 0;
	}
	printf("Done\n");
	mlx_key_hook(m_win, &key_hook, t);
	mlx_loop((*t)->m_mlx);
}
