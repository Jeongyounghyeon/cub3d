/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 19:25:30 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

int			event_handler(int key_code, t_config *config);

void		left_event_handler(t_config *config);
void		right_event_handler(t_config *config);
static void	rotate_vector(t_vec *vector, double theta);
void	w_event_handler(t_config *config);
void	a_event_handler(t_config *config);
void	s_event_handler(t_config *config);
void	d_event_handler(t_config *config);

/*static void	vt_move_event(char **map, t_player *player, int new_dir_x, int new_dir_y);
static void	hr_move_h_event(char **map, t_player *player, int new_dir_x, int new_dir_y);
static void	rotate_event(t_vec *vector, double theta);*/

int	event_handler(int key_code, t_config *config)
{
	if (key_code == KEY_W)
		w_event_handler(config);
	else if (key_code == KEY_A)
		a_event_handler(config);
	else if (key_code == KEY_S)
		s_event_handler(config);
	else if (key_code == KEY_D)
		d_event_handler(config);
	else if (key_code == KEY_LEFT)
	{
		left_event_handler(config);
		//rotate_event(&config->rc.camera, ROT_SPEED);
	}
	else if (key_code == KEY_RIGHT)
	{
		right_event_handler(config);
		//rotate_event(&config->rc.camera, -ROT_SPEED);
	}
	else if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

/*static void	hr_move_h_event(char **map, t_player *player, int new_dir_x, int new_dir_y)
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

static void	vt_move_event(char **map, t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	int			dir_x;
	int			dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)pos->y][(int)(pos->x + dir_x * MOVE_SPEED)] != WALL)
		pos->x += dir_y * MOVE_SPEED;
	if (map[(int)(pos->y + dir_y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y += dir_x * MOVE_SPEED;
}

static void	rotate_event(t_vec *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}*/


void	left_event_handler(t_config *config)
{
	rotate_vector(&config->player.dir, ROT_SPEED);
	rotate_vector(&config->rc.camera, ROT_SPEED);
}

void	right_event_handler(t_config *config)
{
	rotate_vector(&config->player.dir, -ROT_SPEED);
	rotate_vector(&config->rc.camera, -ROT_SPEED);
}

static void	rotate_vector(t_vec *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}

void	w_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vec	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x + dir->x * MOVE_SPEED)] != WALL)
		pos->x += dir->x * MOVE_SPEED;
	if (map[(int)(pos->y + dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y += dir->y * MOVE_SPEED;
}

void	a_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vec	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x - dir->x * MOVE_SPEED)] != WALL)
		pos->x -= dir->y * MOVE_SPEED;
	if (map[(int)(pos->y + dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y += dir->x * MOVE_SPEED;
}

void	s_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vec	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x - dir->x * MOVE_SPEED)] != WALL)
		pos->x -= dir->x * MOVE_SPEED;
	if (map[(int)(pos->y - dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y -= dir->y * MOVE_SPEED;
}

void	d_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vec	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x + dir->x * MOVE_SPEED)] != WALL)
		pos->x += dir->y * MOVE_SPEED;
	if (map[(int)(pos->y - dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y -= dir->x * MOVE_SPEED;
}
