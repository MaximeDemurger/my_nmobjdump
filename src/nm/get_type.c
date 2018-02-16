/*
** get_type.c for get type in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 18:24:34 2017 Fanny Tavart
** Last update Fri Feb 24 12:17:46 2017 Fanny Tavart
*/

#include <elf.h>
#include <stdio.h>
#include <string.h>
#include "nm.h"

static t_type	g_type[3] =
  {
    {&check_wv},
    {&check_shndx},
    {&check_shtype}
  };

static char	check_type_lowcase(const Elf64_Sym sym, char type)
{
  if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && type != 0
      || ((type == 'W' || type == 'V') && sym.st_shndx == SHN_UNDEF))
    type += 32;
  return (type);
}

char            get_type(const Elf64_Sym sym,
			 const Elf64_Shdr *shdr,
			 const char *name)
{
  char		type;
  unsigned int	idx;

  type = (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE) ? 'u' : 0;
  if (strncmp("wm4.", name, 4) == 0)
    return ('n');
  idx = 0;
  while (idx < 3 && type == 0)
    {
      type = g_type[idx].ptr(sym, shdr);
      idx += 1;
    }
  type = check_type_lowcase(sym, type);
  return (type);
}
