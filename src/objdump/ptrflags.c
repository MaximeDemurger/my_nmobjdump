/*
** ptrflags.c for flags pointer functions in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Fri Feb 24 11:55:00 2017 Fanny Tavart
** Last update Sat Feb 25 12:29:08 2017 Fanny Tavart
*/

#include <stdio.h>
#include "objdump.h"

unsigned int	no_flags(unsigned int flags)
{
  if ((flags & NO_FLAGS) != 0)
    {
      printf("NO_FLAGS");
      flags -= NO_FLAGS;
    }
  return (flags);
}

unsigned int	has_reloc(unsigned int flags)
{
  if ((flags & HAS_RELOC) != 0)
    {
      printf("HAS_RELOC");
      flags -= HAS_RELOC;
    }
  return (flags);
}

unsigned int	exec_p(unsigned int flags)
{
  if ((flags & EXEC_P) != 0)
    {
      printf("EXEC_P");
      flags -= EXEC_P;
    }
  return (flags);
}

unsigned int	has_debug(unsigned int flags)
{
  if ((flags & HAS_DEBUG) != 0)
    {
      printf("HAS_DEBUG");
      flags -= HAS_DEBUG;
    }
  return (flags);
}

unsigned int	has_syms(unsigned int flags)
{
  if ((flags & HAS_SYMS) != 0)
    {
      printf("HAS_SYMS");
      flags -= HAS_SYMS;
    }
  return (flags);
}
