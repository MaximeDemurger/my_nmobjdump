/*
** my_putnbr.c for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 19:54:29 2016 Fanny Tavart
** Last update Sat Jan 28 14:45:11 2017 Fanny Tavart
*/

#include "my.h"

void		my_putnbr_base(int output, unsigned long nbr, char *base)
{
  unsigned long	divi;
  unsigned long	result;
  unsigned long	len;

  len = my_strlen(base);
  divi = 1;
  result = 0;
  while (nbr / divi >= len)
    divi = divi * len;
  while (divi >= 1)
    {
      result = (nbr / divi) % len;
      result = base[result];
      my_dputchar(output, result);
      divi = divi / len;
    }
}

void	my_dputnbr(int output, int nb)
{
  int	divi;
  int	result;

  if (nb < 0)
    my_dputchar(output, '-');
  divi = 1;
  result = 0;
  while (nb / divi > 9)
    divi = divi * 10;
  while (divi >= 1)
    {
      result = (nb / divi) % 10;
      my_dputchar(output, result + 48);
      divi = divi / 10;
    }
}
