/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:10:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/05 18:01:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"

void		config_img(t_config *config, char	*elements[6]);
static void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
										int width, int height);

void	config_img(t_config *config, char	*elements[6])
{
	t_img	*img;
	void	*mlx;

	img = config->img;
	mlx = config->window->mlx;
	img->ceiling = ft_mlx_xpm_file_to_image(mlx, elements[id_c], 64, 64);
	img->floor = ft_mlx_xpm_file_to_image(mlx, elements[id_f], 64, 64);
	img->north = ft_mlx_xpm_file_to_image(mlx, elements[id_no], 64, 64);
	img->south = ft_mlx_xpm_file_to_image(mlx, elements[id_so], 64, 64);
	img->west = ft_mlx_xpm_file_to_image(mlx, elements[id_we], 64, 64);
	img->east = ft_mlx_xpm_file_to_image(mlx, elements[id_ea], 64, 64);
}

void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
								int width, int height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, filename, &width, &height);
	if (!img)
		;	// file exeception
	return (img);
}