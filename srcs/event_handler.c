/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 18:40:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

int			event_handler(int key_code, t_config *config);
static void	move_event(char **map, t_player *player, int new_dir_x, int new_dir_y);
static void	rotate_event(t_vec *vector, double theta);

int	event_handler(int key_code, t_config *config)
{
	char		**map;
	t_player	*player;

	map = config->map;
	player = &config->player;
	if (key_code == KEY_W)
		move_event(map, player, 1, 1);
	else if (key_code == KEY_A)
		move_event(map, player, -1, 1);
	else if (key_code == KEY_S)
		move_event(map, player, -1, -1);
	else if (key_code == KEY_D)
		move_event(map, player, 1, -1);
	else if (key_code == KEY_LEFT)
	{
		rotate_event(&config->player.dir, ROT_SPEED);
		rotate_event(&config->rc.camera, ROT_SPEED);
	}
	else if (key_code == KEY_RIGHT)
	{
		rotate_event(&config->player.dir, -ROT_SPEED);
		rotate_event(&config->rc.camera, -ROT_SPEED);
	}
	else if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

static void	move_event(char **map, t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	int			dir_x;
	int			dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)pos->y][(int)(pos->x + dir_x * MOVE_SPEED)] != WALL)
		pos->x += dir_x * MOVE_SPEED;
	if (map[(int)(pos->y + dir_y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y += dir_y * MOVE_SPEED;
}

static void	rotate_event(t_vec *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}
