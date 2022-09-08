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
BONUS		:= cchecker

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(PRINTFDIR)
AR			:= ar rcs
RM			:= rm -f

SRCS_COMMON = \
	add.c \
	free.c \
	get.c \
	init.c \
	is.c \
	lis.c \
	peek.c \
	pop.c \

SRCS_MANDA = \
	main.c \
	push.c \
	push_swap.c \
    reverse_rotate.c \
    rotate.c \
    set_table.c \
    sort.c \
    stack.c \
    swap.c \
    table.c \
    $(SRCS_COMMON) \

SRCS_BONUS = \
	bonus_main.c \
	bonus_push.c \
	bonus_reverse_rotate.c \
	bonus_rotate.c \
	bonus_swap.c \
	checker.c \
	$(SRCS_COMMON) \

OBJS_MANDA = $(SRCS_MANDA:c=o)
OBJS_BONUS = $(SRCS_BONUS:c=o)

all: $(NAME)

$(NAME): $(OBJS_MANDA)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

bonus: $(OBJS_BONUS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $(BONUS) $^ $(PRINTFDIR)/$(PRINTFFILE)

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
