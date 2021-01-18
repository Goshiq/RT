/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:05:03 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/16 16:19:25 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	finish_it(void *p)
{
	t_scene	**t;

	t = (t_scene **)p;
	mrt_doerr(0x0, 0x0, t);
	return (1);
}