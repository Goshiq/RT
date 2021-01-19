/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_mallocer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:28:13 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/19 16:14:28 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	malloc_ans(t_scene **t, t_ans **ans)
{
	(void)t;
	*ans = malloc(sizeof(t_ans));
	(*ans)->d = INFINITY;
	(*ans)->s = pnts_to_vec(0.0, 0.0, 0.0);
}

void	free_ans(t_ans **ans)
{
	free(*ans);
}

void	ft_lstadd_back(t_lst **ptr, void *p, t_scene **t)
{
	t_lst	*prev;
	t_lst	*toadd;

	if (!(toadd = malloc(sizeof(t_lst))))
		mrt_doerr("Can't allocate memory\n", 0x0, t);
	toadd->next = 0x0;
	toadd->ptr = p;
	if (*ptr == 0x0)
	{
		*ptr = toadd;
		return ;
	}
	prev = *ptr;
	while (prev->next)
		prev = prev->next;
	prev->next = toadd;
}

void	mrt_malloc(void **p, t_mall type, t_scene **t)
{
	if (type == SC)
		*p = malloc(sizeof(t_scene));
	else if (type == RES)
		*p = malloc(sizeof(t_res));
	else if (type == FIGS)
		*p = malloc(sizeof(t_figs));
	else if (type == CAMS)
		*p = malloc(sizeof(t_cams));
	else if (type == LGHTS)
		*p = malloc(sizeof(t_lght));
	else if (type == SPH)
		*p = malloc(sizeof(t_sp));
	else if (type == PLA)
		*p = malloc(sizeof(t_pl));
	else if (type == CYL)
		*p = malloc(sizeof(t_cy));
	else if (type == SQU)
		*p = malloc(sizeof(t_sq));
	else if (type == TRI)
		*p = malloc(sizeof(t_tr));
	if (!(*p))
		mrt_doerr("Can't allocate memory\n", 0x0, t);
	init_objs(p, type);
	ft_lstadd_back(&((*t)->ptr), *p, t);
}
