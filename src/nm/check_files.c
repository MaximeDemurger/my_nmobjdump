/*
** check_files.c for check_files.c in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Thu Feb 16 10:12:51 2017 Fanny Tavart
** Last update Sat Feb 25 16:19:53 2017 Fanny Tavart
*/

#include <stdio.h>
#include "nm.h"
#include "my.h"

int	check_files(int ac, char **av)
{
  int	idx;
  int	success;
  char	one;

  one = 0;
  if (ac <= 2)
    one = 1;
  if (ac < 2)
    {
      if (open_file("a.out", av[0], one) == -1)
	dprintf(2, "%s: 'a.out': No such file\n", av[0] + 2);
      return (0);
    }
  else
    {
      idx = 1;
      while (idx < ac)
	{
	  if ((success = open_file(av[idx], av[0], one)) == -1)
	    dprintf(2, "%s: '%s': No such file\n", av[0] + 2, av[idx]);
	  idx += 1;
	}
    }
  return (0);
}
