#include "cub3D.h"


t_map       *init_map(t_map *map)
{
    if (!map)
        map = (t_map *)malloc(sizeof(t_map));
    map->north = 0;
    map->south = 0;
    map->west = 0;
    map->east = 0;
    map->sprite = 0;
    return (map);
}  

t_screen    *init_screen(t_screen *screen)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
    screen->w = 0;
    screen->h = 0;
    return (screen);
}

t_floor    *init_floor(t_floor *floor)
{
   if (!floor)
       floor = (t_floor *)malloc(sizeof(t_floor));
    floor->r = 0;
    floor->g = 0;
    floor->b = 0;
    return (floor);
}

t_ceiling    *init_ceiling(t_ceiling *ceiling)
{
   if (!ceiling)
       ceiling = (t_ceiling *)malloc(sizeof(t_ceiling));
    ceiling->r = 0;
    ceiling->g = 0;
    ceiling->b = 0;
    return (ceiling);
}

void    init_cub3D(t_cub3D *cub3D)
{
    cub3D->screen = init_screen(NULL);
    cub3D->map = init_map(NULL);
    cub3D->floor = init_floor(NULL);
    cub3D->ceiling = init_ceiling(NULL);
    cub3D->count_of_recorded_values = 0;
}

int     main(int argc, char **argv)
{
    t_cub3D cub3D;

    if (argc)
    {
        if (argc == 2)
        {
            init_cub3D(&cub3D);
            ft_parse(argv[1], &cub3D); //TODO проверка наличия файла, откуда идет чтение
        }
    }
    return (0);
}