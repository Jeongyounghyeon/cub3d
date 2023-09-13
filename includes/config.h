/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:42:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "play.h"
# include "render.h"
# include "map.h"

typedef struct s_config		t_config;

/* game data */
typedef struct s_config {
	t_win			*window;
	t_img			*img;
	t_player		*player;
	t_raycasting	*rc;
	char			**map;
}	t_config;

void	window_init(t_config *game, t_map *map);
void	window_setting(t_config *game);
int		window_close(t_config *game);

int		event_key_hook_handler(int key_code, t_config *game);
int		event_hook_handler(int key_code, t_config *game);

void	raycasting(t_config *config);

#endif
