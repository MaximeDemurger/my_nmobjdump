/*
** objdump.h for objdump in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/include
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Mon Feb 13 10:16:22 2017 Fanny Tavart
** Last update Sat Feb 25 15:29:42 2017 Fanny Tavart
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <elf.h>
# include <sys/stat.h>

# define NO_FLAGS	0x00
# define HAS_RELOC	0x01
# define EXEC_P		0x02
# define HAS_DEBUG	0x08
# define HAS_SYMS	0x10
# define HAS_LOCALS	0x20
# define DYNAMIC	0x40
# define D_PAGED	0x100

typedef struct	s_flags
{
  unsigned int	(*ptr)(unsigned int flags);
}		t_flags;

unsigned int	no_flags(unsigned int flags);
unsigned int	has_reloc(unsigned int flags);
unsigned int	exec_p(unsigned int flags);
unsigned int	has_debug(unsigned int flags);
unsigned int	has_syms(unsigned int flags);
unsigned int	has_locals(unsigned int flags);
unsigned int	dynamic(unsigned int flags);
unsigned int	d_paged(unsigned int flags);

int		check_files(int ac, char **av);
char		check_errors(const Elf64_Ehdr *ehdr,
			     const char *bin_name,
			     const char *filepath);
int		error_file(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name);

/*
** --------------
** | OBJDUMP 64 |
** --------------
*/

void		objdump_f(const Elf64_Ehdr *ehdr,
			  const Elf64_Shdr *shdr,
			  const char *filepath,
			  const Elf64_Addr start_address);
void		objdump_s(const Elf64_Ehdr *ehdr,
			  const Elf64_Shdr *shdr,
			  char *strtab,
			  char *buffer);
int		open_file(const char *filepath, const char *bin_name);
int		error_size(struct stat bufstat,
			   int fd,
			   const char *filepath,
			   const char *bin_name);

/*
** --------------
** | OBJDUMP 32 |
** --------------
*/

void		objdump_f32(const Elf32_Ehdr *ehdr,
			    const Elf32_Shdr *shdr,
			    const char *filepath,
			    const Elf32_Addr start_address);
void		objdump_s32(const Elf32_Ehdr *ehdr,
			    const Elf32_Shdr *shdr,
			    char *strtab,
			    char *buffer);
int		open_file32(const char *filepath, const char *bin_name);
int		error_size32(struct stat bufstat,
			     int fd,
			     const char *filepath,
			     const char *bin_name);

#endif /* !OBJDUMP_H_ */
