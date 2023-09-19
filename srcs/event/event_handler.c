/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:23:04 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"

int	event_key_hook_handler(int key_code, t_config *config);
int	event_hook_handler(int key_code, t_config *config);

int	event_key_hook_handler(int key_code, t_config *config)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	event_hook_handler(int key_code, t_config *config)
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
		left_event_handler(config);
	else if (key_code == KEY_RIGHT)
		right_event_handler(config);
	return (0);
}
