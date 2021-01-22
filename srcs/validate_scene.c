/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:13:25 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/22 11:29:31 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_scene(t_scene *t)
{
	if (t->res->x <= 0)
		mrt_doerr("No resolution in the scene-file\n", 0x0, &t);
	if (t->alght->bright < 0)
		mrt_doerr("No ambient light in the scene\n", 0x0, &t);
}
