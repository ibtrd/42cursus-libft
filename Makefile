# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/01/08 19:20:00 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

include srcs.mk

# *** OBJECTS & DEPENDENCIES ************************************************* #

BUILD_DIR := .build/

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

HEADERS		=	incs/

# *** TRACE ****************************************************************** #

TRACE_DIR = .trace/

STD_TRACE = $(TRACE_DIR)
DEBUG_TRACE = $(TRACE_DIR)debug_

TRACE =	$(STD_TRACE)

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror -O3 -MMD -MP

CPPFLAGS 	=	$(addprefix -I, $(HEADERS))

AR			=	ar rc

MKDIR 		= 	mkdir -p $(@D)

MAKE 		+= -j --no-print-directory

# *** DEBUG ****************************************************************** #

ifdef DEBUG
BUILD_DIR := $(BUILD_DIR)debug/
TRACE = $(DEBUG_TRACE)
CFLAGS := $(filter-out -O3,$(CFLAGS)) -g3
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS) $(addsuffix $(NAME), $(TRACE))
	$(AR) $(NAME) $(OBJS)
ifndef DEBUG
	@$(RM) $(DEBUG_TRACE)$@
	@echo "$(BLUE) $(NAME) has been built! $(RESET)"
else
	@$(RM) $(STD_TRACE)$@
	@echo "$(BLUE) $(NAME)(DEBUG) has been built! $(RESET)"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TRACE)% :
	@$(MKDIR)
	@touch $@

-include $(DEPS)

.PHONY : clean
clean :
	$(RM) norminette.log
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	$(RM) norminette.log
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE) all

.PHONY : debug
debug :
	$(MAKE) DEBUG=1

.PHONY : %debug
%debug :
	$(MAKE) $(subst debug,,$@) DEBUG=1

.PHONY : norminette
norminette :
	norminette $(HEADERS) $(SRCS_DIR) > norminette.log; echo -n
	echo "$(NAME):"
	if [ $$(< norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "Norm check OK!"; \
		else < norminette.log grep Error; fi

# *** SPECIAL TARGETS ******************************************************** #

.SILENT : clean fclean re debug %debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m