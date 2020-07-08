# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:30:26 by nagresel          #+#    #+#              #
#    Updated: 2020/04/18 11:41:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPLIATOR - FLAGGS -LIBFT ****************************************** #
NAME		= libasm.a
OS			= $(shell uname)
CC			= gcc
CC_L		= clang
NASM		= nasm
NA_FLAGS	= f macho64
NA_L_FLAGS	= -felf64
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f


# SRCS *********************************************************************** #
SRCS			= srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s \
				srcs/ft_write.s srcs/ft_read.s srcs/ft_strdup.s


# OBJS *********************************************************************** #

OBJS			=	${SRCS:.s=.o}

OBJSBONUS		=	${SRCSBONUS:.s=.o}


# HEADERS ******************************************************************** #
HEADER 			= includes/libasm.h 

#HEADERBONUS		= libft_bonus.h


# RULES ********************************************************************** #
.s.o:
ifeq (${OS}, Darwin)
			${NASM} ${NA_FLAGS} -s $< -o ${<:.s=.o}
else
	${NASM} ${NA_L_FLAGS} -s $< -o ${<:.s=.o}
endif

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS} ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all bonus clean fclean re
