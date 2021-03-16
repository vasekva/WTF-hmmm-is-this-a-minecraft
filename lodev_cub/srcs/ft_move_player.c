#include "cub3D.h"

void 		ft_move_player(t_cub3D *cub3d)
{
//		double time = 3; //time of current frame
//  		double oldTime = 2.99; //time of previous frame
	double frameTime = (3 - 2.99) / 1000.0; //frameTime is the time this frame has taken, in seconds
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

	//move forward if no wall in front of you
	if (cub3d->keys->upKey == 1)
	{
		if(cub3d->array->map_arr[(int)(cub3d->player->player_point->posX + cub3d->player->player_point->dirX * moveSpeed)][(int)(cub3d->player->player_point->posY)] == '0')
			cub3d->player->player_point->posX += cub3d->player->player_point->dirX * moveSpeed;
		if(cub3d->array->map_arr[(int)(cub3d->player->player_point->posX)][(int)(cub3d->player->player_point->posY + cub3d->player->player_point->dirY * moveSpeed)] == '0')
			cub3d->player->player_point->posY += cub3d->player->player_point->dirY * moveSpeed;
	}
	// //move backwards if no wall behind you
	if (cub3d->keys->downKey == 1)
	{
		if(cub3d->array->map_arr[(int)(cub3d->player->player_point->posX - cub3d->player->player_point->dirX * moveSpeed)][(int)(cub3d->player->player_point->posY)] == '0')
			cub3d->player->player_point->posX -= cub3d->player->player_point->dirX * moveSpeed;
		if(cub3d->array->map_arr[(int)cub3d->player->player_point->posX][(int)(cub3d->player->player_point->posY - cub3d->player->player_point->dirY * moveSpeed)] == '0')
			cub3d->player->player_point->posY -= cub3d->player->player_point->dirY * moveSpeed;
	}
	//rotate to the right
	if (cub3d->keys->rightDKey == 1)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = cub3d->player->player_point->dirX;
		cub3d->player->player_point->dirX = cub3d->player->player_point->dirX * cos(-rotSpeed) - cub3d->player->player_point->dirY * sin(-rotSpeed);
		cub3d->player->player_point->dirY = oldDirX * sin(-rotSpeed) + cub3d->player->player_point->dirY * cos(-rotSpeed);
		double oldPlaneX = cub3d->player->player_point->planeX;
		cub3d->player->player_point->planeX = cub3d->player->player_point->planeX * cos(-rotSpeed) - cub3d->player->player_point->planeY * sin(-rotSpeed);
		cub3d->player->player_point->planeY = oldPlaneX * sin(-rotSpeed) + cub3d->player->player_point->planeY * cos(-rotSpeed);
	}
	// //rotate to the left
	if (cub3d->keys->leftAKey == 1)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = cub3d->player->player_point->dirX;
		cub3d->player->player_point->dirX = cub3d->player->player_point->dirX * cos(rotSpeed) - cub3d->player->player_point->dirY * sin(rotSpeed);
		cub3d->player->player_point->dirY = oldDirX * sin(rotSpeed) + cub3d->player->player_point->dirY * cos(rotSpeed);
		double oldPlaneX = cub3d->player->player_point->planeX;
		cub3d->player->player_point->planeX = cub3d->player->player_point->planeX * cos(rotSpeed) - cub3d->player->player_point->planeY * sin(rotSpeed);
		cub3d->player->player_point->planeY = oldPlaneX * sin(rotSpeed) + cub3d->player->player_point->planeY * cos(rotSpeed);
	}
}
