#include "cub3D.h"
#include "mlx.h"
#include "X.h"

int     main(int argc, char **argv)
{
    t_cub cub;

    if (argc)
    {
        init_cub3D(&cub);
        mlx_key_hook(cub.env->win, keyrelease_hook, &cub);
        mlx_hook(cub.env->win, KeyPress, KeyPressMask, keypress_hook, &cub);
        mlx_loop_hook(cub.env->mlx, loop_hook, &cub);
        mlx_loop(cub.env->mlx);
    }
    close_mlx(cub.env);
    return (0);
}