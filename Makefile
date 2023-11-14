# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2023/11/14 19:51:37 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

SRC_PART1	=	isalpha isdigit isalnum isascii isprint strlen memset bzero    \
				memcpy memmove strlcpy strlcat toupper tolower strchr strrchr  \
				strncmp memchr memcmp strnstr atoi calloc strdup
				
SRC_PART2	=	substr strjoin strtrim split itoa strmapi striteri putchar_fd  \
				putstr_fd putendl_fd putnbr_fd

SRC_BONUS	=	lstnew lstadd_front lstsize lstlast lstadd_back lstdelone      \
				lstclear lstiter lstmap

SRCS 		=	$(addprefix ft_, $(addsuffix .c, $(SRC_PART2)))                \
				$(addprefix ft_, $(addsuffix .c, $(SRC_PART1)))
				
SRCS_BONUS	=	$(addprefix ft_, $(addsuffix _bonus.c, $(SRC_BONUS)))

# *** OBJECTS & DEPENDENCIES ************************************************* #

BUILD_DIR	=	.build/

OBJS 		=	$(SRCS:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)

DEPS        =	$(OBJS:%.o=%.d)
DEPS_BONUS	=	$(OBJS_BONUS:%.o=%.d)

# *** CONFIG ***************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS 	=	-MMD -MP

AR			=	ar
ARFLAGS		=	rcs

RM			=	rm -f

MKDIR 		= 	mkdir -p $(@D)
RMDIR		= 	rmdir

# *** TARGETS **************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(BLUE) Building $(NAME)... $(RESET)"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"

$(BUILD_DIR)%.o : %.c
	@if [ ! -d "$(@D)" ]; then $(MKDIR); fi
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

bonus :
	$(MAKE) SRCS="$(SRCS) $(SRCS_BONUS)"

-include $(DEPS)

clean :
	@echo "$(YELLOW) Removing building files... $(RESET)"
	$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	if [ -d "$(BUILD_DIR)" ]; then $(RMDIR) $(BUILD_DIR); fi
	@echo "$(YELLOW) Building files removed! $(RESET)"
	
fclean : clean
	$(RM) $(NAME)
	@echo "$(YELLOW) $(NAME) removed... $(RESET)"
	
re : fclean all

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all bonus clean fclean re

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m