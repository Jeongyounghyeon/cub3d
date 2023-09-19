/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:34:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:03:53 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"
#include "render.h"

// static void	screen_init(t_win *window);

int	window_draw(t_config *config)
{
	raycasting(config);
	draw_image_to_window(config);
	return (0);
}
