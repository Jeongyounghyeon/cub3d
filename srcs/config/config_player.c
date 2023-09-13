/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:33:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 17:45:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	config_player(t_player *player, t_map *map)
{
	player->pos.x = map->start_x;
	player->pos.y = map->start_y;
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
	if (map->start_dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (map->start_dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (map->start_dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (map->start_dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}