/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:56:02 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/12 14:06:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMEM_H
# define XMEM_H

#include <unistd.h>

void	*xmalloc(size_t bytes);
void	free_vector_arr(char **arr);

#endif