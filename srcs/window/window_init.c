/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:02:39 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "config.h"
#include "window.h"
#include "play.h"

void	window_init(t_config *game, t_map *map);

void	window_init(t_config *game, t_map *map)
{
	(void)map;
	game->window->mlx = mlx_init();
	game->window->win = mlx_new_window(game->window->mlx, 1294, 800, "cub3d");
	window_setting(game);
}
