/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 16:35:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config.h"
#include "window.h"
#include "mlx.h"
#include "event.h"

void	window_init(t_config *game, t_map *map);

void	window_init(t_config *game, t_map *map)
{
	(void)map;
	game->window->mlx = mlx_init();
	game->window->win = mlx_new_window(game->window->mlx, 1294, 800, "cub3d");
	window_setting(game);
}