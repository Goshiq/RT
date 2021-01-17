/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:11:24 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/17 14:12:12 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rgb_to_int(t_clr clr)
{
	int	ans;

	ans = clr.r << 16 | clr.g << 8 | clr.b;
	return (ans);
}

t_clr	use_bright(t_clr clr, double br)
{
	t_clr	ans;

	ans.r = clr.r * br;
	ans.g = clr.g * br;
	ans.b = clr.b * br;
	return (ans);
}
