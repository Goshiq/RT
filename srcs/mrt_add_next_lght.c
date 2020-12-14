/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_next_lght.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:44:05 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/08 12:16:57 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_next_lght(t_scene **t, char **s)
{
	int		clr;
	float	br;
	t_lght	*lght;

	if (!(lght = malloc(sizeof(t_lght))))
		mrt_doerr("Can't allocate memory for the new light:\n", s[1], t);
	if (0 > (parse_coord(&(lght->c_crd), s[1])))
		mrt_doerr("Wrong light's coordinates format:\n", s[1], t);
	br = atof(s[2]);
	if (br < 0 || br > 1)
		mrt_doerr("Wrong a light brightness:\n", s[2], t);
	lght->bright = br;
	if (0 > (clr = parse_color(s[3])))
		mrt_doerr("Wrong a light color:\n", s[3], t);
	lght->clr = clr;
	lght->next = 0x0;
	(*t)->lghts->next = lght;
}
