#include "cub3DD.h"
#include "mlx.h"

static void pixel_put_img(t_cub *cub, int x, int y, t_color *col)
{
    t_uint  size;
    char    *image;

    if (!cub)
         printf("PIXEL PUT CUB error"); //TODO сделать вывод ошибок
    image = cub->img;
    if (col && image)
    {
        size = cub->lay.line;
        if (size > 0 && x < WIDTH * 4)
        {
            image[(y * (size)) + x + 0] = col->b;
            image[(y * (size)) + x + 1] = col->g;
            image[(y * (size)) + x + 2] = col->r;
            image[(y * (size)) + x + 3] = col->alpha;
        }
    }
}

void    draw_img(t_cub *cub, t_cam *cam, t_ray ray)
{
    int     lim;

    lim = (HEIGHT - (t_uint)cam->virtual_h) / 2;
    cam->j = lim;
    cub->img = (char *)cub->env->img;
    cub->img = mlx_get_data_addr(cub->env->img, &(cub->lay.bpp),
        &(cub->lay.line), &(cub->lay.endian));
    ray = ray;
    while (cam->j)
    {
        pixel_put_img(cub, cam->i, (cam->j)--, cub->col_sky);
        low_light(cub->col_sky, (unsigned int)1, 1);
    }
    cam->j = lim;
    while (cam->j < (t_uint)((float)lim + cam->virtual_h))
        pixel_put_img(cub, cam->i, (cam->j)++, cub->col_wl);
    while (cam->j < HEIGHT)
    {
        pixel_put_img(cub, cam->i, (cam->j)++, cub->col_gb);
        low_light(cub->col_gb, (unsigned int)1, 1);
    }
    (cam->i) += 4;
}

static void aux_low_light(t_color *color, t_uint inc)
{
    if ((int)color->r - (int)inc > 0)
        color->r -= inc;
    else
        color->r = 0;
    if ((int)color->g - (int)inc > 0)
        color->g -= inc;
    else
        color->g = 0;
    if ((int)color->b - (int)inc > 0)
        color->b -= inc;
    else
        color->b = 0;  
}

t_uint      rgb_to_color(t_uint r, t_uint g, t_uint b)
{
    unsigned int color;

    color = 0;
    r = (r << 8 * 2);
    g = (g << 8);
    color = r | g | b;
    return (color);
}

void        low_light(t_color *color, unsigned int inc, int sign)
{
    if (color)
    {
        if (sign > 0)
        {
            if ((int)color->r + (int)inc < 256)
                color->r += inc;
            else
                color->r = 255;
            if ((int)color->g + (int)inc < 256)
                color->g += inc;
            else
                color->g = 255;
            if ((int)color->b+ (int)inc < 256)
                color->b += inc;
            else
                color->b = 255;
        }
        else
            aux_low_light(color, inc);
        color->color = rgb_to_color(color->r, color->g, color->b);
    }
}

void        set_color(t_color *col)
{
    if (col)
    {
        col->r = (col->color & MASK_R) >> (8 * 2);
        col->g = (col->color & MASK_G) >> 8;
        col->b = (col->color & MASK_B);
        col->alpha = 0;
    }
}

static void aux_caster(t_cub *cub, t_cam *cam)
{
	int		lost_l;

	lost_l = 0;
	if (cam->virtual_h > HEIGHT)
		cam->virtual_h = HEIGHT;
	lost_l = (int)(((int)G_LIGHT * (int)(cub->ray.v_len)) / (int)U_LONG);
	set_color(cub->col_wl);
	low_light(cub->col_wl, (t_uint)lost_l, -1);
	cub->col_gb->color = COL_GD;
	set_color(cub->col_gb);
	cub->col_sky->color = COL_SKY;
	set_color(cub->col_sky);
	draw_img(cub, cam, cub->ray);
}

static void		aux_get_vlen(t_cub *cub, float len_x, float len_y, t_ray *ray)
{
	if (len_x <= len_y)
	{
		ray->len = len_x;
		cub->col_wl->color = ray->col_h;
	}
	else
	{
		ray->len = len_y;
		cub->col_wl->color = ray->col_v;
	}
}

