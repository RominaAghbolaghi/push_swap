# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:32:52 by rmohamma          #+#    #+#              #
#    Updated: 2023/02/10 14:37:40 by rmohamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS			= checker

CC				= gcc -g3
FLAGS			= -Wall -Wextra -Werror -g

L_FT			= ./libft
L_GNL			= ./GNL

SRC_1 = mandatory/main.c
SRC_2	= \
		mandatory/argv_verifier.c \
		mandatory/calculation.c \
		mandatory/create_stack.c \
		mandatory/linked_list_ops.c \
		mandatory/move.c  \
		mandatory/push_ops.c \
		mandatory/reverse_rotate_ops.c \
		mandatory/push_swap.c \
		mandatory/check_ops.c \
		mandatory/create_stack_utils.c \
		mandatory/index_ops.c \
		mandatory/sort_three.c \
		mandatory/rotate_ops.c \
		mandatory/swap_ops.c

BONUS_SRC = bonus/checker_bonus.c \
					bonus/checker_utils_bonus.c \
					bonus/main_bonus.c

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ	= ${BONUS_SRC:.c=.o}

INC_L_FT	= -L ${L_FT} -lft
INC_L_GNL	= -L ${L_GNL} -lgnl

.c.o:
	${CC} -c $< -o ${<:.c=.o}

all: ${NAME} ${BONUS}
mandatory: ${NAME}
bonus: ${BONUS}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(L_FT)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INC_L_FT}

${BONUS}: ${BONUS_OBJ} ${OBJ_2}
	make  -C $(L_FT)
	make  -C $(L_GNL)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INC_L_FT} ${INC_L_GNL}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(L_FT) && $(MAKE) clean
	@cd $(L_GNL) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(L_FT) && $(MAKE) fclean
	@cd $(L_GNL) && $(MAKE) fclean

re: fclean all
remandatory : fclean mandatory
rebonus: fclean bonus


test2:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


test3:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


test5:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


test100:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
