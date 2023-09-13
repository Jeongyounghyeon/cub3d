/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:13:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "play.h"
# include "render.h"
# include "map.h"

typedef struct s_config		t_config;

/* config data */
typedef struct s_config {
	t_win			*window;
	t_img			*img;
	t_player		*player;
	t_raycasting	*raycasting;
}	t_config;

void	window_init(t_config *config, t_map *map);
void	window_setting(t_config *config);
int		window_close(t_config *config);

int	event_key_hook_handler(int key_code, t_config *config);
int	event_hook_handler(int key_code, t_config *config);

#endif
