/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:25:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 13:34:16 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"

void	destroy_map(t_map *map)
{
	int		i;

	if (map)
	{
		i = 0;
		while (i < 6)
		{
			if (map->elements[i])
				free(map->elements[i]);
			i++;
		}
		if (map->contents)
		{
			while (*map->contents)
			{
				free(*map->contents);
				map->contents++;
			}
			free(map->contents);
		}
		free(map);
	}
	return ;
}
