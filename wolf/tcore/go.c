/*
** go.c for go in /home/alies/rendu/gfx_wolf3d/tcore
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 21:35:37 2015 Arnaud Alies
** Last update Wed Dec  9 21:41:05 2015 Arnaud Alies
*/

#include <math.h>
#include <lapin.h>

void	go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move)
{
  newpos->x = curpos->x + cos(angle) * move;
  newpos->y = curpos->y + sin(angle) * move;
}
