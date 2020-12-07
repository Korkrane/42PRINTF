# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 13:21:04 by bahaas            #+#    #+#              #
#    Updated: 2020/12/07 15:24:59 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS_D	= srcs
INC_D	= includes
LIB_D	= libft
SRCS	= c_convert.c s_convert.c percent_convert.c p_convert.c x_convert.c\
		  X_convert.c d_convert.c i_convert.c u_convert.c check_options.c\
		  select_conversion.c ft_printf.c utils.c
SRCS_O	= c_convert.o
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS	= ${addprefix ${SRCS_D}/,${SRCS:.c=.o}}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${LIB_D}
			cp ${LIB_D}/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}
			make clean -C ${LIB_D}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIB_D}

re:			fclean all

.PHONY:		all clean fclean re
