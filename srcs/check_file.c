/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:36:29 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/21 16:53:04 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_file(char *s)
{
	char	**splitted;

	if (!(splitted = ft_split(s, '.')))
		return (1);
	if (splitted[1] && ft_strcmp(splitted[1], "rt"))
		return (1);
	free_split(splitted);
	return (0);
}
