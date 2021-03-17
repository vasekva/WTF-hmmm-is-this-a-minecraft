/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:04:54 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/16 15:04:58 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst
		= mlx_img->addr + (y * mlx_img->line_length
			+ x * (mlx_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
