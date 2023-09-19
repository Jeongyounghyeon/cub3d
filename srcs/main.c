/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:25:41 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"

int	rendering(t_config *config)
{
	raycasting(config);
	for (int y = 0; y < WINDOW_HEIGHT; y++)  // 제거 예정
		for (int x = 0; x < WINDOW_WIDTH; x++)
			config->screen_img.data[y * WINDOW_WIDTH + x] = config->window.buf[y][x];

	mlx_put_image_to_window(config->window.mlx, config->window.win, config->screen_img.img, 0, 0);
	return (0);
}

void	initailze(t_config *config)
{
	config->window.mlx = mlx_init();
	config->window.win = mlx_new_window(config->window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	mlx_key_hook(config->window.win, event_key_hook_handler, config);
	mlx_hook(config->window.win, EVENT_KEY_PRESS, 0, &event_hook_handler, config);

	mlx_loop_hook(config->window.mlx, &rendering, config);
}

int	main(int argc, char **argv)
{
	t_config	config;
	
	if (argc != 2)
		return (1);
	set_config(&config, create_map(argv[1]));
	initailze(&config);
	mlx_loop(config.window.mlx);
	return (0);
}
