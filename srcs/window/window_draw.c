/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:34:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/16 12:00:21 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"
#include "render.h"

// static void	screen_init(t_win *window);

int	window_draw(t_config *config)
{
	// screen_init(&config->window);
	raycasting(config);
	draw_image_to_window(config);
	return (0);
}

// static void	screen_init(t_win *window)
// {
// 	for (int y = 0; y < WINDOW_HEIGHT; y++) {
// 		for (int x = 0; x < WINDOW_WIDTH; x++) {
// 			mlx_pixel_put(window->mlx, window->win, x, y, 0xFFFFFF);
// 		}
// 	}
// }