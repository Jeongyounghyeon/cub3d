/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:59:25 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/05 14:55:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map	t_map;

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
