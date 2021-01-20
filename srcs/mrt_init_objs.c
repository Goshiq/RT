/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:39:41 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/20 22:42:02 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_win_img(t_scene *t, int save)
{
	t_img	*p;

	if (!save)
	{
		if (!(t->m_win = mlx_new_window(t->m_mlx, t->res->x, t->res->y, "")))
			mrt_doerr("Can't init MLX_WIN\n", 0x0, &t);
	}
	else
	{
		if (!(p = malloc(sizeof(t_img))))
			mrt_doerr("Can't malloc memory for the image\n", 0x0, &t);
		p->adr = 0x0;
		p->bits = 0;
		p->l_lngth = 0;
		p->endian = 0;
		p->fd = -1;
		t->img = p;
		ft_lstadd_back(&(t->ptr), (void *)p, &t);
		if (!(t->m_img = mlx_new_image(t->m_mlx, t->res->x, t->res->y)))
			mrt_doerr("Can't init MLX_IMAGE\n", 0x0, &t);
		if (!(t->img->adr = (int *)mlx_get_data_addr(t->m_img, &t->img->bits,
						&t->img->l_lngth, &t->img->endian)))
			mrt_doerr("Can't get image info\n", 0x0, &t);
	}
}

void	init_objs(void **p, t_mall type)
{
	if (type == SC)
		init_sc((t_scene **)p);
	else if (type == RES)
		init_res((t_res **)p);
	else if (type == FIGS)
		init_figs((t_figs **)p);
	else if (type == CAMS)
		init_cams((t_cams **)p);
	else if (type == LGHTS)
		init_lghts((t_lght **)p);
	else if (type == SPH)
		init_sp((t_sp **)p);
	else if (type == PLA)
		init_pl((t_pl **)p);
	else if (type == CYL)
		init_cy((t_cy **)p);
	else if (type == SQU)
		init_sq((t_sq **)p);
	else if (type == TRI)
		init_tr((t_tr **)p);
}
