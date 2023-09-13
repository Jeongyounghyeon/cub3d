/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 15:44:14 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "config.h"
# include "map.h"

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
	char	**map;
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

void	window_init(t_config *game, t_map *map);
void	window_setting(t_config *game);
int		window_close(t_config *game);

#endif
