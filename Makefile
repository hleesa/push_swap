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

NAME		= push_swap
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a
BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(PRINTFDIR)
AR			= ar rcs
RM			= rm -f

SRCS_COMMON = \
	add.c \
	free.c \
	get.c \
	init.c \
	is.c \
	lis.c \
	peek.c \
	pop.c \
	print.c \
    stack.c \
	push.c \
    sort.c \
    reverse_rotate.c \
    rotate.c \
    swap.c \

SRCS_MANDA = \
	main.c \
    set_table.c \
    table.c \
	push_swap.c \

SRCS_BONUS = \
	bonus_main.c \
	bonus_push.c \
	bonus_reverse_rotate.c \
	bonus_rotate.c \
	bonus_swap.c \
	bonus_checker.c \

OBJS_MANDA = $(SRCS_COMMON:c=o) $(SRCS_MANDA:c=o)
OBJS_BONUS = $(SRCS_COMMON:c=o) $(SRCS_BONUS:c=o)

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJS_MANDA)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

$(BONUS): $(OBJS_BONUS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	$(RM) $(OBJS_MANDA) $(OBJS_BONUS) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME) $(BONUS)

re: fclean
	make all

.PHONY: all bonus clean fclean re
