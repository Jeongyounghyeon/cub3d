/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/05 17:18:07 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"
#include "exception.h"

void	initailze(t_config *config)
{
	config->window.mlx = mlx_init();
	if (config->window.mlx == 0)
		exception_handler(err_general);
	config->window.win = mlx_new_window(config->window.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (config->window.win == 0)
		exception_handler(err_general);
	mlx_hook(config->window.win, EVENT_KEY_PRESS, 0, \
				&press_event_handler, &config->key);
	mlx_hook(config->window.win, EVENT_KEY_RELEASE, 0, \
				&release_event_handler, &config->key);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_map		*map;

	if (argc != 2)
		exception_handler(err_arg);
	initailze(&config);
	map = create_map(argv[1]);
	set_config(&config, map);
	mlx_loop_hook(config.window.mlx, &rendering, &config);
	mlx_loop(config.window.mlx);
	return (0);
}
