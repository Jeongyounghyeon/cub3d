/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 17:10:57 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"

void	initailze(t_config *config)
{
	config->window.mlx = mlx_init();
	config->window.win = mlx_new_window(config->window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	mlx_key_hook(config->window.win, event_key_hook_handler, config);
	mlx_hook(config->window.win, EVENT_KEY_PRESS, 0, &event_hook_handler, config);
}

int	main(int argc, char **argv)
{
	t_config	config;
	
	if (argc != 2)
		return (0); // argument exception
	
	initailze(&config);
	set_config(&config, create_map(argv[1]));
	mlx_loop_hook(config.window.mlx, &window_draw, &config);
	mlx_loop(config.window.mlx);
	return (0);
}
