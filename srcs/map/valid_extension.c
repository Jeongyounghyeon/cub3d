/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:57:01 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/11 15:34:33 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

#include "bool.h"

t_bool	valid_extension(char *file)
{
	char	*extension;
	char	*cub_file;

	if (file)
	{
		cub_file = ".cub\0";
		extension = ft_strrchr(file, '.');
		if (!extension || ft_strncmp(extension, cub_file, ft_strlen(cub_file) + 1))
			return (false);
		else
			return (true);
	}
	else
	{
		return (false);
	}
}
