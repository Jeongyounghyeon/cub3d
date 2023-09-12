/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:01:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/11 17:58:16 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

#include "map.h"
#include "bool.h"

void	ignore_param(int argc, char *args[])
{
	(void)argc;
	(void)args;
}

void	show_map(t_list *list)
{
	t_list *iter;

	iter = list;
	while (iter)
	{
		printf("%s", (char *)(iter->content));
		iter = iter->next;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	t_map	*map;
	t_list	*list_map;

	list_map = malloc(sizeof(t_list));
	ft_memset(list_map, 0, sizeof(t_list));
	ignore_param(argc, argv);
	assert(valid_extension(argv[1]) == true);
	read_file(&list_map, argv[1]);
	list_map = nomalize_file(list_map->next);

	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	parse_map(map, list_map);
	printf("------------------ELEMENTS------------------\n");
	for (i = 0; i < 6 ; i++)
		printf("%s\n", map->elements[i]);
	printf("------------------CONTENTS------------------\n");
	i = 0;
	while (map->contents[i])
		printf("%s", map->contents[i++]);
	return (0);
}
