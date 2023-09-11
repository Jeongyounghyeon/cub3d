/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/11 14:30:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "map.h"
# include "ft_math.h"

typedef struct s_config	t_config;
typedef struct s_win	t_win;
typedef struct s_img	t_img;
typedef struct s_player	t_player;

/* game data */
typedef struct s_config {
	t_win			*window;
	t_img			*img;
	t_raycasting	*raycasting;
}t_config;

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}t_win;

/* images */
typedef struct s_img {
	void	*ceiling;
	void	*floor;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}t_img;

typedef struct s_raycasting {
	t_vector	position;
	t_vector	direction;
	t_vector	screen;
}t_raycasting;

#endif