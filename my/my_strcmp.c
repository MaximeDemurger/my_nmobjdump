/*
** my_strcmp.c for lib in /home/tavart_f/Epitech/lib
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 19:00:02 2016 Fanny Tavart
** Last update Mon Jun 13 19:38:48 2016 Fanny Tavart
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	idx;

  idx = 0;
  while (s1[idx] != '\0')
    {
      if (s1[idx] != s2[idx])
	return (s1[idx] - s2[idx]);
      idx += 1;
    }
  if (s2[idx] != '\0')
    return (s1[idx] - s2[idx]);
  return (0);
}
