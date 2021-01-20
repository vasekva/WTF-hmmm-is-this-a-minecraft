
#include "cub3D.h"
#include <math.h>


static void move_cam_h(float vel, t_cam *cam)
{
    cam->direction += vel;
    if (vel < 0)
    {
        if (cam->direction < 0.)
            cam->direction = mes_princ(cam->direction);
    }
    else
    {
        if (cam->direction > 2. * M_PI)
            cam->direction = mes_princ(cam->direction);
    }
}

static void move_cam_v(int vel, t_cam *cam)
{
    if (cam->direction >= 0. && cam->direction <= M_PI)
        cam->pos.y -= vel * sin(mes_ang(cam->direction));
    else
        cam->pos.y += vel * sin(mes_ang(cam->direction));
    if (cam->direction >= M_PI / 2. && cam->direction <= (3. * M_PI) / 2.)
        cam->pos.x -= vel * cos(mes_ang(cam->direction));
    else
        cam->pos.x += vel * cos(mes_ang(cam->direction));
}    

int     keyrelease_hook(int key, void *param)
{
    t_cub   *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == LEFT || key == RIGHT)
            cub->vel_h_bool = 0;
        if (key == UP || key == DOWN)
            cub->vel_v_bool = 0;
    }
    return (1);
}

// int				loop_hook(void *param)
// {
// 	t_cub	*cub;
// 	t_pos	pos;
// 	t_pos	tmp;

// 	if (param)
// 	{
// 		cub = (t_cub*)param;
// 		tmp.x = cub->cam->pos.x;
// 		tmp.y = cub->cam->pos.y;
// 		if (cub->vel_v_bool)
// 			move_cam_v(cub->vel_v, cub->cam);
// 		if (cub->vel_h_bool)
// 			move_cam_h(cub->vel_h, cub->cam);
// 		pos.x = cub->cam->pos.x / WALL_W;
// 		pos.y = cub->cam->pos.y / WALL_H;
// 		if (cub->map[pos.y][pos.x] == WALL)
// 		{
// 			cub->cam->pos.x = tmp.x;
// 			cub->cam->pos.y = tmp.y;
// 		}
// 		else
// 			(cub->map)[pos.y][pos.x] = VOID;
// 		raycaster(cub, cub->cam, cub->map);
// 	}
// 	return (0);
// }

int     loop_hook(void *param)
{
    t_cub   *cub;
    t_pos   pos;
    t_pos   tmp;

    if (param)
    {
        cub = (t_cub *)param;
        tmp.x = cub->cam->pos.x;
        tmp.y = cub->cam->pos.y;
        if (cub->vel_v_bool)
            move_cam_v(cub->vel_v, cub->cam);
        if (cub->vel_h_bool)
            move_cam_h(cub->vel_h, cub->cam);
        pos.x = cub->cam->pos.x / WALL_W;
        pos.y = cub->cam->pos.y / WALL_H;
        if (cub->map[pos.y][pos.x] == WALL)
        {
            cub->cam->pos.x = tmp.x;
            cub->cam->pos.y = tmp.y;
        }
        else
            (cub->map)[pos.y][pos.x] = VOID;
        raycaster(cub, cub->cam, cub->map);
    }
    return (0);
}
