/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:41:25 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 19:14:59 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void		fill_screen_buffer(t_config *config,
				int x, double per_wall_distance, int side);
static void	get_texture_height(int line_height, int *draw_range);
static int	get_tex_x(t_config *config, double per_wall_distance, int side);
static void	fill_screen_buffer_bg(int buf[][WINDOW_WIDTH], int x);
static int	get_color(t_config *config, int tex_y, int tex_x, int side);

void	fill_screen_buffer(t_config *config,
			int x, double per_wall_distance, int side)
{
	int		line_height;
	int		draw_range[2];
	double	step;
	double	tex_pos;
	int		y;

	line_height = (int)(WINDOW_HEIGHT / per_wall_distance);
	get_texture_height(line_height, draw_range);
	step = 1.0 * 64 / line_height;
	tex_pos = (draw_range[0] - WINDOW_HEIGHT / 2 + line_height / 2) * step;
	fill_screen_buffer_bg(config->window.buf, x);
	y = draw_range[0];
	while (y < draw_range[1])
	{
		tex_pos += step;
		config->window.buf[y][x] = get_color(config,
				(int)tex_pos & (64 - 1),
				get_tex_x(config, per_wall_distance, side),
				side);
		y++;
	}
}

static void	get_texture_height(int line_height, int *draw_range)
{
	draw_range[0] = (-line_height / 2) + (WINDOW_HEIGHT / 2);
	draw_range[1] = (line_height / 2) + (WINDOW_HEIGHT / 2);
	if (draw_range[0] < 0)
		draw_range[0] = 0;
	if (draw_range[1] >= WINDOW_HEIGHT)
		draw_range[1] = WINDOW_HEIGHT - 1;
}

static int	get_tex_x(t_config *config, double per_wall_distance, int side)
{
	int		tex_x;
	double	wall_x;

	if (side == 0)
		wall_x = config->player.pos.y
			+ per_wall_distance * config->rc.ray.ray_dir.y;
	else
		wall_x = config->player.pos.x
			+ per_wall_distance * config->rc.ray.ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 64.0);
	if ((side == 0 && config->rc.ray.ray_dir.x > 0)
		|| (side == 1 && config->rc.ray.ray_dir.y < 0))
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

static void	fill_screen_buffer_bg(int buf[][WINDOW_WIDTH], int x)
{
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		buf[y][x] = 0xFFFFFF;
		buf[WINDOW_HEIGHT - y - 1][x] = 0x000000;
		y++;
	}
}

static int	get_color(t_config *config, int tex_y, int tex_x, int side)
{
	int	color;

	if (side == 0 && config->rc.ray.ray_dir.x >= 0)
		color = config->textures[id_we].texture[64 * tex_y + tex_x];
	else if (side == 0 && config->rc.ray.ray_dir.x < 0)
		color = config->textures[id_ea].texture[64 * tex_y + tex_x];
	else if (side == 1 && config->rc.ray.ray_dir.y >= 0)
		color = config->textures[id_so].texture[64 * tex_y + tex_x];
	else
		color = config->textures[id_no].texture[64 * tex_y + tex_x];
	return (color);
}
