/*
** my_dputchar.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 18:25:09 2016 Fanny Tavart
** Last update Mon Jun 13 19:47:00 2016 Fanny Tavart
*/

#include <unistd.h>

void	my_dputchar(int output, char c)
{
  write(output, &c, 1);
}
