/*
** my_strlen.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 18:27:25 2016 Fanny Tavart
** Last update Mon Jun 13 18:43:27 2016 Fanny Tavart
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i += 1;
  return (i);
}
