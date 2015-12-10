/*
** main.c for fire in /home/alies/rendu/gfx_incendie
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 21:54:40 2015 Arnaud Alies
** Last update Thu Dec 10 11:18:09 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <lapin.h>
#include "bmp.h"

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position	zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_data		data;

  if (ac <= 1)
    return (1);
  data.pix = load_bitmap(av[1]);
  if (data.pix == NULL)
    return (2);
  //all_grey(data.pix);
  //binarize(data.pix);
  data.win = bunny_start(((data.pix)->clipable).clip_width,
			 ((data.pix)->clipable).clip_height,
			 false, "Bitmap");
  if (data.win == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
