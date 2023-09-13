/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:32:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:22:08 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "bool.h"

t_bool			valid_map(t_map *map);
static t_bool	valid_map_elements(char *elements[]);
static t_bool	valid_map_contents(t_map *map);
static t_bool	valid_a_content(char content, t_map *map, int x, int y);
static void		update_player_info( char content, t_map *map, int x, int y);

t_bool	valid_map(t_map *map)
{
	if (valid_map_elements(map->elements) == false
		|| valid_map_contents(map) == false
		|| valid_closed_wall(map) == false
		|| map->start_x == -1 || map->start_y == -1)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

static t_bool	valid_map_elements(char *elements[])
{
	int	i;

	i = 0;
	while (i < NUM_OF_ELEMENT)
	{
		if (!elements[i])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static t_bool	valid_map_contents(t_map *map)
{
	int		h;
	int		w;
	char	**contents;

	h = 0;
	contents = map->contents;
	if (!contents || !*contents)
		return (false);
	while (contents[h])
	{
		if (is_empty_line(contents[h]) == true)
			return (false);
		w = 0;
		while (contents[h][w])
		{
			if (valid_a_content(contents[h][w], map, w, h) == false)
				return (false);
			w++;
		}
		if (w > map->width)
			map->width = w;
		h++;
	}
	map->height = h;
	return (true);
}

static t_bool	valid_a_content(char content, t_map *map, int x, int y)
{
	if (content == '1'
		|| content == '0'
		|| content == ' ')
		return (true);
	else if (
		(content == 'E' || content == 'W' || content == 'S' || content == 'N')
		&& (map->start_x == -1 && map->start_y == -1)
	)
	{
		update_player_info(content, map, x, y);
		return (true);
	}
	else
		return (false);
}

static void	update_player_info( char content, t_map *map, int x, int y)
{
	map->start_x = x;
	map->start_y = y;
	map->start_dir = content;
	map->contents[y][x] = '0';
}
