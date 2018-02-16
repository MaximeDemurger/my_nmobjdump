/*
** ptrflagsbis.c for ptr flags in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/src/objdump
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sat Feb 25 12:29:22 2017 Fanny Tavart
** Last update Sat Feb 25 12:38:14 2017 Fanny Tavart
*/

#include <stdio.h>
#include "objdump.h"

unsigned int	has_locals(unsigned int flags)
{
  if ((flags & HAS_LOCALS) != 0)
    {
      printf("HAS_LOCALS");
      flags -= HAS_LOCALS;
    }
  return (flags);
}

unsigned int	dynamic(unsigned int flags)
{
  if ((flags & DYNAMIC) != 0)
    {
      printf("DYNAMIC");
      flags -= DYNAMIC;
    }
  return (flags);
}

unsigned int	d_paged(unsigned int flags)
{
  if ((flags & D_PAGED) != 0)
    {
      printf("D_PAGED");
      flags -= D_PAGED;
    }
  return (flags);
}
