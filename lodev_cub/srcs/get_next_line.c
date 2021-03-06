#include "cub3D.h"

int		get_next_line(int fd, char **line)
{
  int i;
  int ret;
  char buffer[1000000];
  char buf;
  
  i = 0;
  while ((ret = read(fd, &buf, 1)) != 0)
  {
    if (buf == '\n')
      break ;
    buffer[i] = buf;
    i++;
  }
  buffer[i] = '\0';
  *line = (char *)malloc(sizeof(char) * i);
  i = 0;
  while (buffer[i] != 0)
  {
    line[0][i] = buffer[i];
    i++;
  }
  // free(buffer);
  line[0][i] = '\0';
  return (ret);
}