# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstreak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 11:41:39 by lstreak           #+#    #+#              #
#    Updated: 2017/09/20 13:55:45 by lstreak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_SRC = ./
PATH_INCLUDE = ./

SRC = ft_isemptystr.c ./ft_strreplace.c ./ft_realloc.c ./ft_freestrarr.c ./ft_countwordsall.c ./ft_strendswith.c ./ft_pathjoin.c ./ft_putnstr.c ./ft_strstartswith.c ./ft_strsplitall.c ./ft_strjoinch.c ./ft_strjoincl.c ./ft_strjoinchcl.c ./ft_strstart.c ./ft_isprint.c	./ft_memmove.c	./ft_putstr.c	./ft_strdup.c	./ft_strmapi.c	./ft_strsplit.c	\
./ft_itoa.c	./ft_memset.c	./ft_putstr_fd.c	./ft_strequ.c	./ft_strncat.c	./ft_strstr.c \
./ft_atoi.c	./ft_memalloc.c	./ft_putchar.c	./ft_strcat.c	./ft_striter.c	./ft_strncmp.c	./ft_strsub.c\
./ft_bzero.c	./ft_memccpy.c	./ft_putchar_fd.c	./ft_strchr.c	./ft_striteri.c	./ft_strncpy.c	./ft_strtrim.c \
./ft_isalnum.c	./ft_memchr.c	./ft_putendl.c	./ft_strclr.c	./ft_strjoin.c	./ft_strnequ.c	./ft_tolower.c \
./ft_isalpha.c	./ft_memcmp.c	./ft_putendl_fd.c	./ft_strcmp.c	./ft_strlcat.c	./ft_strnew.c	./ft_toupper.c \
./ft_isascii.c	./ft_memcpy.c	./ft_putnbr.c	./ft_strcpy.c	./ft_strlen.c	./ft_strnstr.c	./ft_wordc.c \
./ft_isdigit.c	./ft_memdel.c	./ft_putnbr_fd.c	./ft_strdel.c	./ft_strmap.c	./ft_strrchr.c	./ft_charcount.c \
./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c get_next_line.c ./ft_free2d.c\

OSRC = ./ft_isemptystr.o ./ft_strreplace.o  ./ft_realloc.o ./ft_freestrarr.o ./ft_countwordsall.o ./ft_strendswith.o ./ft_pathjoin.o ./ft_putnstr.o ./ft_strstartswith.o ./ft_strjoincl.o ./ft_strsplitall.o ./ft_strjoinch.o ./ft_strjoinchcl.o ./ft_strstart.o ./ft_atoi.o ./ft_bzero.o ./ft_isalnum.o ./ft_isalpha.o ./ft_isascii.o \
	   ./ft_isdigit.o ./ft_isprint.o ./ft_itoa.o ./ft_memalloc.o ./ft_memccpy.o \
	   ./ft_memchr.o ./ft_memcmp.o ./ft_memcpy.o ./ft_memdel.o ./ft_memmove.o ./ft_free2d.o \
	   ./ft_memset.o ./ft_putchar.o ./ft_putchar_fd.o ./ft_putendl.o ./ft_putendl_fd.o \
	   ./ft_putnbr.o ./ft_putnbr_fd.o ./ft_putstr.o ./ft_putstr_fd.o ./ft_strcat.o \
	   ./ft_strchr.o ./ft_strclr.o ./ft_strcmp.o ./ft_strcpy.o ./ft_strdel.o \
	   ./ft_strdup.o ./ft_strequ.o ./ft_striter.o ./ft_striteri.o ./ft_strjoin.o \
	   ./ft_strlcat.o ./ft_strlen.o ./ft_strmap.o ./ft_strmapi.o ./ft_strncat.o \
   	   ./ft_strncmp.o ./ft_strncpy.o ./ft_strnequ.o ./ft_strnew.o ./ft_strnstr.o \
	   ./ft_strrchr.o ./ft_strsplit.o ./ft_strstr.o ./ft_strsub.o ./ft_strtrim.o \
	   ./ft_tolower.o ./ft_toupper.o ./ft_charcount.o ./ft_wordc.o ./ft_lstnew.o ./ft_lstdelone.o \
	   ./ft_lstdel.o ./ft_lstadd.o ./ft_lstiter.o ./ft_lstmap.o get_next_line.o \

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OSRC) 
	ranlib $(NAME)

clean:
	/bin/rm -f $(OSRC)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

