/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:09:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 17:12:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "xmem.h"

void	init_config(t_config *config)
{
	config->window = (t_win *)xmalloc(1 * sizeof(t_win));
	config->img = (t_img *)xmalloc(1 * sizeof(t_img));
}