# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/11/03 22:22:26 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** FILES  ***************************************************************** #

include libft_srcs.mk

MAKE_DIR = .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current)/

override OBJS := $(patsubst $(SRCS_DIR)%.c,$(BUILD_DIR)%.o,$(SRCS))

override DEPS := $(patsubst %.o,%.d,$(OBJS))

override DIRS := $(sort $(dir $(NAME) $(OBJS) $(DEPS)))

INCS_DIR = incs/

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror $(OFLAGS)
OFLAGS 		=	-O3

CPPFLAGS	= 	$(addprefix -I, $(INCS_DIR)) \
				-MMD -MP \

ARFLAGS 	=	rcs

MAKEFLAGS	=	--no-print-directory

# *** COMPILATION MODES ****************************************************** #

MODE_TRACE = $(MAKE_DIR).trace 
LAST_MODE = $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

ifneq ($(MODE),)
BUILD_DIR := $(BUILD_DIR)$(MODE)/
endif

ifeq ($(MODE),debug)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3
else ifeq ($(MODE),fsanitize)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3 -fsanitize=address
else ifneq ($(MODE),)
ERROR = MODE
endif

ifneq ($(LAST_MODE),$(MODE))
$(NAME) : FORCE
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS) | PREMAKE
	@echo
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(MODE)" > $(MODE_TRACE)
	@printf "\n$(BOLD)\
██╗  ██╗██████╗       ██╗     ██╗██████╗ ███████╗████████╗\n\
██║  ██║╚════██╗      ██║     ██║██╔══██╗██╔════╝╚══██╔══╝\n\
███████║ █████╔╝█████╗██║     ██║██████╔╝█████╗     ██║   \n\
╚════██║██╔═══╝ ╚════╝██║     ██║██╔══██╗██╔══╝     ██║   \n\
     ██║███████╗      ███████╗██║██████╔╝██║        ██║   \n\
     ╚═╝╚══════╝      ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   \n$(RESET)\
                                              @ibertran\n"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)

.PHONY : fclean
fclean :
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

NORM_LOG = $(MAKE_DIR)norminette.log

.PHONY : norminette
norminette :
	mkdir -p $(dir $(NORM_LOG))
	norminette $(INCS_DIR) $(SRCS_DIR) > $(NORM_LOG) || true
	if [ $$(< $(NORM_LOG) grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < $(NORM_LOG) grep Error; fi
	$(RM) $(NORM_LOG)

$(DIRS) :
	@mkdir -p $@

.PHONY : print-%
print-% :
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))


# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all

.SILENT : re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

PREMAKE :
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** FANCY STUFF ************************************************************ #

override RESET	:=	\e[0m
override BOLD	:=	\033[1m
override UNDER	:=	\033[4m
override SUR	:=	\033[7m
override GREY	:=	\033[30m
override RED	:=	\033[31m
override GREEN	:=	\033[32m
override YELLOW	:=	\033[33m
override BLUE	:=	\033[34m
override PURPLE	:=	\033[35m
override CYAN	:=	\033[36m
override WHITE	:=	\033[37m

# **************************************************************************** #
