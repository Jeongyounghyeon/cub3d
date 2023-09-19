/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:07 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/19 18:28:32 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"

int	rendering(t_config *config)
{
	config->rc.camera.x = config->player.dir.y;
	config->rc.camera.y = config->player.dir.x * (-FOV);
	raycasting(config);
	for (int y = 0; y < WINDOW_HEIGHT; y++)  // 제거 예정
		for (int x = 0; x < WINDOW_WIDTH; x++)
			config->screen.data[y * WINDOW_WIDTH + x] = config->window.buf[y][x];
	mlx_put_image_to_window(config->window.mlx, config->window.win, config->screen.img, 0, 0);
	return (0);
}
