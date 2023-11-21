# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2023/11/21 22:03:07 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

SRC_LIBFT	=	isalpha isdigit isalnum isascii isprint strlen memset bzero    \
				memcpy memmove strlcpy strlcat toupper tolower strchr strrchr  \
				strncmp memchr memcmp strnstr atoi calloc strdup			   \
				substr strjoin strtrim split itoa strmapi striteri putchar_fd  \
				putstr_fd putendl_fd putnbr_fd								   \
				lstnew lstadd_front lstsize lstlast lstadd_back lstdelone      \
				lstclear lstiter lstmap

SRC_GNL		=	get_next_line get_next_line_utils

SRC			=	putnbrbase_fd ischarset

SRCS 		=	$(addprefix ft_, $(addsuffix .c, $(SRC_LIBFT)))                \
				$(addsuffix .c, $(SRC_GNL))									   \
				$(addprefix ft_, $(addsuffix .c, $(SRC)))					   \
				

# *** OBJECTS & DEPENDENCIES ************************************************* #

BUILD_DIR	=	.build/

OBJS 		=	$(SRCS:%.c=$(BUILD_DIR)%.o)

DEPS        =	$(OBJS:%.o=%.d)

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

.PHONY : all clean fclean re

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m