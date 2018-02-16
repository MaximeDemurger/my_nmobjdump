/*
** check_type.c for check_type in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/src
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 19:58:45 2017 Fanny Tavart
** Last update Fri Feb 24 12:16:12 2017 Fanny Tavart
*/

#include <elf.h>

char	check_wv(const Elf64_Sym sym, const Elf64_Shdr *shdr)
{
  (void)shdr;
  if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
    {
      if (ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
	return ('V');
      return ('W');
    }
  return (0);
}

char	check_shndx(const Elf64_Sym sym, const Elf64_Shdr *shdr)
{
  (void)shdr;
  if (sym.st_shndx == SHN_UNDEF)
    return ('U');
  else if (sym.st_shndx == SHN_ABS)
    return ('A');
  else if (sym.st_shndx == SHN_COMMON)
    return ('C');
  return (0);
}

char	check_shtype(const Elf64_Sym sym, const Elf64_Shdr *shdr)
{
  if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
  	   && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    return ('B');
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
  	   && (shdr[sym.st_shndx].sh_flags == SHF_ALLOC
  	       || shdr[sym.st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC)))
    return ('R');
  else if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS
  	    && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
  	   || shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
    return ('D');
  else if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS
  	    && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
  	   || shdr[sym.st_shndx].sh_type == SHT_INIT_ARRAY
  	   || shdr[sym.st_shndx].sh_type == SHT_FINI_ARRAY)
    return ('T');
  return (0);
}
