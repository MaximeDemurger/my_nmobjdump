/*
** my_dprintf.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Tue Jun 14 15:39:45 2016 Fanny Tavart
** Last update Sun Feb 12 23:19:35 2017 Fanny Tavart
*/

#include <stdarg.h>
#include "my.h"

static t_flag	g_arr[6] =
  {
    {&dputc, 'c'},
    {&dputs, 's'},
    {&dputd, 'd'},
    {&dputd, 'i'},
    {&dputp, 'p'},
    {&dputu, 'u'}
  };

static int	check_flag(int output, char flag, va_list ap)
{
  int		idx;

  idx = 0;
  while (idx < 6)
    {
      if (g_arr[idx].letter == flag)
	{
	  g_arr[idx].ptr(output, ap);
	  return (1);
	}
      idx += 1;
    }
  return (0);
}

int		my_printf(const char *str, ...)
{
  va_list	ap;
  int		idx;

  va_start(ap, str);
  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] == '%' && str[idx + 1] != '\0')
	{
	  if (check_flag(1, str[idx + 1], ap) == 1)
	    idx += 1;
	}
      else
	my_dputchar(1, str[idx]);
      idx += 1;
    }
  va_end(ap);
  return (0);
}

int		my_dprintf(int output, const char *str, ...)
{
  va_list	ap;
  int		idx;

  va_start(ap, str);
  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] == '%' && str[idx + 1] != '\0')
	{
	  if (check_flag(output, str[idx + 1], ap) == 1)
	    idx += 1;
	}
      else
	my_dputchar(output, str[idx]);
      idx += 1;
    }
  va_end(ap);
  return (0);
}
