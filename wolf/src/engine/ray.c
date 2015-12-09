/*
** calc.c for calc in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Dec  7 14:50:37 2015 Arnaud Alies
** Last update Wed Dec  9 20:54:47 2015 Arnaud Alies
*/

#include <math.h>
#include <lapin.h>
#include "wolf.h"

t_pt	get_ray(int ray_x)
{
  t_pt	res;

  res.x = DIS;
  res.y = FOV * ((((float)WIDTH / 2.0) - (float)ray_x) / (float)WIDTH);
  return (res);
}

t_pt	rotate_ray(t_pt ray, float ang)
{
  t_pt	res;

  res.x = (ray.x * cos(ang)) - (ray.y * sin(ang));
  res.y = (ray.x * sin(ang)) + (ray.y * cos(ang));
  return (res);
}
