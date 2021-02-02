
#include "cub3D.h"

static void     aux_press(int key, t_cub *cub)
{
    if (key == UP && !cub->vel_v_bool)
    {
        cub->vel_v = VEL_V;
        cub->vel_v_bool = 1;
    }
    if (key == DOWN && !cub->vel_v_bool)
    {
        cub->vel_v = -VEL_V;
        cub->vel_v_bool = 1;
    }
}

int             keypress_hook(int key, void *param)
{
    t_cub   *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == ESC)
            exit(0);
        if (key == LEFT && !cub->vel_h_bool)
        {
            cub->vel_h = 0.02;
            cub->vel_h_bool = 1;
        }
        if (key == RIGHT && !cub->vel_h_bool)
        {
            cub->vel_h = -0.02;
            cub->vel_h_bool = 1;
        }
        aux_press(key, cub);
    }
    return (1);
}