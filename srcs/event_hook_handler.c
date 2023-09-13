/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:02:46 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "play.h"
#include "window.h"

int	event_key_hook_handler(int key_code, t_config *game);
int	event_hook_handler(int key_code, t_config *game);

int	event_key_hook_handler(int key_code, t_config *game)
{
	if (key_code == KEY_ESC)
		window_close(game);
	return (0);
}

int	event_hook_handler(int key_code, t_config *game)
{
	(void)game;
	if (key_code == KEY_W)
		printf("test W\n");
	else if (key_code == KEY_A)
		printf("test A\n");
	else if (key_code == KEY_S)
		printf("test S\n");
	else if (key_code == KEY_D)
		printf("test D\n");
	else if (key_code == KEY_FORWARD)
		printf("test FORWORD\n");
	else if (key_code == KEY_LEFT)
		printf("test LEFT\n");
	else if (key_code == KEY_BACKWARD)
		printf("test BACKWARD\n");
	else if (key_code == KEY_RIGHT)
		printf("test RIGHT\n");
	return (0);
}
