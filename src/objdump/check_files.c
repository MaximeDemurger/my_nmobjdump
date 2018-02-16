/*
** check_files.c<objdump> for check_files in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Thu Feb 16 10:20:36 2017 Fanny Tavart
** Last update Fri Feb 24 14:32:53 2017 Fanny Tavart
*/

#include "objdump.h"
#include "my.h"

int	check_files(int ac, char **av)
{
  int	idx;
  int	success;

  if (ac < 2)
    {
      if (open_file("a.out", av[0]) == -1)
	my_dprintf(2, "%s: 'a.out': No such file\n", av[0] + 2);
      return (0);
    }
  else
    {
      idx = 1;
      while (idx < ac)
	{
	  if ((success = open_file(av[idx], av[0])) == -1)
	    my_dprintf(2, "%s: '%s': No such file\n", av[0] + 2, av[idx]);
	  idx += 1;
	}
    }
  return (0);
}
