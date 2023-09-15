/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:27:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/15 12:10:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_config(t_config *config, t_map *map)
{
	config->map = map->contents;
	config_img(config, map->elements);
	config_player(&config->player, map);
	config->rc.screen.x = config->player.dir.y;
	config->rc.screen.y = config->player.dir.x * (-FOV);
}