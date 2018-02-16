/*
** my_dputstr.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 18:29:23 2016 Fanny Tavart
** Last update Mon Jun 13 18:30:18 2016 Fanny Tavart
*/

#include <unistd.h>
#include "my.h"

void	my_dputstr(int output, const char *str)
{
  write(output, str, my_strlen(str));
}
