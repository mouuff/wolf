/*
** load_bitmap.c for load bitmap in /home/alies/rendu/binarizer_2020
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Dec  8 14:57:34 2015 Arnaud Alies
** Last update Tue Dec  8 18:12:12 2015 Arnaud Alies
*/

#include <lapin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void    setpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   w;
  int   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}

t_bunny_pixelarray	*load_pix(int fd)
{
  char			buff[256];
  t_color		buffer;
  int			r;
  int			width;
  int			height;
  int			start;

  r = 0;
  r += read(fd, &buffer, 10);
  r += read(fd, &buffer, 4);
  start = buffer.full;
  r += read(fd, buffer.argb, 4);
  r += read(fd, buffer.argb, 4);
  width = buffer.full;
  r += read(fd, buffer.argb, 4);
  height = buffer.full;
  read(fd, buffer.argb, start - r -1);
  (void)buff;
  return (bunny_new_pixelarray(width, height));
}

void	c_rev(t_color *color)
{
  t_color buffer;

  buffer = *color;
  (color->argb)[0] = buffer.argb[3];
  (color->argb)[1] = buffer.argb[2];
  (color->argb)[2] = buffer.argb[1];
  (color->argb)[3] = 255;
}

int	read_init(t_bunny_pixelarray **pix,
		  t_bunny_position *pos,
		  int *fd,
		  const char *file)
{
  *fd = open(file, O_RDONLY);
  if (*fd == -1)
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
      c_rev(&buffer);
      setpixel(pix, &pos, &buffer);
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
