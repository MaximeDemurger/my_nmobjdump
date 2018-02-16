/*
** check_errors.c for check errors nm in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Mon Feb 20 10:33:47 2017 Fanny Tavart
** Last update Sat Feb 25 17:40:29 2017 Fanny Tavart
*/

#include <elf.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

static char	check_ident(const unsigned char *ident)
{
  if (sizeof(ident) == 8 &&
      ident[EI_MAG0] == ELFMAG0 && ident[EI_MAG1] == ELFMAG1
      && ident[EI_MAG2] == ELFMAG2 && ident[EI_MAG3] == ELFMAG3
      && (ident[EI_CLASS] == ELFCLASS64 || ident[EI_CLASS] == ELFCLASS32)
      && ident[EI_DATA] != ELFDATANONE
      && ident[EI_VERSION] == EV_CURRENT)
    return (1);
  return (0);
}

int		error_file(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name)
{
  if (!S_ISREG(bufstat.st_mode))
    {
      my_dprintf(2, "%s: Warning: '%s' is not an ordinary file\n",
		 (bin_name + 2), filepath);
      close(fd);
      return (-2);
    }
  return (0);
}

int		error_size32(struct stat bufstat,
			     int fd,
			     const char *filepath,
			     const char *bin_name)
{
  Elf32_Ehdr	elf;
  unsigned int	size;

  if (read(fd, &elf, sizeof(elf)) == -1)
    return (close(fd));
  size = elf.e_shoff + (elf.e_shentsize * elf.e_shnum);
  if (size != bufstat.st_size)
    {
      my_dprintf(2, "%s: %s: File truncated\n",
		 (bin_name + 2), filepath);
      close(fd);
      return (-2);
    }
  return (0);
}

int		error_size(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name)
{
  Elf64_Ehdr	elf;
  unsigned int	size;

  if (read(fd, &elf, sizeof(elf)) == -1)
    return (close(fd));
  size = elf.e_shoff + (elf.e_shentsize * elf.e_shnum);
  if (size != bufstat.st_size)
    {
      my_dprintf(2, "%s: %s: File truncated\n",
		 (bin_name + 2), filepath);
      close(fd);
      return (-2);
    }
  return (0);
}

char		check_errors(const Elf64_Ehdr *ehdr,
			     const char *bin_name,
			     const char *filepath)
{
  if ((ehdr->e_type != ET_EXEC && ehdr->e_type != ET_REL
       && ehdr->e_type != ET_DYN) || check_ident(ehdr->e_ident) == 0)
    {
      my_dprintf(2, "%s: %s: File format not recognized\n", (bin_name + 2),
		 filepath);
      return (0);
    }
  return (1);
}
