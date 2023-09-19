/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/19 15:09:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_win	t_win;
typedef struct s_img	t_img;

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		buf[480][640];
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
	int		texture[64 * 64];
}t_img;

#endif
