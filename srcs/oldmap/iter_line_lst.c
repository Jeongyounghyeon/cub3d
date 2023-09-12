/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_line_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:36:23 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 14:40:25 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "bool.h"

t_list	*iter_line_lst(t_map *map, t_list *head, void (*func)(t_map *, void *));

t_list	*iter_line_lst(t_map *map, t_list *head, void (*func)(t_map *, void *))
{
	t_list	*iter;

	iter = head->next;
	while (iter)
	{
		func(map, iter->content);
		iter = iter->next;
	}
	return (iter);
}
