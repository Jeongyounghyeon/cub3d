/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:20:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void			raycasting(t_config *config);
static void		init_data(t_raycasting *rc, t_player *player, int x, int w);
static double	calc_delta_dist(double ray_dir);
static void	init_ray_info(t_raycasting *rc, t_player *player);
static int		get_hit_side(t_raycasting *rc, t_player *player, char **map);

void	raycasting(t_config *config)
{
	int 	x;
	int		side;
	double	perp_wall_dist;
	t_ray	*ray;

	x = 0;
	ray = &(config->rc->ray);
	while (x < config->window->width)
	{
		init_data(config->rc, config->player, x, config->window->width);
		init_ray_info(config->rc, config->player);
		side = get_hit_side(config->rc, config->player, config->window->map);
		if (side == 0)
			perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		else
			perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
		(void)perp_wall_dist;
		//draw(perp_wall_dist, side);
		x++;
	}
	// clear();
}

static void	init_data(t_raycasting *rc, t_player *player, int x, int w)
{
	double	screen_x;

	screen_x = 2 * x / (double)w - 1;
	rc->ray.ray_dir.x = player->dir.x + (rc->screen.x * screen_x);
	rc->ray.ray_dir.y = player->dir.y + (rc->screen.x * screen_x);
	rc->ray.delta_dist.x = calc_delta_dist(rc->ray.ray_dir.x);
	rc->ray.delta_dist.y = calc_delta_dist(rc->ray.ray_dir.y);
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
}

static double	calc_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (fabs(1 / ray_dir));
}

static void	init_ray_info(t_raycasting *rc, t_player *player)
{
	if (rc->ray.ray_dir.x < 0)
	{
		rc->step.x = -1;
		rc->ray.side_dist.x = (player->pos.x - player->map_pos.x) * rc->ray.delta_dist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->ray.side_dist.x = (player->map_pos.x + 1.0 - player->pos.x) * rc->ray.delta_dist.x;
	}
	if (rc->ray.ray_dir.x < 0)
	{
		rc->step.y = -1;
		rc->ray.side_dist.x = (player->pos.y - player->map_pos.y) * rc->ray.delta_dist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->ray.side_dist.x = (player->map_pos.y + 1.0 - player->pos.y) * rc->ray.delta_dist.y;
	}
}

static int	get_hit_side(t_raycasting *rc, t_player *player, char **map)
{
	int	hit;
	int	map_x;
	int	map_y;
	int	side;

	hit = 0;
	map_x = player->map_pos.x;
	map_y = player->map_pos.y;
	while (hit == 0)
	{
		if (rc->ray.side_dist.x < rc->ray.side_dist.y)
		{
			rc->ray.side_dist.x += rc->ray.delta_dist.x;
			map_x += rc->step.x;
			side = 0;
		}
		else
		{
			rc->ray.side_dist.y += rc->ray.delta_dist.y;
			map_y += rc->step.y;
			side = 1;
		}
		if (map[map_y][map_x] > 0)
			hit = 1;
	}
	return (side);
}
