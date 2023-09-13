/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:40:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:13:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"

#include "config.h"
#include "window.h"
#include "play.h"

void	window_setting(t_config *config)
{
	mlx_key_hook(config->window->win, event_key_hook_handler, config);
	mlx_hook(config->window->win, EVENT_KEY_PRESS, 0, &event_hook_handler, &config);
	mlx_hook(config->window->win, EVENT_KEY_EXIT, 0, &window_close, &config);
}
