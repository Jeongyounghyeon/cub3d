/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:01:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 18:09:18 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "map.h"
#include "bool.h"

void	check_leaks(void)
{
	system("leaks PARSE_TESTER");
}

void	ignore_param(int argc, char *args[])
{
	(void)argc;
	(void)args;
}

void	show_map(t_map *map)
{
	int i;

	printf("------------------ELEMENTS------------------\n");
	for (i = 0; i < 6 ; i++)
		printf("%s\n", map->elements[i]);

	printf("------------------CONTENTS------------------\n");
	i = 0;
	while (map->contents[i])
		printf("%s\n", map->contents[i++]);

	printf("--------------------DATA--------------------\n");
	printf("%d\n%d\n(%d, %d), %c\n", map->width, map->height, map->start_x, map->start_y, map->start_dir);
	printf("f: %llu c: %llu\n", map->f_rgb, map->c_rgb);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	ignore_param(argc, argv);
	map = create_map(argv[1]);
	show_map(map);
	//check_leaks();
	return (0);
}

/*t_map	*map;
t_list	*list_map;

map = malloc(sizeof(t_map));
ft_memset(map, 0, sizeof(t_map));
list_map = malloc(sizeof(t_list));
ft_memset(list_map, 0, sizeof(t_list));

valid_extension(argv[1]);
read_file(&list_map, argv[1]);
list_map = nomalize_file(list_map->next);

parse_map(map, list_map);
valid_map(map);
show_map(map);*/
