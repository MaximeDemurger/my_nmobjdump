/*
** open_file.c for openfile in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 13:45:17 2017 Fanny Tavart
** Last update Sat Feb 25 15:28:59 2017 Fanny Tavart
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

static Elf64_Addr	get_start_address(const Elf64_Shdr *shdr,
					  const Elf64_Ehdr *ehdr,
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

static int	check_file_type(const Elf64_Ehdr *ehdr,
				const char *bin_name,
				const char *filepath)
{
  if (check_errors(ehdr, bin_name, filepath) != 1)
    return (0);
  if (ehdr->e_ident[EI_CLASS] != ELFCLASS64)
    return (open_file32(filepath, bin_name));
  return (1);
}

static int	get_file_content(int fd,
				 const char *filepath,
				 const char *bin_name,
				 struct stat bufstat)
{
  void		*buffer;
  Elf64_Ehdr	*ehdr;
  Elf64_Shdr	*shdr;
  char		*strtab;
  int		error;

  if ((buffer = mmap(NULL, bufstat.st_size,
		     PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t)(-1))
    return (-1);
  ehdr = (Elf64_Ehdr *)buffer;
  if ((error = check_file_type(ehdr, bin_name, filepath)) != 1)
    return (error);
  if ((error = error_size(bufstat, fd, filepath, bin_name)) != 0
      && (error = error_size32(bufstat, fd, filepath, bin_name)) != 0)
    return (error);
  shdr = (Elf64_Shdr *)(buffer + ehdr->e_shoff);
  strtab = buffer + shdr[ehdr->e_shstrndx].sh_offset;
  objdump_f(ehdr, shdr, filepath, get_start_address(shdr, ehdr, strtab));
  objdump_s(ehdr, shdr, strtab, buffer);
  if (munmap(buffer, bufstat.st_size) == -1)
    {
      close(fd);
      return (-1);
    }
  return (0);
}

int		open_file(const char *filepath, const char *bin_name)
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
  if ((error = get_file_content(fd, filepath, bin_name, bufstat)) != 0)
    {
      close(fd);
      return (-2);
    }
  return (close(fd));
}
