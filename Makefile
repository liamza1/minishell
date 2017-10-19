# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstreak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 15:36:53 by lstreak           #+#    #+#              #
#    Updated: 2017/09/20 13:46:14 by lstreak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
PATH_SRC = ./src/
PATH_INCLUDE = ./includes/
PATH_LIB = ./libft/

INCLUDE = minishell.h

SRC = 	$(PATH_SRC)main.c	\
		$(PATH_SRC)exec_command.c	\
		$(PATH_SRC)builtin_echo.c	\
		$(PATH_SRC)envbuiltins.c	\
		$(PATH_SRC)display_prompt_msg.c	\
		$(PATH_SRC)unsetenv_builtin.c	\
		$(PATH_SRC)cd_builtin.c	\
		$(PATH_SRC)signal_handler.c	\





OSRC = main.o \
	   exec_command.o \
	   builtin_echo.o \
	   envbuiltins.o \
	   unsetenv_builtin.o \
	   display_prompt_msg.o	\
	   cd_builtin.o	\
	   signal_handler.o	\

all: $(NAME)

$(NAME):
	make -C $(PATH_LIB) fclean && make -C $(PATH_LIB)
	gcc  -Wall -Werror -Wextra -I $(PATH_INCLUDE)$(INCLUDE) -c $(SRC)
	gcc -o $(NAME) $(OSRC) -L$(PATH_LIB) -lft 

clean:
	/bin/rm -f $(OSRC)
	make -C $(PATH_LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATH_LIB) fclean

re: fclean
	make

