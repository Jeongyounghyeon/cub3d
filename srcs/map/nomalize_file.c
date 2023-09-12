/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomalize_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:53 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/12 12:18:28 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "map.h"
#include "get_next_line.h"
#include "bool.h"

static t_bool	is_empty_line(char *line);
static void		lst_remove(t_list **pre, t_list **curr);

t_list	*nomalize_file(t_list *tmp_lst_4_map)
{
	t_list	*iter;
	t_list	*pre;
	int		not_empty_line_cnt;

	iter = tmp_lst_4_map;
	not_empty_line_cnt = 0;
	while (not_empty_line_cnt <= NUM_OF_ELEMENT && iter)
	{
		if (is_empty_line(iter->content) == true)
			lst_remove(&pre, &iter);
		else
			not_empty_line_cnt++;
		pre = iter;
		iter = iter->next;
	}
	return (tmp_lst_4_map); 
}

static t_bool	is_empty_line(char *line)
{
	char	*empty_signs;
	t_bool	value;

	empty_signs = " ";
	value = false;
	line = ft_strtrim(line, empty_signs);
	if (!line)
		exit (1);
	else if (*line == '\n')
		value = true;
	free(line);
	return (value);
}

static void	lst_remove(t_list **pre, t_list **curr)
{
	t_list	*del;

	(*pre)->next = (*curr)->next;
	del = *curr;
	*curr = *pre;
	ft_lstdelone(del, free);
}
