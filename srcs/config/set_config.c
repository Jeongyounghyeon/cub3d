/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:27:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 17:32:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_config(t_config *config, t_map *map)
{
	config->map = map->contents;
	
}