/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/13 11:34:02 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	recognize_figs(t_scene **t, t_coord d, t_figs *fig, t_ans *ans)
{
	if (fig->type == SP)
		cross_sp(t, d, (t_sp *)(fig->data), ans);
}

int		get_clr(t_scene **t, t_cams cam, t_coord d)
{
	double	c_min;
	t_ans	*ans;
	int		clr;
	t_figs	*fig;

	clr = 0;
	fig = (*t)->figs;
	c_min = INFINITY;
	d = dots_to_vec(cam.c_crd, d);
	ans = malloc(sizeof(t_ans));
	ans->fig = malloc(sizeof(t_figs));
	while (fig)
	{
		ans->d = INFINITY;
		recognize_figs(t, d, fig, ans);
		if (ans->d < c_min)
		{
			c_min = ans->d;
			calc_col(t, ans, &clr);
		}
		fig = fig->next;
	}
	free_ans(ans);
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
	t_doub	res;
	t_doub	xy;
	int		clr;
	t_coord	d;

	res.x = (*t)->res->x / 2;
	res.y = (*t)->res->y / 2;
	xy.x = 0;
	xy.y = 0;
	mrt_clear_win(t);
	while (xy.x++ < res.x * 2)
	{
		while (xy.y++ < res.y * 2)
		{
			d = loc_to_glob(xy.x - 1 - res.x, res.y - xy.y + 1, (*t)->cams);
			if (0 < (clr = get_clr(t, *((*t)->cams), d)))
				mlx_pixel_put((*t)->m_mlx, (*t)->m_win, xy.x, xy.y, clr);
		}
		xy.y = 0;
	}
	printf("Done\n");
	mlx_key_hook((*t)->m_win, &key_hook, t);
	mlx_loop((*t)->m_mlx);
}
