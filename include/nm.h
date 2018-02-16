/*
** nm.h for nm.h in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/include
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Mon Feb 13 10:15:30 2017 Fanny Tavart
** Last update Thu Feb 23 16:27:21 2017 Fanny Tavart
*/

#ifndef NM_H_
# define NM_H_

# include <stdlib.h>
# include <sys/stat.h>
# include <elf.h>

typedef struct	s_type
{
  char		(*ptr)(const Elf64_Sym sym, const Elf64_Shdr *shdr);
}		t_type;

char		check_wv(const Elf64_Sym sym, const Elf64_Shdr *shdr);
char		check_shndx(const Elf64_Sym sym, const Elf64_Shdr *shdr);
char		check_shtype(const Elf64_Sym sym, const Elf64_Shdr *shdr);

typedef struct	s_symbol
{
  char		*name;
  Elf64_Addr	value;
  char		type;
  char		end;
}		t_symbol;

int		open_file(const char *filepath, const char *bin_name, char one);
int		check_files(int ac, char **av);
char		getsymboltab(char *buffer,
			     const char *bin_name,
			     const char *filepath,
			     size_t bufsize);
char		check_errors(const Elf64_Ehdr *ehdr,
			     const char *bin_name,
			     const char *filepath);
t_symbol	*sort_symbol_array(t_symbol *arr);
unsigned int	get_symbol_array_size(t_symbol *arr);
char            get_type(const Elf64_Sym sym,
			 const Elf64_Shdr *shdr,
			 const char *name);
int		error_file(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name);
int		error_size(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name);

#endif /* !NM_H_ */
