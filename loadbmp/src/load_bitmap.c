/*
** load_bitmap.c for load bitmap in /home/alies/rendu/binarizer_2020
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Dec  8 14:57:34 2015 Arnaud Alies
** Last update Thu Dec 10 16:30:16 2015 Arnaud Alies
*/

#include <lapin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bmp.h"

t_bunny_pixelarray	*load_pix(int fd)
{
  char			buffer[2048];
  t_bunny_pixelarray	*pix;
  t_head		head;
  t_info		info;
  int			r;

  r = read(fd, &head, sizeof(head));
  if (r != sizeof(head))
    return (NULL);
  r = read(fd, &info, sizeof(info));
  if (r != sizeof(info))
    return (NULL);
  read(fd, buffer, (sizeof(head) + sizeof(info)) - head.offset);
  return (bunny_new_pixelarray(info.width, info.height));
}

void	c_rev(t_color *color)
{
  t_color buffer;

  buffer = *color;
  (color->argb)[0] = buffer.argb[2];
  (color->argb)[1] = buffer.argb[1];
  (color->argb)[2] = buffer.argb[0];
  (color->argb)[3] = 255;
}

int	read_init(t_bunny_pixelarray **pix,
		  t_bunny_position *pos,
		  int *fd,
		  const char *file)
{
  if ((*fd = open(file, O_RDONLY)) == -1)
    return (1);
  if ((*pix = load_pix(*fd)) == NULL)
    return (1);
  pos->x = 0;
  pos->y = ((*pix)->clipable).clip_height - 1;
  return (0);
}

t_bunny_pixelarray	*load_bitmap(const char *file)
{
  t_color		buffer;
  int			r;
  int			fd;
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;

  if (read_init(&pix, &pos, &fd, file))
    return (NULL);
  r = 1;
  while (r > 0)
    {
      r = read(fd, buffer.argb, 4);
      if (r == 4)
	{
	  c_rev(&buffer);
	  tekpixel(pix, &pos, &buffer);
	}
      pos.x += 1;
      if (pos.x >= (pix->clipable).clip_width)
	{
	  pos.x = 0;
	  pos.y -= 1;
	}
    }
  close(fd);
  return (pix);
}