void    map_pos_vert(t_cam *cam, t_ray *ray, t_pos *pos, t_uint w)
{
    float   h;

    h = sqrt(pow(ray->len, 2) - pow(w, 2));
    if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
    {
        if (((int)(cam->pos.x - w) % WALL_W) == 0)
            pos->x = -1 + (cam->pos.x - w) / WALL_W;
        else
            pos->x = (cam->pos.x - w) / WALL_W;
        ray->col_v = COL_O;
    }
    else
    {
        pos->x = (cam->pos.x + w) / WALL_W;
        ray->col_v = COL_E;
    }
    if (ray->direction > 0. && ray->direction < M_PI)
    {
        if (((int)(cam->pos.y - h) % WALL_H) == 0)
            pos->y = -1 + (cam->pos.y - h) / WALL_H;
        else
            pos->y = (cam->pos.y - h) / WALL_H;
    }
    else
        pos->y = (cam->pos.y + h) / WALL_H;
}

float   inter_vert(t_cam *cam, t_ray *ray, char **map)
{
    t_uint  w;
    t_pos   pos;
    float   port_2;

    if ((int)DEG(ray->direction) == (int)DEG(M_PI / 2.)
            || (int)DEG(ray->direction) == (int)DEG((3. * M_PI) / 2.))
        return (0);
    if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
        w = cam->pos.x % WALL_W;
    else
        w = WALL_W - (cam->pos.x % WALL_W);
    ray->len = (float)w / cos(mes_ang(ray->direction));
    map_pos_vert(cam, ray, &pos, w);
    port_2 = (float)WALL_W / cos(mes_ang(ray->direction));
    while (!((pos.y > MAP_H || pos.x > MAP_W || pos.x < 0)
                || (pos.y < 0 || (map[pos.y][pos.x] == '1'))))
    {
        ray->len += port_2;
        w += WALL_W;
        map_pos_vert(cam, ray, &pos, w);
    }
    return (ray->len);
}

void    map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h)
{
    float   w;

    w = sqrt(pow(ray->len, 2) - pow(h, 2));
    if (ray->direction > 0. && ray->direction < M_PI)
    {
        if (((int)(cam->pos.y - h) % WALL_H) == 0)
            pos->y = -1 + (cam->pos.y - h) / WALL_H;
        else
            pos->y = (cam->pos.y - h) / WALL_H;
        ray->col_h = COL_S;
    }
    else
    {
        ray->col_h = COL_N;
        pos->y = (cam->pos.y + h) / WALL_H;
    }
    if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
    {
        if (((int)(cam->pos.x - w) % WALL_W) == 0)
            pos->x = -1 + (cam->pos.x - w) / WALL_W;
        else
            pos->x = (cam->pos.x - w) / WALL_W;
    }
    else
        pos->x = (cam->pos.x + w) / WALL_W;
}

float   inter_hor(t_cam *cam, t_ray *ray, char **map)
{
    t_uint  h;
    t_pos   pos;
    float   port_2;

    if ((int)DEG(ray->direction) == (int)DEG(M_PI)
            || (int)DEG(ray->direction) == 0
            || (int)DEG(ray->direction) == (int)DEG(2. * M_PI))
        return (0);
    if (ray->direction > 0. && ray->direction < M_PI)
        h = cam->pos.y % WALL_H;
    else
        h = WALL_H - (cam->pos.y % WALL_H);
    ray->len = (float)h / sin(mes_ang(ray->direction));
    map_pos_hor(cam, ray, &pos, h);
    port_2 = (float)WALL_H / sin(mes_ang(ray->direction));
    while (!((pos.y > MAP_H || pos.x > MAP_W || pos.x < 0)
                || (pos.y < 0 || (map[pos.y][pos.x] == '1'))))
    {
        ray->len += port_2;
        h += WALL_H;
        map_pos_hor(cam, ray, &pos, h);
    }
    return (ray->len);
}
/*
** Тут тоже пара функций сверху
*/
static void    get_vlen(t_cam *cam, t_ray *ray, char **map, t_cub *cub)
{
	float   len_x;
	float   len_y;

	len_x = inter_hor(cam, ray, map);
	len_y = inter_vert(cam, ray, map);
	if (len_x == 0 && len_y != 0)
	{
		ray->len = len_y;
		cub->col_wl->color = ray->col_v;
	}
	else if (len_y == 0 && len_x != 0)
	{
		ray->len = len_x;
		cub->col_wl->color = ray->col_h;
	}
	else
		aux_get_vlen(cub, len_x, len_y, ray);
}

