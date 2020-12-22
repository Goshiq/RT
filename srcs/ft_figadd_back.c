/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:59:00 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/17 18:18:38 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_figadd_back(t_scene **t, void *fig, t_type type)
{
	t_figs	*prev;
	t_figs	*toadd;

	if ((*t)->figs->type == DEF)
	{
		(*t)->figs->type = type;
		(*t)->figs->data = fig;
		(*t)->figs->next = 0x0;
		return ;
	}
	toadd = 0x0;
	mrt_malloc((void **)(&toadd), FIGS, t);
	toadd->type = type;
	toadd->data = fig;
	toadd->next = 0x0;
	prev = (*t)->figs;
	while (prev->next)
		prev = prev->next;
	prev->next = toadd;
}
