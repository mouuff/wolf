/*
** disp.h for disp in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec 11 20:24:24 2015 Arnaud Alies
** Last update Fri Dec 11 20:29:41 2015 Arnaud Alies
*/

#ifndef DISP_H_
#define DISP_H_

typedef struct s_disp
{
  t_bunny_pixelarray    *texture;
  t_bunny_position      pos;
  int                   height;
  int                   space;
  t_hit			*hit;
} t_disp;

#endif
