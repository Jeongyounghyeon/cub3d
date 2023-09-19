/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:29:53 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/16 12:48:00 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"

void	draw_image_to_window(t_config *config)
{
	for (int y = 0; y < WINDOW_HEIGHT; y++)
		for (int x = 0; x < WINDOW_WIDTH; x++)
			config->screen_img.data[y * WINDOW_WIDTH + x] = config->window.buf[y][x];

	mlx_put_image_to_window(config->window.mlx, config->window.win, config->screen_img.img, 0, 0);
}