void    init_ray(t_ray *ray, float dir)
{
    ray->len = 0;
    ray->v_len = 0;
    ray->direction = dir;
}
/*
** Разветвления 
*/
void        raycaster(t_cub *cub, t_cam *cam, char **map)
{
	float   ang_strt;
	float   ang_end;
	float   inc;

	cam->i = 0;
	cub->env->img = mlx_new_image(cub->env->mlx, WIDTH, HEIGHT);
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&(cub->ray), mes_princ(ang_strt));
		get_vlen(cam, &(cub->ray), map, cub);
		cub->ray.v_len = cub->ray.len *
			(float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj
			* (HEIGHT / 2)) / cub->ray.v_len;
		aux_caster(cub, cam);
		ang_strt -= inc;
	}
	mlx_put_image_to_window(cub->env->mlx, 
		cub->env->win, cub->env->img, 0, 0);
	mlx_destroy_image(cub->env->mlx, cub->env->img);
}

float   mes_princ(float ang)
{
	if (ang < 0.)
		return ((2. * 3.1416) + ang);
	else if (ang > 2. * 3.1416)
		return (ang - 2. * 3.1416);
	return (ang);
}

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

float   mes_ang(float	ang)
{
    if (ang > 0. && ang < M_PI / 2.)
        return (ang);
    if (ang >= M_PI / 2. && ang <= M_PI)
        return (M_PI - ang);
    if (ang > M_PI && ang < (3. * M_PI) / 2.)
        return (ang - M_PI);
    if (ang >= (3. * M_PI) / 2. && ang <= 2. * M_PI)
        return ((2. * M_PI) - ang);
    return (0);
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

t_color *init_color(t_color *color, unsigned int col)
{
    if (!color)
        color = (t_color *)malloc(sizeof(t_color));
    color->color = col;
    color->r = (col & MASK_R) >> (8 * 2);
    color->g = (col & MASK_G) >> 8;
    color->b = (col & MASK_B);
    color->alpha = 0;
    return (color);
}

t_obj   *init_wall(t_obj *wall)
{
    if (!wall)
        wall = malloc(sizeof(t_obj));
    wall->h = WALL_H;
    wall->w = WALL_W;
    wall->type = WALL;
    wall->text = 0;
    return (wall);
}

t_screen    *init_screen(t_screen *screen)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
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
        cam = (t_cam *)malloc(sizeof(t_cam));
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
        env = malloc(sizeof(t_env));
    env->win = NULL;
    env->win = NULL;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "cub3D");
    return (env);
}

t_cub   *init_cub3D(t_cub *cub)
{
    cub->env = init_env(NULL);
    cub->cam = init_cam(NULL);
    cub->screen = init_screen(NULL);
    cub->wall = init_wall(NULL);
    cub->map = get_map();
    cub->vel_h = 0;
    cub->vel_v = 0;
    cub->vel_v_bool = 0;
    cub->vel_h_bool = 0;
    cub->col_sky = init_color(NULL, 0x00FCFF);
    cub->col_gb = init_color(NULL, 0x007482);
    cub->col_wl = init_color(NULL, COL_N);
    cub->col_sky = init_color(NULL, 0xFFFFFF);
    cub->col_gb = init_color(NULL, 0xFFFFFF);
    cub->col_wl = init_color(NULL, 0xFFFFFF);
    cub->shad = ((WIDTH / 2) / 256);
    cub->i_shad = 0;
    cub->i_light = 0;
    return (cub);
}

void        close_mlx(t_env *env)
{
    mlx_destroy_window(env->mlx, env->win);
}

int     main(int argc, char **argv)
{
    t_cub cub;

    if (argc)
    {
        init_cub3D(&cub);
        mlx_key_hook(cub.env->win, keyrelease_hook, &cub);
        mlx_hook(cub.env->win, 2, 1L<<0, keypress_hook, &cub);
        mlx_loop_hook(cub.env->mlx, loop_hook, &cub);
        mlx_loop(cub.env->mlx);
    }
    close_mlx(cub.env);
    return (0);
}