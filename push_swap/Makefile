# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclement <dclement@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 15:45:57 by dclement          #+#    #+#              #
#    Updated: 2024/11/11 11:59:51 by dclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I./libft -I./ft_printf -I.

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ./ft_printf/

FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

SRC = main.c check_cheapest.c check_min_max_a.c list_a.c\
		find_cheapest.c check_min_max_b.c\
		list_b.c sort.c sort_three.c sort_four.c sort_five.c\
		swap_nodes.c rotate.c reverse_rotate.c push.c\
		int_parse.c new_in_a.c new_min_max_b.c sort_two.c\
		move_back.c new_min_max_a.c free_all.c

OBJ = $(SRC:.c=.o)

NAME = push_swap.a

EXEC_NAME = push_swap

all: $(LIBFT) $(FT_PRINTF) $(NAME) $(EXEC_NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)
		@echo "\n$(G)Push_swap library compiled!$(DEF_COLOR)-> $(NAME)\n"

$(EXEC_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXEC_NAME) $(OBJ) $(FT_PRINTF) $(LIBFT)
	@echo "\n$(G)Push_swap executable compiled!$(DEF_COLOR)-> push_swap\n"
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@rm -f $(OBJ)
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@rm -f $(NAME) $(EXEC_NAME)
re: fclean all

.PHONY: all clean fclean re