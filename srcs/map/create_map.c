/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:29 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/12 13:50:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"

t_map		*create_map(char *file);
static void	initialize(t_map **p_map, t_list **p_list);
static void	finalize(t_list **head);

t_map	*create_map(char *file)
{
	t_map	*map;
	t_list	*init_list_4_map;
	t_list	*normalized_list_4_map;

	map = 0;
	init_list_4_map = 0;
	if (valid_extension(file) == false)
		temp_error();
	initialize(&map, &init_list_4_map);
	read_file(&init_list_4_map, file);
	normalized_list_4_map = nomalize_file(init_list_4_map->next);
	parse_map(map, normalized_list_4_map);
	if (valid_map(map) == false)
		temp_error();
	finalize(&init_list_4_map);
	return (map);
}

static void	initialize(t_map **p_map, t_list **p_list)
{
	*p_map = malloc(sizeof(t_map));
	ft_memset(*p_map, 0, sizeof(t_map));
	*p_list = malloc(sizeof(t_list));
	ft_memset(*p_list, 0, sizeof(t_list));
}

static void	finalize(t_list **head)
{
	ft_lstclear(head, free);
}
