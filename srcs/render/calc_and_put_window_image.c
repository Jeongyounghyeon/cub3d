/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_put_window_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:47:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:08:20 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void	calc_and_put_window_image(t_config *config, int x, double per_wall_distance, int side)
{
	int	line_height;
	int	draw_range[2];

	line_height = (int)(WINDOW_HEIGHT / per_wall_distance);
	draw_range[0] = (-line_height / 2) + (WINDOW_HEIGHT / 2);
	draw_range[1] = (line_height / 2) + (WINDOW_HEIGHT / 2);
	if (draw_range[0] < 0)
		draw_range[0] = 0;
	if (draw_range[1] >= WINDOW_HEIGHT)
		draw_range[1] = WINDOW_HEIGHT - 1;
	
	double wall_x;
	if (side == 0)
		wall_x = config->player.pos.y + per_wall_distance * config->rc.ray.ray_dir.y;
	else
		wall_x = config->player.pos.x + per_wall_distance * config->rc.ray.ray_dir.x;
	wall_x -= floor(wall_x);

	int tex_x = (int)(wall_x * 64.0);
	if ((side == 0 && config->rc.ray.ray_dir.x > 0) ||
		(side == 1 && config->rc.ray.ray_dir.y < 0))
		tex_x = 64 - tex_x - 1;

	double	step = 1.0 * 64 / line_height;
	double	tex_pos = (draw_range[0] - WINDOW_HEIGHT / 2 + line_height / 2) * step;

	/* init start */
	for (int y = 0; y < WINDOW_HEIGHT / 2; y++) {
		config->window.buf[y][x] = 0xFFFFFF;
		config->window.buf[WINDOW_HEIGHT - y - 1][x] = 0x000000;
	}
	/* init end */

	for (int y = draw_range[0]; y < draw_range[1]; y++) {
		int tex_y = (int)tex_pos & (64 - 1);
		tex_pos += step;
		int color;

		if (side == 0 && config->rc.ray.ray_dir.x >= 0)
			color = config->img[id_we].texture[64 * tex_y + tex_x];
		else if (side == 0 && config->rc.ray.ray_dir.x < 0)
			color = config->img[id_ea].texture[64 * tex_y + tex_x];
		else if (side == 1 && config->rc.ray.ray_dir.y >= 0)
			color = config->img[id_so].texture[64 * tex_y + tex_x];
		else
			color = config->img[id_no].texture[64 * tex_y + tex_x];
		config->window.buf[y][x] = color;
	}
}
