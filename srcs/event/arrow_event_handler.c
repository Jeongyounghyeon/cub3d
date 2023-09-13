/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_event_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:00:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 17:49:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void		left_event_handler(t_config *config);
void		right_event_handler(t_config *config);
static void	rotate_vector(t_vector *vector, double theta);

void	left_event_handler(t_config *config)
{
	rotate_vector(&config->player.dir, ROT_SPEED);
	rotate_vector(&config->raycasting.screen, ROT_SPEED);
}

void	right_event_handler(t_config *config)
{
	rotate_vector(&config->player.dir, -ROT_SPEED);
	rotate_vector(&config->raycasting.screen, -ROT_SPEED);
}

static void	rotate_vector(t_vector *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}