/*
** my_dprint.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Tue Jun 14 16:26:28 2016 Fanny Tavart
** Last update Sun Feb 12 23:19:50 2017 Fanny Tavart
*/

#include "my.h"

void	dputc(int output, va_list ap)
{
  my_dputchar(output, va_arg(ap, int));
}

void	dputu(int output, va_list ap)
{
  unsigned long	nb;

  nb = va_arg(ap, unsigned long);
  my_putnbr_base(output, nb, "0123456789");
}

void	dputs(int output, va_list ap)
{
  my_dputstr(output, va_arg(ap, char *));
}

void	dputd(int output, va_list ap)
{
  my_dputnbr(output, va_arg(ap, int));
}

void		dputp(int output, va_list ap)
{
  unsigned long	nb;

  nb = va_arg(ap, unsigned long);
  if (nb == 0)
    my_dputstr(output, "(nil)");
  else
    {
      my_dputstr(output, "0x");
      my_putnbr_base(output, nb, "0123456789ABCDEF");
    }
}
