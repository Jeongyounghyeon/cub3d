/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/19 18:40:28 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void			raycasting(t_config *config);
static void		init_data(t_raycasting *rc, t_player *player, int x, int w);
static double	calc_delta_dist(double ray_dir);
static void		init_ray_info(t_raycasting *rc, t_player *player);
static int		get_hit_side(t_raycasting *rc, t_player *player, char **map);

void	raycasting(t_config *config)
{
	int 			x;
	int				side;
	double			perp_wall_dist;
	t_raycasting	*rc;
	t_player		*player;

	x = 0;
	rc = &config->rc;
	player = &config->player;
	while (x < WINDOW_WIDTH)
	{
		init_data(rc, player, x, WINDOW_WIDTH);
		init_ray_info(rc, player);
		side = get_hit_side(rc, player, config->map);
		if (side == 0)
			 perp_wall_dist = rc->ray.side_dist.x - rc->ray.delta_dist.x;
		else
			perp_wall_dist = rc->ray.side_dist.y - rc->ray.delta_dist.y;
		calc_and_put_window_image(config, x, perp_wall_dist, side);
		x++;
	}
}

static void	init_data(t_raycasting *rc, t_player *player, int x, int w)
{
	double	camera_x;

	camera_x = 2 * x / (double)w - 1;
	rc->ray.ray_dir.x = player->dir.x + (rc->camera.x * camera_x);
	rc->ray.ray_dir.y = player->dir.y + (rc->camera.y * camera_x);
	rc->ray.delta_dist.x = calc_delta_dist(rc->ray.ray_dir.x);
	rc->ray.delta_dist.y = calc_delta_dist(rc->ray.ray_dir.y);
	player->int_pos.x = (int)player->pos.x;
	player->int_pos.y = (int)player->pos.y;
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
		rc->ray.step.x = -1;
		rc->ray.side_dist.x = (player->pos.x - player->int_pos.x) * rc->ray.delta_dist.x;
	}
	else
	{
		rc->ray.step.x = 1;
		rc->ray.side_dist.x = (player->int_pos.x + 1.0 - player->pos.x) * rc->ray.delta_dist.x;
	}
	if (rc->ray.ray_dir.y < 0)
	{
		rc->ray.step.y = -1;
		rc->ray.side_dist.y = (player->pos.y - player->int_pos.y) * rc->ray.delta_dist.y;
	}
	else
	{
		rc->ray.step.y = 1;
		rc->ray.side_dist.y = (player->int_pos.y + 1.0 - player->pos.y) * rc->ray.delta_dist.y;
	}
}

static int	get_hit_side(t_raycasting *rc, t_player *player, char **map)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (rc->ray.side_dist.x < rc->ray.side_dist.y)
		{
			rc->ray.side_dist.x += rc->ray.delta_dist.x;
			player->int_pos.x += rc->ray.step.x;
			side = 0;
		}
		else
		{
			rc->ray.side_dist.y += rc->ray.delta_dist.y;
			player->int_pos.y += rc->ray.step.y;
			side = 1;
		}
		if (map[(int)player->int_pos.y][(int)player->int_pos.x] == WALL)
			hit = 1;
	}
	return (side);
}
