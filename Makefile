# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschramm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 13:49:19 by rschramm          #+#    #+#              #
#    Updated: 2016/12/30 12:52:29 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -o
CC = g++

SRC = src/

NAME = fillit

SRCS =	   src/main.cpp \
		   src/raw_block.cpp \
		   src/val_block.cpp \

all: $(NAME)

RM = rm -f

$(NAME):
	$(CC) -L /opt/boost_1_61_0/libs -I /opt/boost_1_61_0/ $(CFLAGS) $(NAME) $(SRCS)

clean:
	@rm -rf *.o

fclean: clean
	@$(COMP)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
