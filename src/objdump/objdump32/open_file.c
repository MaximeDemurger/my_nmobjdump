/*
** open_file.c for openfile in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 13:45:17 2017 Fanny Tavart
** Last update Sat Feb 25 15:04:25 2017 Fanny Tavart
*/

#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include "objdump.h"
#include "my.h"

static Elf32_Addr	get_start_address32(const Elf32_Shdr *shdr,
					    const Elf32_Ehdr *ehdr,
					    const char *strtab)
{
  unsigned int	idx;

  idx = 0;
  while (idx < ehdr->e_shnum)
    {
      if (my_strcmp(strtab + shdr[idx].sh_name, ".text") == 0)
	return (shdr[idx].sh_addr);
      idx += 1;
    }
  return (0);
}

static int	get_file_content32(int fd,
				   const char *filepath,
				   const char *bin_name,
				   struct stat bufstat)
{
  void		*buffer;
  Elf32_Ehdr	*ehdr;
  Elf32_Shdr	*shdr;
  char		*strtab;
  int		error;

  if ((buffer = mmap(NULL, bufstat.st_size,
		     PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t)(-1))
    return (-1);
  if ((error = error_size32(bufstat, fd, filepath, bin_name)) != 0)
    return (error);
  ehdr = (Elf32_Ehdr *)buffer;
  shdr = (Elf32_Shdr *)(buffer + ehdr->e_shoff);
  strtab = buffer + shdr[ehdr->e_shstrndx].sh_offset;
  objdump_f32(ehdr, shdr, filepath, get_start_address32(shdr, ehdr, strtab));
  objdump_s32(ehdr, shdr, strtab, buffer);
  if (munmap(buffer, bufstat.st_size) == -1)
    {
      close(fd);
      return (-1);
    }
  return (0);
}

int		open_file32(const char *filepath, const char *bin_name)
{
  struct stat	bufstat;
  int		fd;
  int		error;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (close(fd));
  if (fstat(fd, &bufstat) == -1)
    return (close(fd));
  if ((error = error_file(bufstat, fd, filepath, bin_name)) != 0)
    return (error);
  if ((error = get_file_content32(fd, filepath, bin_name, bufstat)) != 0)
    {
      close(fd);
      return (-2);
    }
  return (close(fd));
}
