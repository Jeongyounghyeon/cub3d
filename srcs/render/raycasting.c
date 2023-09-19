/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/16 13:16:19 by youjeong         ###   ########.fr       */
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
	int 	x;
	int		side;
	double	perp_wall_dist;
	// t_ray	*ray;

	x = 0;
	// ray = &(config->rc.ray);
	while (x < WINDOW_WIDTH)
	{
		init_data(&config->rc, &config->player, x, WINDOW_WIDTH);
		init_ray_info(&config->rc, &config->player);
		side = get_hit_side(&config->rc, &config->player, config->map);
		if (side == 0)
			perp_wall_dist = (config->player.map_pos.x - config->player.pos.x + (1 - config->rc.step.x) / 2) / config->rc.ray.ray_dir.x;
			// perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		else
			perp_wall_dist = (config->player.map_pos.y - config->player.pos.y + (1 - config->rc.step.y) / 2) / config->rc.ray.ray_dir.y;
			// perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
		calc_and_put_window_image(config, x, perp_wall_dist, side);

		// calc_and_draw_one_line(config, x, perp_wall_dist);
		x++;
	}
	// clear();
}

static void	init_data(t_raycasting *rc, t_player *player, int x, int w)
{
	double	screen_x;

	screen_x = 2 * x / (double)w - 1;
	rc->ray.ray_dir.x = player->dir.x + (rc->screen.x * screen_x);
	rc->ray.ray_dir.y = player->dir.y + (rc->screen.y * screen_x);
	rc->ray.delta_dist.x = calc_delta_dist(rc->ray.ray_dir.x);
	rc->ray.delta_dist.y = calc_delta_dist(rc->ray.ray_dir.y);
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
}

static double	calc_delta_dist(double ray_dir)
{
	// if (ray_dir == 0)
	// 	return (1e30);
	// else
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
	if (rc->ray.ray_dir.y < 0)
	{
		rc->step.y = -1;
		rc->ray.side_dist.y = (player->pos.y - player->map_pos.y) * rc->ray.delta_dist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->ray.side_dist.y = (player->map_pos.y + 1.0 - player->pos.y) * rc->ray.delta_dist.y;
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
			player->map_pos.x += rc->step.x;
			side = 0;
		}
		else
		{
			rc->ray.side_dist.y += rc->ray.delta_dist.y;
			player->map_pos.y += rc->step.y;
			side = 1;
		}
		if (map[(int)player->map_pos.y][(int)player->map_pos.x] == WALL)
			hit = 1;
	}
	return (side);
}
