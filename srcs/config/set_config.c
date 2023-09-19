/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:27:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/15 14:25:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/* tmp textures */
#include "mlx.h"

void	set_config(t_config *config, t_map *map)
{
	config->map = map->contents;
	config_img(config, map->elements);
	config_player(&config->player, map);
	config->rc.screen.x = config->player.dir.y;
	config->rc.screen.y = config->player.dir.x * (-FOV);

	config->screen_img.img = mlx_new_image(config->window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	config->screen_img.data = (int *)mlx_get_data_addr(config->screen_img.img, &config->screen_img.bpp, &config->screen_img.size_line, &config->screen_img.endian);

}