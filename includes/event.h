/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:21:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 16:35:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "config.h"

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

int	event_key_hook_handler(int key_code, t_config *game);
int	event_hook_handler(int key_code, t_config *game);

#endif