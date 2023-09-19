/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:21:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 16:59:01 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include "system.h"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_FORWARD 		126
# define KEY_BACKWARD		125
# define KEY_ESC			53

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_EXIT		17

# define MOVE_SPEED			0.05
# define ROT_SPEED			0.05

# define WALL				'1'

typedef struct s_player
{
	t_coord		pos;
	t_vec		dir;
	t_coord		int_pos;
}	t_player;


#endif
