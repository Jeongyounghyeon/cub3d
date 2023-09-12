/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 17:01:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "map.h"

typedef struct s_config	t_config;
typedef struct s_win	t_win;
typedef struct s_img	t_img;
typedef struct s_player	t_player;

/* game data */
typedef struct s_config {
	t_win	*window;
	t_img	*img;
}t_config;

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
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

typedef struct s_player
{
	double	x;
	double	y;
	double	direction[2];
}	t_player;

#endif