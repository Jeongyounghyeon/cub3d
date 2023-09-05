/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:40:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 16:35:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "event.h"
#include "window.h"
#include "mlx.h"

void	window_setting(t_config *game)
{
	mlx_key_hook(game->window->win, event_key_hook_handler, game);
	mlx_hook(game->window->win, EVENT_KEY_PRESS, 0, &event_hook_handler, &game);
	mlx_hook(game->window->win, EVENT_KEY_EXIT, 0, &window_close, &game);
}
