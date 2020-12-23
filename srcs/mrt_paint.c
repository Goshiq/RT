/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/23 09:48:00 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		in_circle(double x, double y, t_sp *sp)
{
	double	cur_rad;
	double	rl_rad;

	rl_rad = sp->diam / 2;
	cur_rad = sqrt(pow(x - sp->c_crd.x, 2) + pow(y - sp->c_crd.y, 2));
	if (cur_rad <= rl_rad)
		return (1);
	return (0);
}
/*
t_coord	CanvasToViewport(double x, double y, double d)
{
	t_coord	ans;


}
*/
int		key_hook(int key, void *param)
{
	t_scene	**t;

	t = (t_scene **)param;
	if (key == 53)
		mrt_doerr(0x0, 0x0, (t_scene **)param);
		//mlx_destroy_window((*t)->m_mlx, (*t)->m_win);
	return (0);
}

void	mrt_paint(t_scene **t)
{
	void	*m_win;
	double	x;
	double	y;
	//double	clr;
	//t_coord	D;

	m_win = mlx_new_window((*t)->m_mlx, (*t)->res->x, (*t)->res->y, "");
	//mrt_malloc(&m_win, WIN, t);
	x = (*t)->res->x / (-2);
	y = (*t)->res->y / 2;
	while (x++ < ((*t)->res->x / 2))
	{
		while (y-- > ((*t)->res->y / (-2)))
		{
	//		D = CanvasToViewport(x - 1, y - 1, (*t)->cams->d);
		}
		y = (*t)->res->y / 2;
	}
	//printf("%f\n", vec_len((*t)->cams->c_crd));
	printf("Done\n");
	//mlx_key_hook(m_win, &key_hook, t);
	mlx_loop((*t)->m_mlx);
}
