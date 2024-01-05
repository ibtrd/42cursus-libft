# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/01/05 07:10:21 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

-include srcs.mk

# *** OBJECTS & DEPENDENCIES ************************************************* #

BUILD_DIR	=	.build/
OBJS 		=	$(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS        =	$(OBJS:%.o=%.d)

INCLUDES		=	incs/

# *** CONFIG ***************************************************************** #

CC_OPTION	= 	-O3
CFLAGS		=	-Wall -Wextra -Werror $(CC_OPTION) -MMD -MP

CPPFLAGS 	=	$(addprefix -I, $(INCLUDES))

AR			=	ar
ARFLAGS		=	rcs

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(BLUE) $(NAME) has been built! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean :
	rm -rf $(BUILD_DIR)
	@echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME)
	@echo "$(YELLOW) $(NAME) files removed! $(RESET)"
	
re : fclean
	$(MAKE)

debug :
	$(MAKE) CC_OPTION="-g3" BUILD_DIR=".build/debug/"

norminette :
	norminette $(SRCS_DIR)

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m