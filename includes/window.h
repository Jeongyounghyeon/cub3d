/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 16:06:08 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

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
