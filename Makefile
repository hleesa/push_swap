# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 16:18:40 by salee2            #+#    #+#              #
#    Updated: 2022/08/27 16:18:43 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS = \
	add.c \
	create_node.c \
	get_num_of_rotate.c \
	init.c \
	is.c \
	peek.c \
	pop.c \
	push.c \
	push_swap.c \
	reverse_rotate.c \
	rotate.c \
	swap.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFTFILE) $(NAME)

$(LIBFTFILE) :
	make -C $(LIBFTDIR)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
