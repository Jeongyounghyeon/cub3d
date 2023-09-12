/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:25:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/12 12:21:56 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#include "map.h"
#include "bool.h"

t_list			*create_map_elements(t_map *map, t_list *head);
static void		make_a_element(t_map *map, char *line);
static t_bool	validation_id(char *line);
static t_bool	validation_rgb(char *rgb);

t_list	*create_map_elements(t_map *map, t_list *head)
{
	return (iter_line_lst(map, head, make_a_element));
}

static void	make_a_element(t_map *map, char *line)
{
	int	h;
	int	w;

	if (!line || !*line)
		return ;
	w = 0;
	h = map->height;
	while (line[w])
	{
		if (!(validation_id(map, line[w]) || validation_rgb(line)))
			exit(1);
		w++;
	}
	map->contents[h++] = line;
	if (w > map->width)
		map->width = w;
}

static t_bool	validation_id(t_map *map, char *line)
{
	int	id;

	id = get_id(line);
	if (!id_invalid)
		return (false);
	else
	{
		map->elements[id] = ft_strdup(get_ele(line));
	}
}

static t_bool	validation_rgb(char *rgb)
{
}

static t_ele_id	get_id(char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		return (id_no);
	else if (!ft_strncmp("SO ", line, 3))
		return (id_so);
	else if (!ft_strncmp("EA ", line, 3))
		return (id_ea);
	else if (!ft_strncmp("WE ", line, 3))
		return (id_we);
	else if (!ft_strncmp("F ", line, 2))
		return (id_f);
	else if (!ft_strncmp("C ", line, 2))
		return (id_c);
	else
		return (id_invalid);
}

static char	*get_ele(char *line)
{
	while (line)
	{
		if (*line == ' ')
			return (line++);
		line++;
	}
	return (0);
}
