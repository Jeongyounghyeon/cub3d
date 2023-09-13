/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:07:21 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 15:54:48 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define FOV 0.66

# include "coordinate.h"

typedef struct s_ray
{
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
}	t_ray;

typedef	struct s_raycasting
{
	t_vector	screen;
	t_ray		ray;
	t_coord		step;
}	t_raycasting;


#endif
