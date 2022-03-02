# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/15 21:27:29 by mlothair          #+#    #+#             #
#   Updated: 2021/11/15 21:27:29 by mlothair         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

SRC = main.c utils.c sort_counters.c chunk_sorting.c rotate_to_positions.c stack_operation.c stack_operation_more.c insertion.c main_commands.c
OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC = gcc

CFLAGS  = -Wall -Wextra -Werror -MMD

LIBFT = libft/libft.a

TARGET = push_swap

all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJS)
	$(CC) $(LIBFT) $(CFLAGS) $(OBJS) -o $@

$(LIBFT):
	 $(MAKE) all bonus -C libft

.PHONY: clean fclean all re

-include $(DEPS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(TARGET)

re: fclean all