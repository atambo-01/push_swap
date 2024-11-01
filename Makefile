# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:22:37 by atambo            #+#    #+#              #
#    Updated: 2024/10/08 19:49:27 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES         =	./sources/check_input_01.c \
					./sources/check_input_02.c \
					./sources/ft_atoi_ps.c \
					./sources/ft_split_ps.c \
					./sources/higher_sort.c \
					./sources/lesser_sort.c \
					./sources/list_utils.c \
					./sources/main.c \
					./sources/operations_01.c \
					./sources/operations_02.c \
					./sources/operations_03.c \
					./sources/push_swap_utils.c \
					./sources/short_forms_01.c \
					./sources/short_forms_02.c \
					./sources/sort_6_plus.c \
					./sources/sort_b_3.c \
					
					
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
NAME            = push_swap
OBJS            = $(SOURCES:.c=.o)
INCLUDES        = -Iincludes

SUBDIRS         = ./sources/ft_printf ./sources/libft

LIBS            = ./sources/ft_printf/ft_printf.a ./sources/libft/libft.a

all: submake $(NAME)

submake:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all submake clean fclean re

