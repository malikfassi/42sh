# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2014/03/01 22:12:33 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

SRC_FILES = main.c free_arr.c search_path.c \
			sh_env.c sh_cd1.c sh_cd2.c sh_utils.c \
			sh_setenv.c sh_unsetenv.c

LPATH = -L./libs/libft -lft\
		-L./libs/libprt -lprt\
		-L./libs/libgnl -lgnl

HPATH = -I./includes\
		-I./libs/libft/includes\
		-I./libs/libprt/includes\
		-I./libs/libgnl/includes

CFLAGS = gcc -Wall -Wextra -Werror
SRC_PATH = ./srcs/

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NOCOLOR = "\x1b[0m"


##START RULES
.PHONY: all clean fclean re compile_lib clean_lib fclean_lib

all: compile_lib $(NAME)

$(NAME): $(SRCS)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation of $(NAME)
	@$(CFLAGS) $(HPATH) $(LPATH) $(SRCS) -o $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation done !

clean: clean_lib
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJS)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !

fclean: fclean_lib
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJS)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting done !

re:	fclean all

###lib dependencies

compile_lib:
	@make -C libs/libft
	@make -C libs/libprt
	@make -C libs/libgnl

clean_lib:
	@make -C libs/libft clean
	@make -C libs/librt clean
	@make -C libs/libgnl clean

fclean_lib:
	@make -C libs/libft fclean
	@make -C libs/libprt fclean
	@make -C libs/libgnl fclean
