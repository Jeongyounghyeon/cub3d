/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 19:16:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "config.h"
#include "window.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_config	config;
	
	(void)argv;
	if (argc != 2)
		return (0); // argument exception
	
	set_config(&config, create_map(argv[1]));
	window_init(&config);
	window_setting(&config);
	mlx_loop_hook(config.window.mlx, &window_draw, &config);
	mlx_loop(config.window.mlx);
	return (0);
}
