/*
** open_file.c for openfile in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 13:45:17 2017 Fanny Tavart
** Last update Sat Feb 25 16:20:06 2017 Fanny Tavart
*/

#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include "nm.h"
#include "my.h"

unsigned int	get_symbol_array_size(t_symbol *arr)
{
  unsigned int		idx;

  idx = 0;
  while (arr[idx].end != 1)
    idx += 1;
  return (idx);
}

int		open_file(const char *filepath, const char *bin_name, char one)
{
  int		fd;
  struct stat	bufstat;
  void		*buffer;
  int		error;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (close(fd));
  if (fstat(fd, &bufstat) == -1)
    return (close(fd));
  if ((error = error_file(bufstat, fd, filepath, bin_name)) != 0)
    return (error);
  if ((buffer = mmap(NULL, bufstat.st_size,
		     PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t)(-1))
    return (-2);
  if ((error = error_size(bufstat, fd, filepath, bin_name)) != 0)
    return (error);
  if (one != 1)
    printf("\n%s:\n", filepath);
  if (getsymboltab(buffer, bin_name, filepath, bufstat.st_size) == 0)
    return (-2);
  if (munmap(buffer, bufstat.st_size) == -1)
    return (-1);
  return (close(fd));
}
