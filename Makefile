# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2022/12/20 16:14:18 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

SRC_CLIENT =	src/client.c

SRC_SERVER =	src/server.c

BONUS_CLIENT =	bonus/client_bonus.c

BONUS_SERVER =	bonus/server_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(BONUS_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(BONUS_SERVER:.c=.o)

CC = gcc

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

bonus :	$(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIB) -o $(CLIENT)
			$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIB) -o $(SERVER)

clean :
		$(MAKE) clean -C $(LIB_PATH)
		rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean : clean
		$(MAKE) fclean -C $(LIB_PATH)
		rm -f $(CLIENT) $(SERVER)

re : fclean $(CLIENT) $(SERVER)

PHONY: all clean fclean re
