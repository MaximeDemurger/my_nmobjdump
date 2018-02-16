/*
** objdump_s.c for objdump s option in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Fri Feb 24 12:05:25 2017 Fanny Tavart
** Last update Sat Feb 25 14:48:01 2017 Fanny Tavart
*/

#include <stdio.h>
#include <elf.h>
#include "my.h"

static void	print_space32(unsigned int idx, char end)
{
  if (end == 1)
    {
      while (idx % 16 != 0)
	{
	  printf(" ");
	  idx += 1;
	}
      printf("\n");
      return ;
    }
  while (idx % 16 != 0)
    {
      printf("  ");
      idx += 1;
      if (idx % 4 == 0)
  	printf(" ");
      if (idx % 16 == 0)
  	printf(" ");
    }
}

static void	print_hexa32(const Elf32_Shdr shdr,
			     char *buffer,
			     unsigned int idx)
{
  char		c;

  while (idx < shdr.sh_size)
    {
      c = (buffer + shdr.sh_offset)[idx];
      printf("%02x", (unsigned char)c);
      idx += 1;
      if (idx % 16 == 0)
	{
	  printf("  ");
	  break ;
	}
      if (idx % 4 == 0)
	printf(" ");
    }
  if (idx >= shdr.sh_size && idx % 16 != 0)
    print_space32(idx, 0);
}

static void	print_char32(char c)
{
  if (c >= 32 && c <= 126)
    printf("%c", c);
  else
    printf(".");
}

static void	print_sections32(const Elf32_Shdr shdr, char *buffer)
{
  unsigned int	idx;
  unsigned int	tmp;
  char		c;

  idx = 0;
  tmp = shdr.sh_addr;
  while (idx < shdr.sh_size)
    {
      if (idx % 16 == 0)
	{
	  printf(" %04x ", tmp);
	  tmp += 16;
	  print_hexa32(shdr, buffer, idx);
	}
      c = (buffer + shdr.sh_offset)[idx];
      print_char32(c);
      idx += 1;
      if (idx % 16 == 0)
	printf("\n");
    }
  if (idx >= shdr.sh_size && idx % 16 != 0)
    print_space32(idx, 1);
}

void		objdump_s32(const Elf32_Ehdr *ehdr,
			    const Elf32_Shdr *shdr,
			    char *strtab,
			    char *buffer)
{
  unsigned int	idx;

  idx = 0;
  while (idx < ehdr->e_shnum)
    {
      if ((strtab + shdr[idx].sh_name)[0] != '\0'
	  && my_strcmp(strtab + shdr[idx].sh_name, ".bss") != 0
	  && my_strcmp(strtab + shdr[idx].sh_name, ".shstrtab") != 0
	  && my_strcmp(strtab + shdr[idx].sh_name, ".symtab") != 0
	  && my_strcmp(strtab + shdr[idx].sh_name, ".strtab") != 0)
	{
	  printf("Contents of section %s:\n", strtab + shdr[idx].sh_name);
	  print_sections32(shdr[idx], buffer);
	}
      idx += 1;
    }
}
