/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:03:27 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/08 13:19:35 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_res(t_res **t)
{
	(*t)->x = 0;
	(*t)->y = 0;
}

void	init_alght(t_lght **t)
{
	(*t)->bright = -1;
	(*t)->clr = 0;
}

void	init_cams(t_cams **t)
{
	(*t)->fov = -1;
}

void	init_lghts(t_lght **t)
{
	(*t)->next = 0x0;
	(*t)->bright = -1;
}

void	init_figs(t_figs **t)
{
	(*t)->type = DEF;
}
