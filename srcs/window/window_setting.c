/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:40:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:02:34 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"

#include "config.h"
#include "window.h"
#include "play.h"

void	window_setting(t_config *game)
{
	mlx_key_hook(game->window->win, event_key_hook_handler, game);
	mlx_hook(game->window->win, EVENT_KEY_PRESS, 0, &event_hook_handler, &game);
	mlx_hook(game->window->win, EVENT_KEY_EXIT, 0, &window_close, &game);
}
