#include "cub3D.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

// void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }
static void		my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			ft_start_game(t_cub3D *cub3D)
{
	cub3D->player->posX = 22, cub3D->player->posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	cub3D->env->img = mlx_new_image(cub3D->env->mlx, 1920, 1080);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);
	int h = 1080;
	int w = 1920;

 	for(int x = 0; x < w; x++)
    {
      	//calculate ray position and direction
      	double cameraX = 2 * x / (double)(w) - 1; //x-coordinate in camera space
      	double rayDirX = dirX + planeX * cameraX;
      	double rayDirY = dirY + planeY * cameraX;
	
    	//which box of the map we're in
    	int mapX = (int)(cub3D->player->posX);
    	int mapY = (int)(cub3D->player->posY);
    	//length of ray from current position to next x or y-side
    	double sideDistX;
    	double sideDistY;
    	 //length of ray from one x or y-side to next x or y-side
    	// Alternative code for deltaDist in case division through zero is not supported
    	double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : ft_abs(1 / rayDirX));
    	double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : ft_abs(1 / rayDirY));
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
    	  if (worldMap[mapX][mapY] > 0) hit = 1;
    	}
		  
    	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    	if (side == 0) perpWallDist = (mapX - cub3D->player->posX + (1 - stepX) / 2) / rayDirX;
    	else           perpWallDist = (mapY - cub3D->player->posY + (1 - stepY) / 2) / rayDirY;
    	//Calculate height of line to draw on screen
    	int lineHeight = (int)(h / perpWallDist);
    	//calculate lowest and highest pixel to fill in current stripe
    	int drawStart = -lineHeight / 2 + h / 2;
    	if	(drawStart < 0)drawStart = 0;
    	int drawEnd = lineHeight / 2 + h / 2;
    	if	(drawEnd >= h)drawEnd = h - 1;
		for (int y = drawStart; y < drawEnd; y++)
		{
			my_mlx_pixel_put(cub3D->mlx_img, x, y, 0x00FFF000);
		}
	}
	
	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
}
