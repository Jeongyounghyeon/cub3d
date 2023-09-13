/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 14:22:21 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "render.h"

void	algorithm(t_win *win, t_render *render)
{
	char	**map; // param
	int 	x;
	int		side;
	double	perp_wall_dist;

	x = 0;
	while (x < win->width)
	{
		initialize(render, x, w);
		set_step_and_side_dist(render);
		side = hit_check(render, map);
		if (side == 0)
			perp_wall_dist = ray.side_dist.x - ray.delta_dist.x;
		else
			perp_wall_dist = ray.side_dist.y - ray.delta_dist.y;
		//draw(perp_wall_dist, side);
		x++;
	}
	// clear();
}

void	initialize(t_render *render, int x, int w)
{
	double	screen_x;

	screen_x = 2 * x / (double)w - 1;
	render->ray.ray_dir.x = render->dir.x + (render->screen.x * screen_x);
	render->ray.ray_dir.y = render->dir.y + (render->screen.x * screen_x);
	render->ray.delta_dist.x = calc_delta_dist(render->ray.ray_dir.x);
	render->ray.delta_dist.y = calc_delta_dist(render->ray.ray_dir.y);
	render->map_pos.x = (int)render->pos.x;
	render->map_pos.y = (int)render->pos.y;
}

double	calc_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (abs(1 / ray_dir));
}

void	set_step_and_side_dist(t_render *render)
{
	if (render->ray.ray_dir.x < 0)
	{
		render->step.x = -1;
		render->ray.side_dist.x = (render->pos.x - render->map_pos.x) * render->ray.delta_dist.x;
	}
	else
	{
		render->step.x = 1;
		render->ray.side_dist.x = (render->map_pos.x + 1.0 - render->pos.x) * render->ray.delta_dist.x;
	}
	if (render->ray.ray_dir.x < 0)
	{
		render->step.y = -1;
		render->ray.side_dist.x = (render->pos.y - render->map_pos.y) * render->ray.delta_dist.y;
	}
	else
	{
		render->step.y = 1;
		render->ray.side_dist.x = (render->map_pos.y + 1.0 - render->pos.y) * render->ray.delta_dist.y;
	}
}

int	hit_check(t_render *render, char **map)
{
	int	hit;
	int	map_x;
	int	map_y;

	hit = 0;
	map_x = render->map_pos.x;
	map_y = render->map_pos.y;
	while (hit == 0)
	{
		if (render->ray.side_dist.x < render->ray.side_dist.y)
		{
			render->ray.side_dist.x += render->ray.delta_dist.x;
			map_x + render->step.x;
			side = 0;
		}
		else
		{
			render->ray.side_dist.y += render->ray.delta_dist.y;
			map_y + render->step.y;
			side = 1;
		}
		if (map[map_y][map_x] > 0)
			hit = 1;
	}
	return (side);
}
