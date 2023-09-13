/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 17:46:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "play.h"
#include "window.h"

int	event_key_hook_handler(int key_code, t_config *config);
int	event_hook_handler(int key_code, t_config *config);

int	event_key_hook_handler(int key_code, t_config *config)
{
	(void)config;
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	event_hook_handler(int key_code, t_config *config)
{
	(void)config;
	if (key_code == KEY_W)
		w_event_handler(config);
	else if (key_code == KEY_A)
		a_event_handler(config);
	else if (key_code == KEY_S)
		s_event_handler(config);
	else if (key_code == KEY_D)
		d_event_handler(config);
	else if (key_code == KEY_LEFT)
		left_event_handler(config);
	else if (key_code == KEY_RIGHT)
		right_event_handler(config);
	return (0);
}
