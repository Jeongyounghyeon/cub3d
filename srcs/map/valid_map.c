/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:32:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/12 12:21:34 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "bool.h"

t_bool	valid_map(t_map *map)
{
	if (valid_map_elements(map->elements) == false
		|| valid_map_contents(map->contents) == false)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

t_bool	valid_map_elements(char *elements[])
{
	return (true);
}

t_bool	valid_map_contents(char **contents)
{
	return (true);
}
