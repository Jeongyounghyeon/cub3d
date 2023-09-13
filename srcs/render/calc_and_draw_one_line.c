/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_draw_one_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:53:53 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 20:02:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	calc_and_draw_one_line(t_config *config, int x, double per_wall_distance);

void	calc_and_draw_one_line(t_config *config, int x, double per_wall_distance)
{
	int	line_height;
	int	draw_range[2];
	int	color;

	line_height = (int)(WINDOW_HEIGHT / per_wall_distance);
	draw_range[0] = (-line_height / 2) + (WINDOW_HEIGHT / 2);
	draw_range[1] = (line_height / 2) + (WINDOW_HEIGHT / 2);
	if (draw_range[0] < 0)
		draw_range[0] = 0;
	if (draw_range[1] >= WINDOW_HEIGHT)
		draw_range[1] = WINDOW_HEIGHT - 1;
	if (config->map[(int)config->player.map_pos.y][(int)config->player.map_pos.x] == WALL)
		color = 0xFF0000;
	else
		color = 0xFFFFFF;
	window_draw_one_line(&config->window, x, draw_range, color);
}