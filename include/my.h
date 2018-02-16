/*
** my.h for lib in /home/tavart_f/Epitech/lib/my
** 
** Made by Fanny Tavart
** Login   <tavart_f@epitech.net>
** 
** Started on  Mon Jun 13 18:26:00 2016 Fanny Tavart
** Last update Tue Feb 14 11:35:30 2017 Fanny Tavart
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>

# define SRC	0
# define DEST	1

/*
** --------------
** - MY_DPRINTF -
** --------------
*/

typedef struct	s_flag
{
  void		(*ptr)(int output, va_list ap);
  char		letter;
}		t_flag;

int	my_dprintf(int output, const char *str, ...);
int	my_printf(const char *str, ...);
void	dputc(int output, va_list ap);
void	dputs(int output, va_list ap);
void	dputu(int output, va_list ap);
void	dputd(int output, va_list ap);
void	dputp(int output, va_list ap);

/*
** ----------------
** - USEFUL TOOLS -
** ----------------
*/

void	my_dputchar(int output, char c);
int	my_strlen(const char *str);
void	my_dputstr(int output, const char *str);
char	*my_strcat(const char *src, char *dest);
char	*my_strcpy(const char *src, char *dest);
int	my_strcmp(const char *s1, const char *s2);
void	my_putnbr_base(int output, unsigned long nbr, char *base);
void	my_dputnbr(int output, int nb);
char	*get_next_line(const int fd);
int	openfile(const char *filepath);

#endif /* !MY_H_ */
