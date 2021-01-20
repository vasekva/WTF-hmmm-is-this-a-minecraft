#include "cub3D.h"
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