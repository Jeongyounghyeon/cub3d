/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/20 21:56:09 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

int			event_handler(int key_code, t_config *config);

static void	hr_move_h_event(char **map,
				t_player *player, int new_dir_x, int new_dir_y);
static void	vt_move_event(char **map,
				t_player *player, int new_dir_x, int new_dir_y);
static void	rotate_event(t_config *config, double radian);
static void	rotate_vector(t_vec *vector, double theta);

int	event_handler(int key_code, t_config *config)
{
	if (key_code == KEY_W)
		hr_move_h_event(config->map, &config->player, 1, 1);
	else if (key_code == KEY_S)
		hr_move_h_event(config->map, &config->player, -1, -1);
	else if (key_code == KEY_A)
		vt_move_event(config->map, &config->player, 1, -1);
	else if (key_code == KEY_D)
		vt_move_event(config->map, &config->player, -1, 1);
	else if (key_code == KEY_LEFT)
		rotate_event(config, ROT_SPEED);
	else if (key_code == KEY_RIGHT)
		rotate_event(config, -ROT_SPEED);
	else if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

static void	hr_move_h_event(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	double		dir_x;
	double		dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_y * MOVE_SPEED)] \
			[(int)(pos->x + dir_x * MOVE_SPEED)] != WALL)
	{
		pos->x += dir_x * MOVE_SPEED;
		pos->y += dir_y * MOVE_SPEED;
	}
}

static void	vt_move_event(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	double		dir_x;
	double		dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_x * MOVE_SPEED)] \
	[(int)(pos->x + dir_y * MOVE_SPEED)] != WALL)
	{
		pos->x += dir_y * MOVE_SPEED;
		pos->y += dir_x * MOVE_SPEED;
	}
}

static void	rotate_event(t_config *config, double radian)
{
	rotate_vector(&config->player.dir, radian);
	rotate_vector(&config->rc.camera, radian);
}

static void	rotate_vector(t_vec *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}
