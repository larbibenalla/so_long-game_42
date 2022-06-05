# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labenall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 16:32:31 by labenall          #+#    #+#              #
#    Updated: 2022/06/01 16:55:15 by labenall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = so_long.c   utils.c splite.c malloc.c free.c cheak_map.c handler_key.c handler_a.c handler_w.c handler_s.c handler_d.c verified_map.c

OBJ = so_long.o   utils.o splite.o malloc.o free.o cheak_map.o handler_key.o handler_a.o handler_w.o handler_s.o handler_d.o verified_map.o

SRC_B = so_long_bonus.c   utils_bonus.c splite_bonus.c malloc_bonus.c free_bonus.c cheak_map_bonus.c handler_key_bonus.c handler_a_bonus.c \
handler_w_bonus.c handler_s_bonus.c handler_d_bonus.c verified_map_bonus.c itoa_bonus.c animation_bonus.c help_animation_bonus.c

OBJ_B = so_long_bonus.o   utils_bonus.o splite_bonus.o malloc_bonus.o free_bonus.o cheak_map_bonus.o handler_key_bonus.o handler_a_bonus.o \
handler_w_bonus.o handler_s_bonus.o handler_d_bonus.o verified_map_bonus.o itoa_bonus.o animation_bonus.o help_animation_bonus.o

NAME = so_long

NAME_B = so_long_bonus

HEADER = so_long.h

HEADER_B = so_long_bonus.h

all: $(NAME) $(HEADER)

bonus: $(NAME_B) $(HEADER_B)

$(NAME): $(OBJ)
	cc -Wall -Wextra -Werror $(SRC) -o $(NAME) -I $(HEADER) -lmlx -framework OpenGL -framework AppKit

$(NAME_B): $(OBJ_B)
	cc -Wall -Wextra -Werror $(SRC_B) -o $(NAME_B) -I $(HEADER_B) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJ) $(OBJ_B)
fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY:			all clean fclean re bonus
