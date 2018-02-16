/*
** objdump_f.c for objdump f option in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Fri Feb 24 11:59:35 2017 Fanny Tavart
** Last update Sat Feb 25 15:44:45 2017 Fanny Tavart
*/

#include <elf.h>
#include <stdio.h>
#include "objdump.h"

t_flags	g_flags32[8] =
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

static void	display_flags32(unsigned int flags)
{
  unsigned int	idx;
  unsigned int	tmp;

  idx = 0;
  while (idx < 8)
    {
      tmp = flags;
      flags = g_flags32[idx].ptr(flags);
      if (idx != 0 && flags != 0 && flags != tmp)
      	printf(", ");
      idx += 1;
    }
}

static unsigned int	get_sym_flags32(const Elf32_Sym *sym,
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

static unsigned int	get_section_flags32(const Elf32_Shdr *shdr,
					    const Elf32_Ehdr *ehdr,
					    unsigned int flags)
{
  unsigned int	idx;
  Elf32_Sym	*sym;
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

static unsigned int	check_flags32(const Elf32_Ehdr *ehdr,
				      const Elf32_Shdr *shdr,
				      unsigned int flags)
{
  if (ehdr->e_type == ET_EXEC)
    flags += EXEC_P + D_PAGED + HAS_SYMS;
  else if (ehdr->e_type == ET_DYN)
    flags += DYNAMIC + D_PAGED;
  else if (ehdr->e_type == ET_REL)
    flags += HAS_RELOC;
  return (flags);
}

void		objdump_f32(const Elf32_Ehdr *ehdr,
			    const Elf32_Shdr *shdr,
			    const char *filepath,
			    const Elf32_Addr start_address)
{
  unsigned int	flags;

  flags = NO_FLAGS;
  printf("\n%s:     file format elf32-i386\n", filepath);
  flags = check_flags32(ehdr, shdr, flags);
  printf("architecture: i386:x86-32, flags %010p:\n", flags);
  display_flags32(flags);
  printf("\n");
  if (start_address != 0)
    printf("start address %018p\n\n", start_address);
  else
    printf("start address 0x0000000000000000\n\n");
}
