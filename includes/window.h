/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:13:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "config.h"

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
}	t_win;

/* images */
typedef struct s_img {
	void	*ceiling;
	void	*floor;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}t_img;

#endif
