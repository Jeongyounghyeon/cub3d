/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:13:04 by youjeong         ###   ########.fr       */
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
	if (key_code == KEY_ESC)
		window_close(config);
	return (0);
}

int	event_hook_handler(int key_code, t_config *config)
{
	(void)config;
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
