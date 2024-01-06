# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/01/06 08:11:18 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

-include srcs.mk

# *** OBJECTS & DEPENDENCIES ************************************************* #

ifndef DEBUG
BUILD_DIR = .build/
else
BUILD_DIR = .build/debug/
endif

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

HEADERS		=	incs/

# *** TRACE ****************************************************************** #

TRACE_DIR = .build/.trace/
STD_TRACE = $(TRACE_DIR)std/
DEBUG_TRACE = $(TRACE_DIR)debug/

ifndef DEBUG
TRACE =	$(STD_TRACE)
else
TRACE = $(DEBUG_TRACE)
endif

# *** CONFIG ***************************************************************** #

ifndef DEBUG
CC_OPTION = -O3
else
CC_OPTION = -g3
endif

CFLAGS		=	-Wall -Wextra -Werror $(CC_OPTION) -MMD -MP

CPPFLAGS 	=	$(addprefix -I, $(HEADERS))

AR			=	ar rc

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

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
	$(MKDIR)
	touch $@

-include $(DEPS)

clean :
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"
	
re : fclean
	$(MAKE) --no-print-directory

debug :
	$(MAKE) DEBUG=1

norminette :
	mkdir -p $(BUILD_DIR)
	norminette $(HEADERS) $(SRCS_DIR) > $(BUILD_DIR)norminette.log; echo -n
	echo "$(NAME):"
	if [ $$(< $(BUILD_DIR)norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "Norm check OK!"; \
		else < $(BUILD_DIR)norminette.log grep Error; fi

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re debug norminette
.SILENT : clean fclean re debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m