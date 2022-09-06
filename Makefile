# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 16:18:40 by salee2            #+#    #+#              #
#    Updated: 2022/08/27 19:50:08 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
LIBFTDIR	:= ./libft
LIBFTFILE	:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(LIBFTDIR)
AR			:= ar rcs
RM			:= rm -f

SRCS = \
	add.c \
	get.c \
	init.c \
	is.c \
	lis.c \
	main.c	\
	peek.c \
	pop.c \
	print.c \
	push.c \
	push_swap.c \
	reverse_rotate.c \
	rotate.c \
	sort.c \
	stack.c \
	swap.c \
	table.c \

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFTDIR)/$(LIBFTFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(LIBFTFILE)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
