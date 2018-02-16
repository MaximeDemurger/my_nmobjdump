/*
** main.c for main objdump in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/src/objdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Mon Feb 13 10:10:21 2017 Fanny Tavart
** Last update Thu Feb 16 10:23:44 2017 Fanny Tavart
*/

#include "objdump.h"
#include "my.h"

int	main(int ac, char **av)
{
  if (check_files(ac, av) != 0)
    return (84);
  return (0);
}
