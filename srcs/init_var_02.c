
# include "cub3D.h"
# include "mlx.h"
# include "math.h"
# include "check_errors.h"

void        close_mlx(t_env *env)
{
    mlx_destroy_window(env->mlx, env->win);
}

t_screen    *init_screen(t_screen *screen)
{
    if (!screen)
        if (!(screen = (t_screen *)malloc(sizeof(t_screen))))
			check_errors(MALLOC, "screen", "init_wolf_var.c");
    screen->h = HEIGHT;
    screen->w = WIDTH;
    screen->center.x = WIDTH / 2;
    screen->center.y = HEIGHT / 2;
    return (screen);
}

t_cam       *init_cam(t_cam *cam)
{
    float tan;

    if (!cam)
        if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
			check_errors(MALLOC, "cam", "init_wolf_var.c");
    cam->champs = CHAMPS;
    cam->direction = START_DIR;
    cam->i = 0;
    cam->j = 0;
    cam->pos.x = ((t_uint)WALL_H * (t_uint)5) + ((t_uint)WALL_W / (t_uint)2);
    cam->pos.y = ((t_uint)WALL_H * (t_uint)4) + ((t_uint)WALL_W / (t_uint)2);
    tan = (float)((float)sin((CHAMPS / 2.0)) / (float)cos((CHAMPS / 2.0)));
    cam->dist_proj = (t_uint)((float)(WIDTH / 2) / tan);
    cam->h_cam = WALL_H / 2;
    return (cam);
}

t_env       *init_env(t_env *env)
{
    if (!env)
        if (!(env = malloc(sizeof(t_env))))
			check_errors(MALLOC, "env", "init_wolf_war.c");
    env->win = NULL;
    env->win = NULL;
    if (!(env->mlx = mlx_init()))
		check_errors(MALLOC, "env->mlx", "init_wolf_var.c");
    if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "cub3D")))
		check_errors(MALLOC, "env->win", "init_wolf_var.c");
    return (env);
}
