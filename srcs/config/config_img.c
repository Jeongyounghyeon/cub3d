/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:10:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/15 14:18:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"
#include "exception.h"

void		config_img(t_config *config, char	*elements[6]);
static void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
									int *width, int *height);
void	config_img(t_config *config, char	*elements[6])
{
	t_img	*img;
	void	*mlx;

	img = config->img;
	mlx = config->window.mlx;
	img[id_ea].img = ft_mlx_xpm_file_to_image(mlx, elements[id_ea], &img[id_ea].width, &img[id_ea].height);
	img[id_we].img = ft_mlx_xpm_file_to_image(mlx, elements[id_we], &img[id_we].width, &img[id_we].height);
	img[id_no].img = ft_mlx_xpm_file_to_image(mlx, elements[id_no], &img[id_no].width, &img[id_no].height);
	img[id_so].img = ft_mlx_xpm_file_to_image(mlx, elements[id_so], &img[id_so].width, &img[id_so].height);
	
	img[id_ea].data = (int *)mlx_get_data_addr(img[id_ea].img, &img[id_ea].bpp, &img[id_ea].size_line, &img[id_ea].endian);
	img[id_we].data = (int *)mlx_get_data_addr(img[id_we].img, &img[id_we].bpp, &img[id_we].size_line, &img[id_we].endian);
	img[id_no].data = (int *)mlx_get_data_addr(img[id_no].img, &img[id_no].bpp, &img[id_no].size_line, &img[id_no].endian);
	img[id_so].data = (int *)mlx_get_data_addr(img[id_so].img, &img[id_so].bpp, &img[id_so].size_line, &img[id_so].endian);

	for (int y = 0; y < img[id_ea].height; y++)
		for (int x = 0; x < img[id_ea].width; x++)
			img[id_ea].texture[img[id_ea].width * y + x] = img[id_ea].data[img[id_ea].width * y + x];
	
	for (int y = 0; y < img[id_we].height; y++)
		for (int x = 0; x < img[id_we].width; x++)
			img[id_we].texture[img[id_we].width * y + x] = img[id_we].data[img[id_we].width * y + x];
	
	for (int y = 0; y < img[id_no].height; y++)
		for (int x = 0; x < img[id_no].width; x++)
			img[id_no].texture[img[id_no].width * y + x] = img[id_no].data[img[id_no].width * y + x];
	
	for (int y = 0; y < img[id_so].height; y++)
		for (int x = 0; x < img[id_so].width; x++)
			img[id_so].texture[img[id_so].width * y + x] = img[id_so].data[img[id_so].width * y + x];
	
	mlx_destroy_image(config->window.mlx, img[id_ea].img);
	mlx_destroy_image(config->window.mlx, img[id_we].img);
	mlx_destroy_image(config->window.mlx, img[id_no].img);
	mlx_destroy_image(config->window.mlx, img[id_so].img);
}

static void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
									int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (!img)
		exception_handler(err_ele_info_img);
	return (img);
}