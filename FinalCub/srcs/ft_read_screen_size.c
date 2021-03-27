#include "cub3d.h"

int	ft_numlen(char *str, int *c)
{
	int	len;
	int	i;

	i = *c;
	len = 0;
	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	*c = i;
	return (len);
}

int	ft_read_width(char *str, int c, t_cub3d *cub3d)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[c] == ' ')
		c++;
	if (!ft_isdigit(str[c]))
	{
		if (str[c] == '-')
			exception(cub3d, SIX);
		else
			exception(cub3d, THIRTY);
	}
	while (str[c] == '0')
		c++;
	len = ft_numlen(str, &c);
	if (len > 4)
		exception(cub3d, THIRTYSEVEN);
	tmp = ft_substr(str, c - len, len);
	cub3d->scr_w = ft_parse_int(tmp);
	free(tmp);
	return (c);
}

void	ft_check_end_of_str(t_cub3d *cub3d, char *str, int c)
{
	while (str[c])
	{
		if (str[c] != ' ')
			exception(cub3d, THIRTY);
		c++;
	}
}

int	ft_read_height(char *str, int c, t_cub3d *cub3d)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[c] == ' ')
		c++;
	if (!ft_isdigit(str[c]))
	{
		if (str[c] == '-')
			exception(cub3d, SIX);
		else
			exception(cub3d, THIRTY);
	}
	while (str[c] == '0')
		c++;
	len = ft_numlen(str, &c);
	if (len > 4)
		exception(cub3d, THIRTYSEVEN);
	tmp = ft_substr(str, c - len, len);
	cub3d->scr_h = ft_parse_int(tmp);
	free(tmp);
	return (c);
}

void	ft_read_screen_size(t_cub3d *cub3d)
{
	int	i;
	int	screen_w;
	int	screen_h;
	int	c;

	i = 0;
	while (cub3d->buf.buffer[i])
	{
		if (cub3d->buf.buffer[i][0] == 'R')
			break ;
		i++;
	}
	c = 1;
	c = ft_read_width(cub3d->buf.buffer[i], c, cub3d);
	c = ft_read_height(cub3d->buf.buffer[i], c, cub3d);
	mlx_get_screen_size(&screen_w, &screen_h);
	if (cub3d->scr_w > screen_w)
		cub3d->scr_w = screen_w;
	if (cub3d->scr_h > screen_h)
		cub3d->scr_h = screen_h;
	if (cub3d->scr_w <= 0 || cub3d->scr_h <= 0)
		exception(cub3d, SIX);
}
