/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_contents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:25:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 15:11:54 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#include "map.h"
#include "bool.h"

void			create_map_contents(t_map *map, t_list *head);
static void		initialize(t_map *map);
static void		make_a_contents_line(t_map *map, char *line);
static t_bool	validation_content(char content);
static t_bool	validation_player(char content, t_map *map, int x, int y);

void	create_map_contents(t_map *map, t_list *head)
{
	initialize(map);
	iter_line_lst(map, head, make_a_contents_line);
}

static void	initialize(t_map *map)
{
	map->contents = xmalloc(sizeof(char *));
	map->width = -1;
	map->height = 0;
	map->start_x = -1;
	map->start_y = -1;
}

static void	make_a_contents_line(t_map *map, char *line)
{
	int	h;
	int	w;

	w = 0;
	h = map->height;
	while (line[w])
	{
		if (!(validation_content(line[w]) || validation_player(line[w], map, w, h)))
			exit(1);
		w++;
	}
	map->contents[h++] = ft_strdup(line);
	if (w > map->width)
		map->width = w;
}

static t_bool	validation_content(char content)
{
	if (content == '1'
		|| content == '0'
		|| content == ' ')
		return (true);
	else
		return (false);
}

static t_bool	validation_player(char content, t_map *map, int x, int y)
{
	if ((content == 'E' || content == 'W'
			|| content == 'S' || content == 'N')
			&& (map->start_x == -1 && map->start_y == -1))
	{
		map->start_x = x;
		map->start_y = y;
		map->start_dir = content;
		return (true);
	}
	else
		return (false);
}
