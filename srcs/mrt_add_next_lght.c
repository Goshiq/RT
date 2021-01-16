/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_next_lght.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:44:05 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/15 13:42:17 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_lght_back(t_lght *lst, t_lght *lgt)
{
	t_lght	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lgt;
}

void	add_next_lght(t_scene **t, char **s)
{
	t_clr	clr;
	float	br;
	t_lght	*lght;

	lght = 0x0;
	mrt_malloc((void **)(&lght), LGHTS, t);
	if (0 > (parse_coord(&(lght->c_crd), s[1])))
		mrt_doerr("Wrong light's coordinates format:\n", s[1], t);
	br = atof(s[2]);
	if (br < 0 || br > 1)
		mrt_doerr("Wrong a light brightness:\n", s[2], t);
	lght->bright = br;
	clr = parse_color(s[3], br);
	if (0 > clr.r)
		mrt_doerr("Wrong a light color:\n", s[3], t);
	lght->clr = clr;
	lght->next = 0x0;
	add_lght_back((*t)->lghts, lght);
}
