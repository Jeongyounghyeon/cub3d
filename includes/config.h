/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 15:10:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "play.h"
# include "render.h"
# include "map.h"

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

typedef struct s_config	t_config;

/* config data */
typedef struct s_config {
	t_win			window;
	t_img			screen_img;
	t_img			img[4];
	t_player		player;
	t_raycasting	rc;
	char			**map;
}	t_config;

void	set_config(t_config *config, t_map *map);
void	config_img(t_config *config, char	*elements[6]);
void	config_player(t_player *player, t_map *map);


void	window_init(t_config *config);
void	window_setting(t_config *config);
void	window_draw_one_line(t_win *window, int x, int y[2], int color);
void	draw_image_to_window(t_config *config);

int		event_key_hook_handler(int key_code, t_config *config);
int		event_hook_handler(int key_code, t_config *config);
void	w_event_handler(t_config *config);
void	a_event_handler(t_config *config);
void	s_event_handler(t_config *config);
void	d_event_handler(t_config *config);
void	left_event_handler(t_config *config);
void	right_event_handler(t_config *config);

int		event_key_hook_handler(int key_code, t_config *game);
int		event_hook_handler(int key_code, t_config *game);

int		window_draw(t_config *config);
void	raycasting(t_config *config);
void	calc_and_draw_one_line(t_config *config, int x, double per_wall_distance);
void	calc_and_put_window_image(t_config *config, int x, double per_wall_distance, int side);

#endif
