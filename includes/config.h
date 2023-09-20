/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/20 19:40:28 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "event.h"
# include "render.h"
# include "map.h"

typedef struct s_config	t_config;

typedef struct s_config {
	t_win			window;
	t_img			screen;
	t_img			textures[4];
	t_player		player;
	t_raycasting	rc;
	char			**map;
}	t_config;

void	set_config(t_config *config, t_map *map);
int		event_handler(int key_code, t_config *config);

int		rendering(t_config *config);
void	raycasting(t_config *config);
void	fill_screen_buffer(t_config *config,
			int x, double per_wall_distance, int side);

#endif
