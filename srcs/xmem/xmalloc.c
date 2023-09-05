/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:04 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 12:54:41 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*xmalloc(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (temp == 0)
		exit(1);
	return (temp);
}
