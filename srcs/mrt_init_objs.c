/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:39:41 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/19 11:39:44 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
