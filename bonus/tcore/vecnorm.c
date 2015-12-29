/*
** vecnorm.c for vecnorm in /home/alies/rendu/gfx_wolf3d/tcore
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 18:54:50 2015 Arnaud Alies
** Last update Wed Dec  9 19:08:16 2015 Arnaud Alies
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	norm;

  norm = sqrt(pow(((double)coord1->x - (double)coord0->x), 2.0) +
	      pow(((double)coord1->y - (double)coord0->y), 2.0));
  return (norm);
}
