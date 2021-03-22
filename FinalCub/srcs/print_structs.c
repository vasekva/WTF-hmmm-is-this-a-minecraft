#include "cub3d.h"

void		print_structs(t_cub3d *cub3d)
{

	printf("===============================\n\n");

	for (int i = 0; i < cub3d->map_h; i++)
		printf("%s\n", cub3d->map[i]);

	printf("===============================\n\n");

	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", cub3d->tex[i].texture);
		printf("%d\n", cub3d->tex[i].col);
		printf("%d\n", cub3d->tex[i].color);
		printf("%d\n", cub3d->tex[i].width);
		printf("%s\n", cub3d->tex[i].tex_path);
		printf("%s\n", cub3d->tex[i].image);
		printf("%p\n", cub3d->tex[i].tex_ptr);
		printf("%d\n", cub3d->tex[i].bit_pix);
		printf("%d\n", cub3d->tex[i].size_line);
		printf("%d\n", cub3d->tex[i].endian);
		printf("%d\n", cub3d->tex[i].pix);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}

	printf("===============================\n\n");

	printf("LINE_COUNT: %d\n", cub3d->map_h);
	printf("LINE_LEN: %d\n", cub3d->map_w);

	printf("===============================\n\n");

	printf("%lf\n", cub3d->flr.fl_x_wall);
	printf("%lf\n", cub3d->flr.fl_y_wall);
	printf("%lf\n", cub3d->flr.cur_dist);
	printf("%lf\n", cub3d->flr.weight);
	printf("%lf\n", cub3d->flr.cur_fl_x);
	printf("%lf\n", cub3d->flr.cur_fl_y);
	printf("%d\n", cub3d->flr.fl_tex_x);
	printf("%d\n", cub3d->flr.fl_tex_y);

	printf("===============================\n\n");

	printf("%lf\n", cub3d->pos_x);
	printf("%lf\n", cub3d->pos_y);
	printf("%lf\n", cub3d->dir_x);
	printf("%lf\n", cub3d->dir_y);
	
	printf("%lf\n", cub3d->plane_x);
	printf("%lf\n", cub3d->plane_y);
	printf("%lf\n", cub3d->olddir_x);
	printf("%lf\n", cub3d->oldplane_x);
	printf("%lf\n", cub3d->cam_plane);
	printf("%lf\n", cub3d->raydir_x);
	printf("%lf\n", cub3d->raydir_y);

	printf("%d\n", cub3d->map_x);
	printf("%d\n", cub3d->map_y);


	printf("===============================\n\n");
}