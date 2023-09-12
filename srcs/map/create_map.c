/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:29 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/11 17:37:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "bool.h"

t_map	create_map(char *file)
{
	t_map	*map;
	t_list	*tmp_lst_4_map;

	valid_extension(file);
	initialize(map, tmp_lst_4_map);
	read_file(&list, file);
	nomalize_file(tmp_lst_4_map);
	parse_map(map);
	valid_map(map);
	finalize(&tmp_lst_4_map);
	return (map);
}

static void	initialize(t_map *map, t_list *list)
{
	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	list = malloc(sizeof(t_list));
	ft_memset(lst, 0, sizeof(t_list));
}


static void	finalize(t_list **head)
{
	ft_lstclear(head, free);
}
