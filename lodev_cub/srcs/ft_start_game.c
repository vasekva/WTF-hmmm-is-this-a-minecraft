#include "cub3D.h"

#define texWidth 64
#define texHeight 64

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

void			ft_start_game(t_cub3D *cub3D)
{
	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);

 	for(int x = 0; x < cub3D->screen->w; x++)
    {
      	//calculate ray position and direction
      	double cameraX = 2 * x / (double)(cub3D->screen->w) - 1; //x-coordinate in camera space
      	double rayDirX = cub3D->player->dirX + cub3D->player->planeX * cameraX;
      	double rayDirY = cub3D->player->dirY + cub3D->player->planeY * cameraX;
	
    	//which box of the map we're in
    	int mapX = (int)(cub3D->player->posX);
    	int mapY = (int)(cub3D->player->posY);
    	//length of ray from current position to next x or y-side
    	double sideDistX;
    	double sideDistY;
    	 //length of ray from one x or y-side to next x or y-side
    	// Alternative code for deltaDist in case division through zero is not supported
		double	deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double	deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
    	double perpWallDist;
    	//what direction to step in x or y-direction (either +1 or -1)
    	int stepX;
    	int stepY;
    	int hit = 0; //was there a wall hit?
    	int side; //was a NS or a EW wall hit?
    	//calculate step and initial sideDist
    	if (rayDirX < 0)
    	{
    	  stepX = -1;
    	  sideDistX = (cub3D->player->posX - mapX) * deltaDistX;
    	}
    	else
    	{
    	  stepX = 1;
    	  sideDistX = (mapX + 1.0 - cub3D->player->posX) * deltaDistX;
    	}
    	if (rayDirY < 0)
    	{
    	  stepY = -1;
    	  sideDistY = (cub3D->player->posY - mapY) * deltaDistY;
    	}
    	else
    	{
    	  stepY = 1;
    	  sideDistY = (mapY + 1.0 - cub3D->player->posY) * deltaDistY;
    	}
    	//perform DDA
    	while (hit == 0)
    	{
    	  //jump to next map square, OR in x-direction, OR in y-direction
    	  if (sideDistX < sideDistY)
    	  {
    	    sideDistX += deltaDistX;
    	    mapX += stepX;
    	    side = 0;
    	  }
    	  else
    	  {
    	    sideDistY += deltaDistY;
    	    mapY += stepY;
    	    side = 1;
    	  }
    	  //Check if ray has hit a wall
    	  if (cub3D->array->map_arr[mapX][mapY] > '0')
		  	hit = 1;
    	}
		  
    	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    	if (side == 0)
			perpWallDist = (mapX - cub3D->player->posX + (1 - stepX) / 2) / rayDirX;
    	else
			perpWallDist = (mapY - cub3D->player->posY + (1 - stepY) / 2) / rayDirY;
    	//Calculate height of line to draw on screen
    	int lineHeight = (int)(cub3D->screen->h / perpWallDist);
    	//calculate lowest and highest pixel to fill in current stripe
    	int drawStart = -lineHeight / 2 + cub3D->screen->h / 2;
    	if	(drawStart < 0)
			drawStart = 0;
    	int drawEnd = lineHeight / 2 + cub3D->screen->h / 2;
    	if	(drawEnd >= cub3D->screen->h)
			drawEnd = cub3D->screen->h - 1;

		int color;

      	switch(cub3D->array->map_arr[mapX][mapY])
      	{
      	  case '1':  color = 0x00FF0000;  break; //red
      	  case '2':  color = 0x0000FF00;  break; //green
      	  case '3':  color = 0x000000FF;   break; //blue
      	  case '4':  color = 0x00FFFFFF;  break; //white
      	  default: color = 0x00FFFF00; break; //yellow
      	}

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
    		if(cub3D->array->map_arr[(int)(cub3D->player->posX + cub3D->player->dirX * moveSpeed)][(int)(cub3D->player->posY)] == '0')
				cub3D->player->posX += cub3D->player->dirX * moveSpeed;
    		if(cub3D->array->map_arr[(int)(cub3D->player->posX)][(int)(cub3D->player->posY + cub3D->player->dirY * moveSpeed)] == '0')
				cub3D->player->posY += cub3D->player->dirY * moveSpeed;
    	}
    	// //move backwards if no wall behind you
    	if (cub3D->keys->downKey == 1)
    	{
    		if(cub3D->array->map_arr[(int)(cub3D->player->posX - cub3D->player->dirX * moveSpeed)][(int)(cub3D->player->posY)] == '0')
		  		cub3D->player->posX -= cub3D->player->dirX * moveSpeed;
    		if(cub3D->array->map_arr[(int)cub3D->player->posX][(int)(cub3D->player->posY - cub3D->player->dirY * moveSpeed)] == '0')
				cub3D->player->posY -= cub3D->player->dirY * moveSpeed;
    	}
    	//rotate to the right
    	if (cub3D->keys->rightDKey == 1)
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = cub3D->player->dirX;
    	  cub3D->player->dirX = cub3D->player->dirX * cos(-rotSpeed) - cub3D->player->dirY * sin(-rotSpeed);
    	  cub3D->player->dirY = oldDirX * sin(-rotSpeed) + cub3D->player->dirY * cos(-rotSpeed);
    	  double oldPlaneX = cub3D->player->planeX;
    	  cub3D->player->planeX = cub3D->player->planeX * cos(-rotSpeed) - cub3D->player->planeY * sin(-rotSpeed);
    	  cub3D->player->planeY = oldPlaneX * sin(-rotSpeed) + cub3D->player->planeY * cos(-rotSpeed);
    	}
    	// //rotate to the left
    	if (cub3D->keys->leftAKey == 1)
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = cub3D->player->dirX;
    	  cub3D->player->dirX = cub3D->player->dirX * cos(rotSpeed) - cub3D->player->dirY * sin(rotSpeed);
    	  cub3D->player->dirY = oldDirX * sin(rotSpeed) + cub3D->player->dirY * cos(rotSpeed);
    	  double oldPlaneX = cub3D->player->planeX;
    	  cub3D->player->planeX = cub3D->player->planeX * cos(rotSpeed) - cub3D->player->planeY * sin(rotSpeed);
    	  cub3D->player->planeY = oldPlaneX * sin(rotSpeed) + cub3D->player->planeY * cos(rotSpeed);
    	}
	}
	
	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
	
}
