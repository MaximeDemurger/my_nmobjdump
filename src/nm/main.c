/*
** main.c for main nm in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/src/nm
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Mon Feb 13 10:08:37 2017 Fanny Tavart
** Last update Tue Feb 21 09:49:55 2017 Fanny Tavart
*/

#include "nm.h"
#include "my.h"

int	main(int ac, char **av)
{
  if (check_files(ac, av) != 0)
    return (1);
  return (0);
}
