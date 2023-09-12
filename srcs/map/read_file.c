/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:34:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/11 15:46:32 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libft.h"

#include "map.h"
#include "get_next_line.h"
#include <stdio.h>
void	read_file(t_list **head, char *file)
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
