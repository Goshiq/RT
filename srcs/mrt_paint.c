/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:26:25 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/13 21:05:31 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		in_circle(float x, float y, t_sp *sp)
{
	float	cur_rad;
	float	rl_rad;

	rl_rad = sp->diam / 2;
	cur_rad = sqrt(pow(x - sp->c_crd.x, 2) + pow(y - sp->c_crd.y, 2));
	if (cur_rad <= rl_rad)
		return (1);
	return (0);
}

int		key_hook(int key, void *param)
{
	if (!param)
		if (key == 53)
			exit(0);
	return (0);
}

void	mrt_paint(t_scene **t)
{
	void	*m_win;
	int		x;
	int		y;
	float	clr;

	if (!(m_win = mlx_new_window((*t)->m_mlx, (*t)->res->x, (*t)->res->y, "")))
		mrt_doerr("Can't create the window\n", 0x0, t);
	x = 0;
	y = 0;
	while (1)
	{
		if ((*t)->figs->type == 3)
		{
			clr = ((t_sp *)(*t)->figs->data)->clr + (*t)->alght->clr * (*t)->alght->bright;
			while (x++ < (*t)->res->x)
			{
				while (y++ < (*t)->res->y)
					if (in_circle(x, y, (t_sp *)(*t)->figs->data))
						mlx_pixel_put((*t)->m_mlx, m_win, x - 1, y - 1, clr);
				y = 0;
			}
		}
		if (!(*t)->figs->next)
			break ;
		(*t)->figs = (*t)->figs->next;
		x = 0;
	}
	printf("Done\n");
	mlx_key_hook(m_win, &key_hook, 0x0);
	mlx_loop((*t)->m_mlx);
}
