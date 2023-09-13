/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_event_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 17:21:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	w_event_handler(t_config *config);
void	a_event_handler(t_config *config);
void	s_event_handler(t_config *config);
void	d_event_handler(t_config *config);

void	w_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vector	*dir;

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
	t_vector	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x - dir->x * MOVE_SPEED)] != WALL)
		pos->x -= dir->x * MOVE_SPEED;
	if (map[(int)(pos->y + dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y += dir->y * MOVE_SPEED;
}

void	s_event_handler(t_config *config)
{
	char		**map;
	t_coord		*pos;
	t_vector	*dir;

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
	t_vector	*dir;

	map = config->map;
	pos = &config->player.pos;
	dir = &config->player.dir;
	if (map[(int)pos->y][(int)(pos->x + dir->x * MOVE_SPEED)] != WALL)
		pos->x += dir->x * MOVE_SPEED;
	if (map[(int)(pos->y - dir->y * MOVE_SPEED)][(int)(pos->x)] != WALL)
		pos->y -= dir->y * MOVE_SPEED;
}