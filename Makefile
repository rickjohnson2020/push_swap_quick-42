# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riyano <riyano@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 16:18:17 by riyano            #+#    #+#              #
#    Updated: 2025/01/29 17:16:51 by riyano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/error_utils.c srcs/sort/quick_arr.c srcs/sort/sort_main.c \
	   srcs/sort/sort_small.c srcs/sort/sort_small_helpers.c srcs/normalize.c \
	   srcs/stack/general_utils.c srcs/stack/operation_utils.c \
	   srcs/stack/push_ops.c srcs/stack/rotate_ops.c srcs/stack/r_rotate_ops.c \
	   srcs/stack/swap_ops.c srcs/sort/quick_stack.c srcs/sort/sort_chunk_small.c \
	   srcs/stack/get_node.c srcs/stack/move_chunk.c srcs/sort/quick_stack_utils.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CLAGS) $^ -o $@ -L $(LIBFT_DIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
