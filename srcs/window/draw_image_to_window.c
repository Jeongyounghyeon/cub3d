/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:29:53 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:05:40 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "window.h"

void	draw_image_to_window(t_win *window, t_img *image)
{
	for (int y = 0; y < WINDOW_HEIGHT; y++)
		for (int x = 0; x < WINDOW_WIDTH; x++)
			image->data[y * WINDOW_WIDTH + x] = window->buf[y][x];

	mlx_put_image_to_window(window->mlx, window->win, image->img, 0, 0);
}
