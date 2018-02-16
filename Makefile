##
## Makefile for makefile in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump
## 
## Made by Fanny Tavart
## Login   <fanny.tavart@epitech.net>
## 
## Started on  Mon Feb 13 10:18:25 2017 Fanny Tavart
## Last update Sat Feb 25 16:54:56 2017 Fanny Tavart
##

CC	= gcc

RM	= rm -f

NAMENM	= my_nm

NAMEOD	= my_objdump

CFLAGS	= -W -Wextra -Werror
CFLAGS	+= -I./include

SRCSMY	= my/my_atoi.c		\
	  my/my_dprint.c	\
	  my/my_dprintf.c	\
	  my/my_dputchar.c	\
	  my/my_dputnbr.c	\
	  my/my_dputstr.c	\
	  my/my_strcmp.c	\
	  my/my_strlen.c	\

SRCSNM	= src/nm/main.c			\
	  src/nm/open_file.c		\
	  src/nm/get_symboltab.c	\
	  src/nm/sort_symbol_array.c	\
	  src/nm/get_type.c		\
	  src/nm/check_type.c		\
	  src/nm/check_errors.c		\
	  src/nm/check_files.c

SRCSOD	= src/objdump/main.c			\
	  src/objdump/check_errors.c		\
	  src/objdump/check_files.c		\
	  src/objdump/ptrflags.c		\
	  src/objdump/ptrflagsbis.c		\
	  src/objdump/objdump64/objdump_f.c	\
	  src/objdump/objdump64/objdump_s.c	\
	  src/objdump/objdump64/open_file.c	\
	  src/objdump/objdump32/objdump_f.c	\
	  src/objdump/objdump32/objdump_s.c	\
	  src/objdump/objdump32/open_file.c

OBJSNM	= $(SRCSNM:.c=.o)

OBJSOD	= $(SRCSOD:.c=.o)

all:		$(NAMENM) $(NAMEOD)

nm:		$(NAMENM)

objdump:	$(NAMEOD)

$(NAMENM):	$(OBJSNM)
		$(CC) -o $(NAMENM) $(SRCSMY) $(OBJSNM) $(CFLAGS)

$(NAMEOD):	$(OBJSOD)
		$(CC) -o $(NAMEOD) $(SRCSMY) $(OBJSOD) $(CFLAGS)

clean:
		$(RM) $(OBJSNM) $(OBJSOD)

fclean:		clean
		$(RM) $(NAMENM) $(NAMEOD)

re: fclean all

.PHONY: all clean fclean re
