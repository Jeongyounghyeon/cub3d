/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 15:55:46 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "player.h"
# include "render.h"

typedef struct s_config		t_config;

/* game data */
typedef struct s_config {
	t_win			*window;
	t_img			*img;
	t_player		*player;
	t_raycasting	*raycasting;
}	t_config;

#endif
