/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:59:25 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/04 17:58:21 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct t_map;

enum e_ele_id
{
	id_no,
	id_so,
	id_we,
	id_ea,
	id_f,
	id_c
};

typedef struct s_map
{
	char	**contents;
	char	*elements[6];
	int		height;
	int		weight;
	int		start_x;
	int		start_y;
	int		start_dir;
}	t_map;

#endif
