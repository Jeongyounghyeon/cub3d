/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw_one_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:42:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 18:52:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"

void	window_draw_one_line(t_win *window, int x, int y[2], int color)
{
	int	iter_y;

	iter_y = y[0];
	while (iter_y <= y[1])
		mlx_pixel_put(window->mlx, window->win, x, iter_y, color);
}