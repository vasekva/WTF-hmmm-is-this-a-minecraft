
#include "cub3D.h"
#include "libft.h"

void    print_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        ft_putendl(map[i]);
        i++;
    }
}

char    **get_map(void)
{
    char    **map;
    int     i;

    i = -1;
    if (!(map = (char**)malloc(sizeof(char *) * (MAP_H + 1))))
         printf("MAP malloc error"); //TODO сделать вывод ошибок
    map[MAP_H] = 0;
    while (++i < MAP_H + 1)
        map[i] = ft_calloc(1, MAP_W + 1);
    ft_strcpy(map[0], "1111111111111111111111111111111111111111");
	ft_strcpy(map[1], "1000010000000000000000000000000000000001");
	ft_strcpy(map[2], "1010000011100000000000000001111100011111");
	ft_strcpy(map[3], "1000000011000000000000000000000000001001");
	ft_strcpy(map[4], "1010000011110000000000111111111111111111");
	ft_strcpy(map[5], "1000000000110000000000100000000000000011");
	ft_strcpy(map[6], "101001011111000000000010000000000000011");
	ft_strcpy(map[7], "1000000110111111110000100000000000000011");
	ft_strcpy(map[8], "1000000110111000000000111011100011100011");
	ft_strcpy(map[9], "1000000110000000000000000000000001100011");
	ft_strcpy(map[10], "1000000000111100000111000000000111100111");
	ft_strcpy(map[11], "1000001100001100000011000000000000000011");
	ft_strcpy(map[12], "1111111111111111111111111111111111111111");
	return (map);
}