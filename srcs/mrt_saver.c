/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_saver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:39:50 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/20 22:42:15 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>
#include <string.h>

void	mrt_saver(t_scene **t, t_doub xy, int clr)
{
	(void)t;
	(void)xy;
	(void)clr;
	printf("d is %d\n", (*t)->img->bits);
}
