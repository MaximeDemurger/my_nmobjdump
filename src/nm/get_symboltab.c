/*
** get_symboltab.c for get symbol tab in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 13:27:53 2017 Fanny Tavart
** Last update Sat Feb 25 17:07:34 2017 Fanny Tavart
*/

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include "nm.h"
#include "my.h"

static void	display_symbol_array(t_symbol *arr)
{
  unsigned int	idx;

  idx = 0;
  while (arr[idx].end != 1)
    {
      if (arr[idx].type == 'w' || arr[idx].type == 'U')
	printf("                 %c %s\n", arr[idx].type, arr[idx].name);
      else if (arr[idx].value != 0
	       || arr[idx].type == 't'
	       || arr[idx].type == 'n'
	       || arr[idx].type == 'T')
	printf("%016x %c %s\n", arr[idx].value, arr[idx].type, arr[idx].name);
      idx += 1;
    }
}

static t_symbol	*create_symbol_array(unsigned int arr_size,
				     Elf64_Sym *sym,
				     char *namearray,
				     Elf64_Shdr *shdr)
{
  unsigned int	symidx;
  unsigned int	idx;
  t_symbol	*arr;

  if (sym == NULL || namearray == NULL || arr_size == 0)
    return (NULL);
  if ((arr = malloc((sizeof(t_symbol) * arr_size) + 1)) == NULL)
    return (NULL);
  idx = 0;
  symidx = 0;
  while (idx < arr_size)
    {
      if ((namearray + sym[idx].st_name)[0] != '\0')
	{
	  arr[symidx].end = 0;
	  arr[symidx].value = sym[idx].st_value;
	  arr[symidx].name = namearray + sym[idx].st_name;
	  arr[symidx].type = (get_type(sym[idx], shdr, arr[symidx].name) == 0) ?
	    ' ' : get_type(sym[idx], shdr, arr[symidx].name);
	  symidx += 1;
	}
      idx += 1;
    }
  arr[symidx].end = 1;
  return (arr);
}

static char	handle_array(unsigned int arr_size,
			     Elf64_Sym *sym,
			     char *namearray,
			     Elf64_Shdr *shdr)
{
  t_symbol	*arr;

  if ((arr = create_symbol_array(arr_size, sym, namearray, shdr)) == NULL)
    return (0);
  arr = sort_symbol_array(arr);
  display_symbol_array(arr);
  free(arr);
  return (1);
}

static char	find_section(Elf64_Ehdr	*ehdr,
			     Elf64_Shdr *shdr,
			     char *strtab,
			     char *buffer)
{
  char		*namearray;
  Elf64_Sym	*sym;
  unsigned int	size;
  int		idx;

  sym = NULL;
  namearray = NULL;
  idx = 0;
  while (idx < ehdr->e_shnum)
    {
      if (my_strcmp(strtab + shdr[idx].sh_name, ".symtab") == 0)
  	{
  	  sym = (Elf64_Sym *)(buffer + (shdr + idx)->sh_offset);
	  size = (shdr + idx)->sh_size / sizeof(Elf64_Sym);
  	}
      else if (my_strcmp(strtab + shdr[idx].sh_name, ".strtab") == 0)
	namearray = (buffer + (shdr + idx)->sh_offset);
      idx += 1;
    }
  if (handle_array(size, sym, namearray, shdr) == 0)
    return (0);
  return (1);
}

char		getsymboltab(char *buffer,
			     const char *bin_name,
			     const char *filepath,
			     size_t bufsize)
{
  Elf64_Ehdr	*ehdr;
  Elf64_Shdr	*shdr;
  char		*strtab;

  ehdr = (Elf64_Ehdr *)buffer;
  shdr = (Elf64_Shdr *)(buffer + ehdr->e_shoff);
  if (check_errors(ehdr, bin_name, filepath) == 0)
    return (0);
  strtab = (char *)(buffer + shdr[ehdr->e_shstrndx].sh_offset);
  if (find_section(ehdr, shdr, strtab, buffer) == 0)
    return (0);
  return (1);
}
