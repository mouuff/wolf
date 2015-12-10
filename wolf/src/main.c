/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Thu Dec 10 20:47:08 2015 Arnaud Alies
*/

#include <math.h>
#include <lapin.h>
#include "bmp.h"
#include "wolf.h"

int	init_data(t_data *data, char *file)
{
  data->ang = 3.1415/2;
  data->map = load_map(file);
  if (data->map == NULL)
    return (1);
  (data->pos).x = ((data->map)->spawn)[0];
  (data->pos).y = ((data->map)->spawn)[1];
  show_map(data->map);
  return (0);
}

void	walk(t_data *data, int speed)
{
  t_pt	new;

  new.x = (data->pos).x + cos(data->ang) / 5 * speed;
  new.y = (data->pos).y;
  if (!check_wall(data->map, new.x, new.y))
    {
      new.x = (data->pos).x + cos(data->ang) / 10 * speed;
      (data->pos) = new;
    }
  new.x = (data->pos).x;
  new.y = (data->pos).y + sin(data->ang) / 5 * speed;
  if (!check_wall(data->map, new.x, new.y))
    {
      new.y = (data->pos).y + sin(data->ang) / 10 * speed;
      (data->pos) = new;
    }
}

void	move(t_data *data)
{
  if (data->keys != NULL)
    {
      if (data->keys[BKS_D])
	data->ang -= 0.04;
      if (data->keys[BKS_Q])
	data->ang += 0.04;
      if (data->keys[BKS_Z])
	walk(data, 1);
      if (data->keys[BKS_S])
	walk(data, -1);
    }
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  move(data);
  wolf(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  /*bunny_blit(&((data->win)->buffer), &((data->texture)->clipable), &zero);*/
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data	*data;

  data = (t_data*)data_pt;
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  if (ac <= 1)
    return (1);
  if (init_data(&data, av[1]))
    return (1);
  
  if ((data.texture = load_bitmap("insanedoge.bmp")) == NULL)
    return (1);
  data.keys = NULL;
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "Wolf")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
