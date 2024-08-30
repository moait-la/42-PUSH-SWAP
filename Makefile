# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 19:43:08 by moait-la          #+#    #+#              #
#    Updated: 2024/01/31 20:39:07 by moait-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Mandatory/bring_totop.c Mandatory/check_ifvalid.c Mandatory/error.c Mandatory/push.c \
		Mandatory/reverse_rotate.c Mandatory/rotate.c Mandatory/set_values.c \
		Mandatory/sort.c Mandatory/stack_utils.c Mandatory/swap.c Mandatory/utils.c Mandatory/main.c \
		libft/ft_split.c libft/ft_strjoin.c libft/ft_isdigit.c libft/ft_strdup.c libft/ft_memcpy.c libft/ft_strlen.c

BONUS_SRCS= Bonus/actions.c Bonus/bonus_utils.c Bonus/is_action_valid.c Bonus/check_ifvalid.c Bonus/checker.c Bonus/error_bonus.c \
			Bonus/excute_actions.c Bonus/stack_utils.c Bonus/strjoin.c get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c \
			libft/ft_strncmp.c

OBJ = ${SRCS:.c=.o}
BONUS_OBJ = ${BONUS_SRCS:.c=.o}

NAME = push_swap
BONUS_NAME = checker

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ./Includes/push_swap.h ./Includes/get_next_line.h ./libft/libft.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

bonus: ${BONUS_OBJ}
	${CC} ${BONUS_OBJ} -o ${BONUS_NAME}

clean:
	${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: clean