/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:25:07 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 13:35:05 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libft.h"

#include "map.h"
#include "get_next_line.h"
#include "xmem.h"

t_map		*create_map(char *file);
static void	initialize(t_map *map, t_list *lst);
static void	read_file(t_list **head, char *file);
static void	finalize(t_list **head);

t_map	*create_map(char *file)
{
	t_map	*map;
	t_list	*line_lst;

	initialize(map, line_lst);
	read_file(&line_lst, file);
	finalize(&line_lst);
	return (map);
}

static void	initialize(t_map *map, t_list *lst)
{
	map = xmalloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	lst = xmalloc(sizeof(t_list));
	ft_memset(lst, 0, sizeof(t_list));
}

static void	read_file(t_list **head, char *file)
{
	char	*line;
	int		fd;
	t_list	*new_node;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			new_node = ft_lstnew(line);
			if (!new_node)
				exit(1);
			ft_lstadd_back(head, new_node);
		}
		else
			return ;
	}
}

static void	finalize(t_list **head)
{
	ft_lstclear(head, free);
}
