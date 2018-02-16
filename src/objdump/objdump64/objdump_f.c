/*
** objdump_f.c for objdump f option in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Fri Feb 24 11:59:35 2017 Fanny Tavart
** Last update Sat Feb 25 15:42:48 2017 Fanny Tavart
*/

#include <elf.h>
#include <stdio.h>
#include "objdump.h"

t_flags	g_flags[8] =
  {
    {&no_flags},
    {&has_reloc},
    {&exec_p},
    {&has_debug},
    {&has_syms},
    {&has_locals},
    {&dynamic},
    {&d_paged}
  };

static void	display_flags(unsigned int flags)
{
  unsigned int	idx;
  unsigned int	tmp;

  idx = 0;
  while (idx < 8)
    {
      tmp = flags;
      flags = g_flags[idx].ptr(flags);
      if (idx != 0 && flags != 0 && flags != tmp)
      	printf(", ");
      idx += 1;
    }
}

static unsigned int	get_sym_flags(const Elf64_Sym *sym,
				      unsigned int size,
				      unsigned int flags)
{
  unsigned int	idx;

  idx = 0;
  while (idx < size)
    {
      if (sym[idx].st_info == STB_LOCAL)
	return (flags + HAS_LOCALS);
    }
  return (flags);
}

static unsigned int	get_section_flags(const Elf64_Shdr *shdr,
					  const Elf64_Ehdr *ehdr,
					  unsigned int flags)
{
  unsigned int	idx;
  Elf64_Sym	*sym;
  unsigned int	size;

  idx = 0;
  while (idx < ehdr->e_shnum)
    {
      if (shdr[idx].sh_type == SHT_SYMTAB)
	flags += HAS_SYMS;
      idx += 1;
    }
  return (flags);
}

unsigned int	check_flags(const Elf64_Ehdr *ehdr,
			    const Elf64_Shdr *shdr,
			    unsigned int flags)
{
  if (ehdr->e_type == ET_EXEC)
    flags += EXEC_P + D_PAGED;
  else if (ehdr->e_type == ET_DYN)
    flags += DYNAMIC + D_PAGED;
  else if (ehdr->e_type == ET_REL)
    flags += HAS_RELOC;
  flags = get_section_flags(shdr, ehdr, flags);
  return (flags);
}

void		objdump_f(const Elf64_Ehdr *ehdr,
			  const Elf64_Shdr *shdr,
			  const char *filepath,
			  const Elf64_Addr start_address)
{
  unsigned int	flags;

  flags = NO_FLAGS;
  printf("\n%s:     file format elf64-x86-64\n", filepath);
  flags = check_flags(ehdr, shdr, flags);
  printf("architecture: i386:x86-64, flags %010p:\n", flags);
  display_flags(flags);
  printf("\n");
  if (start_address != 0)
    printf("start address %018p\n\n", start_address);
  else
    printf("start address 0x0000000000000000\n\n");
}
