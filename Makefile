# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 11:21:01 by sehhong           #+#    #+#              #
#    Updated: 2021/09/16 15:31:46 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = ./libft/
LIBFT_LIB = ft

SRCS_DIR = ./srcs/
INCL_DIR = ./includes/

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

FILES_M =  $(addprefix $(SRCS_DIR), \
			arg_parser.c cmd_split.c error_checker.c execve.c exit_macros.c \
			fork.c pipex.c wait_and_exit.c cmd_split.c)
OBJS_M = $(FILES_M:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS_M)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_LIB) $(OBJS_M) -o $(NAME) 

clean:
	$(RM) $(OBJS_M)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all 

.PHONY: all bonus clean fclean re
