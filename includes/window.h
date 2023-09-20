/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/20 19:45:23 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

# define TEXTURE_WIDTH	64
# define TEXTURE_HEIGHT	64

typedef struct s_win	t_win;
typedef struct s_img	t_img;

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		buf[WINDOW_HEIGHT][WINDOW_WIDTH];
}	t_win;

/* images */
typedef struct s_img {
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	int		texture[TEXTURE_HEIGHT * TEXTURE_WIDTH];
}t_img;

#endif
