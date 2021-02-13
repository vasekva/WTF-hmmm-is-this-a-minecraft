#include "cub3D.h"

t_screen    	*init_screen(t_screen *screen)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
    screen->w = 0;
    screen->h = 0;
    return (screen);
}

t_map       	*init_map(t_map *map)
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

t_floor			*init_floor(t_floor *floor)
{
   if (!floor)
       floor = (t_floor *)malloc(sizeof(t_floor));
    floor->r = 0;
    floor->g = 0;
    floor->b = 0;
    return (floor);
}

t_ceiling    	*init_ceiling(t_ceiling *ceiling)
{
   if (!ceiling)
       ceiling = (t_ceiling *)malloc(sizeof(t_ceiling));
    ceiling->r = 0;
    ceiling->g = 0;
    ceiling->b = 0;
    return (ceiling);
}

t_parser 		*init_parser(t_parser *parser)
{
    if (!parser)
        parser = (t_parser *)malloc(sizeof(t_parser));
	parser->c_screen_size = 0;
	parser->c_color_floor = 0;
	parser->c_color_ceiling = 0;
	parser->c_north = 0;
	parser->c_south = 0;
	parser->c_west = 0;
	parser->c_east = 0;
	parser->c_sprite = 0;
	parser->count_of_recorded_values = 0;
	parser->count_of_map_lines = 0;
	parser->max_strlen_of_map = 0;
	return (parser);
}
