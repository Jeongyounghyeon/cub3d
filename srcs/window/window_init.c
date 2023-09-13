/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 19:35:55 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "config.h"
#include "window.h"
#include "play.h"

void	window_init(t_config *config);

void	window_init(t_config *config)
{
	config->window.mlx = mlx_init();
	config->window.win = mlx_new_window(config->window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	window_setting(config);
}
