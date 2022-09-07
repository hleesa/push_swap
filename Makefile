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
PRINTFDIR	:= ./ft_printf
PRINTFFILE	:= libftprintf.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(PRINTFDIR)
AR			:= ar rcs
RM			:= rm -f

SRCS = \
	add.c \
	free.c \
	get.c \
	init.c \
	is.c \
	lis.c \
	main.c	\
	peek.c \
	pop.c \
	push.c \
	push_swap.c \
	reverse_rotate.c \
	rotate.c \
	set_table.c \
	sort.c \
	stack.c \
	swap.c \
	table.c \

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	$(RM) $(OBJS) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
