/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:32 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:29:34 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

static void		my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void 			ft_def_player_dir(t_cub3D *cub3D)
{
	cub3D->player->deltaDistX = sqrt(1 + (cub3D->player->rayDirY
			* cub3D->player->rayDirY) /
					(cub3D->player->rayDirX * cub3D->player->rayDirX));
	cub3D->player->deltaDistY = sqrt(1 + (cub3D->player->rayDirX
			* cub3D->player->rayDirX) /
					(cub3D->player->rayDirY * cub3D->player->rayDirY));
	if (cub3D->player->rayDirX < 0)
	{
		cub3D->player->stepX = -1;
		cub3D->player->sideDistX = (cub3D->player->player_point->posX
			- cub3D->player->mapX) * cub3D->player->deltaDistX;
	}
	else
	{
		cub3D->player->stepX = 1;
		cub3D->player->sideDistX = (cub3D->player->mapX + 1.0
			- cub3D->player->player_point->posX) * cub3D->player->deltaDistX;
	}
	if (cub3D->player->rayDirY < 0)
	{
		cub3D->player->stepY = -1;
		cub3D->player->sideDistY = (cub3D->player->player_point->posY
				- cub3D->player->mapY) * cub3D->player->deltaDistY;
	}
	else
	{
		cub3D->player->stepY = 1;
		cub3D->player->sideDistY = (cub3D->player->mapY + 1.0
				- cub3D->player->player_point->posY) * cub3D->player->deltaDistY;
	}
}

void 			ft_perform_dda(t_cub3D *cub3D)
{
	int hit = 0;
//	int side;


	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (cub3D->player->sideDistX < cub3D->player->sideDistY)
		{
			cub3D->player->sideDistX += cub3D->player->deltaDistX;
			cub3D->player->mapX += cub3D->player->stepX;
			cub3D->player->dda->side = 0;
		}
		else
		{
			cub3D->player->sideDistY += cub3D->player->deltaDistY;
			cub3D->player->mapY += cub3D->player->stepY;
			cub3D->player->dda->side = 1;
		}
		//Check if ray has hit a wall
		if (cub3D->array->map_arr[cub3D->player->mapX][cub3D->player->mapY] > '0')
			hit = 1;
	}
}

void			ft_start_game(t_cub3D *cub3D)
{
	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);

 	for(int x = 0; x < cub3D->screen->w; x++)
    {
		cub3D->player->cameraX = 2 * x / (double)(cub3D->screen->w) - 1;
      	cub3D->player->rayDirX = cub3D->player->player_point->dirX + cub3D->player->player_point->planeX * cub3D->player->cameraX;
		cub3D->player->rayDirY = cub3D->player->player_point->dirY + cub3D->player->player_point->planeY * cub3D->player->cameraX;

    	cub3D->player->mapX = (int)(cub3D->player->player_point->posX);
		cub3D->player->mapY = (int)(cub3D->player->player_point->posY);


    	ft_def_player_dir(cub3D);

    	ft_perform_dda(cub3D);

		if (cub3D->player->dda->side == 0)
			cub3D->player->dda->perpWallDist = (cub3D->player->mapX - cub3D->player->player_point->posX + (1 - cub3D->player->stepX) / 2) / cub3D->player->rayDirX;
		else
			cub3D->player->dda->perpWallDist = (cub3D->player->mapY - cub3D->player->player_point->posY + (1 - cub3D->player->stepY) / 2) / cub3D->player->rayDirY;


    	//Calculate height of line to draw on screen
    	int lineHeight = (int)(cub3D->screen->h / cub3D->player->dda->perpWallDist);
    	//calculate lowest and highest pixel to fill in current stripe
    	int drawStart = -lineHeight / 2 + cub3D->screen->h / 2;
    	if	(drawStart < 0)
			drawStart = 0;
    	int drawEnd = lineHeight / 2 + cub3D->screen->h / 2;
    	if	(drawEnd >= cub3D->screen->h)
			drawEnd = cub3D->screen->h - 1;

		int color;

		color = create_rgb(255, 255, 255);

		for (int y = drawStart; y < drawEnd; y++)
		{
			my_mlx_pixel_put(cub3D->mlx_img, x, y, color);
		}

		double time = 3; //time of current frame
  		double oldTime = 2.99; //time of previous frame
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds	
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

		//move forward if no wall in front of you
    	if (cub3D->keys->upKey == 1)
    	{
    		if(cub3D->array->map_arr[(int)(cub3D->player->player_point->posX + cub3D->player->player_point->dirX * moveSpeed)][(int)(cub3D->player->player_point->posY)] == '0')
				cub3D->player->player_point->posX += cub3D->player->player_point->dirX * moveSpeed;
    		if(cub3D->array->map_arr[(int)(cub3D->player->player_point->posX)][(int)(cub3D->player->player_point->posY + cub3D->player->player_point->dirY * moveSpeed)] == '0')
				cub3D->player->player_point->posY += cub3D->player->player_point->dirY * moveSpeed;
    	}
    	// //move backwards if no wall behind you
    	if (cub3D->keys->downKey == 1)
    	{
    		if(cub3D->array->map_arr[(int)(cub3D->player->player_point->posX - cub3D->player->player_point->dirX * moveSpeed)][(int)(cub3D->player->player_point->posY)] == '0')
		  		cub3D->player->player_point->posX -= cub3D->player->player_point->dirX * moveSpeed;
    		if(cub3D->array->map_arr[(int)cub3D->player->player_point->posX][(int)(cub3D->player->player_point->posY - cub3D->player->player_point->dirY * moveSpeed)] == '0')
				cub3D->player->player_point->posY -= cub3D->player->player_point->dirY * moveSpeed;
    	}
    	//rotate to the right
    	if (cub3D->keys->rightDKey == 1)
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = cub3D->player->player_point->dirX;
    	  cub3D->player->player_point->dirX = cub3D->player->player_point->dirX * cos(-rotSpeed) - cub3D->player->player_point->dirY * sin(-rotSpeed);
    	  cub3D->player->player_point->dirY = oldDirX * sin(-rotSpeed) + cub3D->player->player_point->dirY * cos(-rotSpeed);
    	  double oldPlaneX = cub3D->player->player_point->planeX;
    	  cub3D->player->player_point->planeX = cub3D->player->player_point->planeX * cos(-rotSpeed) - cub3D->player->player_point->planeY * sin(-rotSpeed);
    	  cub3D->player->player_point->planeY = oldPlaneX * sin(-rotSpeed) + cub3D->player->player_point->planeY * cos(-rotSpeed);
    	}
    	// //rotate to the left
    	if (cub3D->keys->leftAKey == 1)
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = cub3D->player->player_point->dirX;
    	  cub3D->player->player_point->dirX = cub3D->player->player_point->dirX * cos(rotSpeed) - cub3D->player->player_point->dirY * sin(rotSpeed);
    	  cub3D->player->player_point->dirY = oldDirX * sin(rotSpeed) + cub3D->player->player_point->dirY * cos(rotSpeed);
    	  double oldPlaneX = cub3D->player->player_point->planeX;
    	  cub3D->player->player_point->planeX = cub3D->player->player_point->planeX * cos(rotSpeed) - cub3D->player->player_point->planeY * sin(rotSpeed);
    	  cub3D->player->player_point->planeY = oldPlaneX * sin(rotSpeed) + cub3D->player->player_point->planeY * cos(rotSpeed);
    	}
	}
	
	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
	
}
