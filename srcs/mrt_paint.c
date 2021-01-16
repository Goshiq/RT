/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/16 09:30:37 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	recognize_figs(t_scene **t, t_two d, t_figs *fig, t_ans *ans)
{
	if (fig->type == SP)
		cross_sp(t, d, (t_sp *)(fig->data), ans);
	if (fig->type == PL)
		cross_pl(t, d, (t_pl *)(fig->data), ans);
}

void	find_cross(t_scene **t, t_two d, t_ans *ans)
{
	t_figs	*fig;
	double	c_min;
	t_coord	tmp;

	c_min = INFINITY;
	fig = (*t)->figs;
	while (fig)
	{
		ans->d = INFINITY;
		recognize_figs(t, d, fig, ans);
		if (ans->d < c_min)
		{
			c_min = ans->d;
			tmp = ans->s;
			ans->fig = fig;
		}
		fig = fig->next;
	}
	ans->d = c_min;
	ans->s = tmp;
}

int		get_clr(t_scene **t, t_coord d)
{
	t_ans	*ans;
	t_clr	lght_clr;
	t_two	crds;

	lght_clr = make_clr(0, 0, 0);
	d = dots_to_vec((*t)->cams->c_crd, d);
	vec_norm(&d);
	crds.c1 = (*t)->cams->c_crd;
	crds.c2 = d;
	ans = malloc(sizeof(t_ans));
	ans->d = INFINITY;
	find_cross(t, crds, ans);
	if (ans->d == INFINITY)
		return (0);
	calc_br(t, ans, &lght_clr);
	free(ans);
	return (calc_col(t, ans, lght_clr));
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
			if (0 < (clr = get_clr(t, d)))
				mlx_pixel_put((*t)->m_mlx, (*t)->m_win, xy.x, xy.y, clr);
		}
		xy.y = 0;
	}
	printf("Done\n");
	mlx_key_hook((*t)->m_win, &key_hook, t);
	mlx_loop((*t)->m_mlx);
}
