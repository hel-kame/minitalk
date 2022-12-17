# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2022/12/17 18:08:52 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi.c			\
		ft_bzero.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_strlen.c			\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_calloc.c			\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_strjoin.c		\
		ft_substr.c			\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_putchar_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c		\
		ft_strmapi.c		\
		ft_striteri.c		\
		ft_printf.c			\
		ft_putchar.c		\
		ft_puthexa.c		\
		ft_puthexa_maj.c	\
		ft_putnbr.c			\
		ft_putstr.c			\
		ft_putunbr.c		\
		ft_print_memory.c	\

BONUS =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc

NAME = libft.a

CFLAGS =	-Werror -Wextra -Wall

all :	$(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
#		ranlib $(NAME)

clean :
		rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean $(NAME)

bonus : $(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
		ranlib $(NAME)

PHONY: all clean fclean re bonus
