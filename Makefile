# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2022/12/17 22:11:37 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

SRC_CLIENT =	src/client.c	\

SRC_SERVER =	src/server.c	\

CC = gcc

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIB_PATH = libft/

LIB = -Llibft -lft

INCLUDES = ./includes

CFLAGS =	-Werror -Wextra -Wall -I$(INCLUDES)

all :	$(CLIENT) $(SERVER)

$(CLIENT) :	$(OBJ_CLIENT)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB) -o $(CLIENT)

$(SERVER) :	$(OBJ_SERVER)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB) -o $(SERVER)

clean :
		$(MAKE) clean -C $(LIB_PATH)
		rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
		$(MAKE) fclean -C $(LIB_PATH)
		rm -f $(CLIENT) $(SERVER)

re : fclean $(CLIENT) $(SERVER)

PHONY: all clean fclean re
