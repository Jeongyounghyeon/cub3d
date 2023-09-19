/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:02:40 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "window.h"

void	window_init(t_win *window);

void	window_init(t_win *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
}
