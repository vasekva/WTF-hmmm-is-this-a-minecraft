#include "./cub3D.h"

int	key_press(int key, t_coords *coords)
{
    if (key == K_W)
    {
        if(coords->world_map[(int)(coords->posX + coords->dirX * coords->moveSpeed)][(int)(coords->posY)] == 0)
            coords->posX += coords->dirX * coords->moveSpeed;
        if(coords->world_map[(int)(coords->posX)][(int)(coords->posY + coords->dirY * coords->moveSpeed)] == 0)
            coords->posY += coords->dirY * coords->moveSpeed;
    }
    if (key == K_S)
    {
        if(coords->world_map[(int)(coords->posX + coords->dirX * coords->moveSpeed)][(int)(coords->posY)] == 0)
            coords->posX -= coords->dirX * coords->moveSpeed;
        if(coords->world_map[(int)(coords->posX)][(int)(coords->posY + coords->dirY * coords->moveSpeed)] == 0)
            coords->posY -= coords->dirY * coords->moveSpeed;
    }
    // if (key == K_D)
    // {
    // 	double oldDirX = dirX;
    // 	coords->dirX = coords-> * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    // 	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    // 	double oldPlaneX = planeX;
    // 	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    // 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    // }
    // if (key == K_A)
    // {
    // 	if(coords->world_map[(int)(coords->posX + coords->dirX * moveSpeed)][(int)(coords->posY)] == 0)
    // 		coords->posX += coords->dirX * moveSpeed;
    // 	if(coords->world_map[(int)(coords->posX)][(int)(coords->posY + coords->dirY * moveSpeed)] == 0)
    // 		coords->posY += coords->dirY * moveSpeed;
    // }
    //TODO ESC
    return (0);
}