/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:44:59 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 18:51:25 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	wrap_dd(t_two *dd, t_ans *ans, t_lght *light, t_ans *shad)
{
	dd->c1 = ans->s;
	dd->c2 = dots_to_vec(ans->s, light->c_crd);
	shad->d = INFINITY;
}
