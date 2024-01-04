# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/01/04 09:22:18 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** SOURCES **************************************************************** #

MISC_DIR	=	misc/
SRC_LIBFT	=	isalpha isdigit isalnum isascii isprint strlen memset bzero \
				memcpy memmove strlcpy strlcat toupper tolower strchr strrchr \
				strncmp memchr memcmp strnstr atoi calloc strdup isspace \
				substr strjoin strtrim split itoa strmapi striteri putchar_fd \
				putstr_fd putendl_fd putnbr_fd ischarset itoalen isrange \
				strcmp

GNL_DIR		=	get_next_line/
SRC_GNL		=	get_next_line get_next_line_utils get_next_line_multifd

PRINTF_DIR	=	ft_printf/
SRC_PRINTF	=	printf dprintf format \
				convert_char convert_string \
				convert_decimal convert_decimal_utils \
				convert_unsigned_decimal \
				convert_pointer convert_pointer_utils \
				convert_lower_hexa convert_upper_hexa \
				convert_percent

LST_DIR		=	lst/
LST_SRC		=	lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
				lstclear lstiter lstmap

SRCS_DIR	=	srcs/
SRCS 		=	$(addprefix $(SRCS_DIR)$(MISC_DIR)ft_, $(addsuffix .c, $(SRC_LIBFT))) \
				$(addprefix $(SRCS_DIR)$(GNL_DIR), $(addsuffix .c, $(SRC_GNL))) \
				$(addprefix $(SRCS_DIR)$(PRINTF_DIR)ft_, $(addsuffix .c, $(SRC_PRINTF))) \
				$(addprefix $(SRCS_DIR)$(LST_DIR)ft_, $(addsuffix .c, $(LST_SRC))) \

# *** OBJECTS & DEPENDENCIES ************************************************* #

BUILD_DIR	=	.build/

OBJS 		=	$(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS        =	$(OBJS:%.o=%.d)

INCLUDE		=	incs/

# *** COMMANDS **************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3
CPPFLAGS 	=	-MMD -MP $(addprefix -I, $(INCLUDE))

AR			=	ar
ARFLAGS		=	rcs

RM			=	rm -rf

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@if [ ! -d "$(@D)" ]; then $(MKDIR); fi
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean :
	$(RM) $(BUILD_DIR)
	@echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	$(RM) $(BUILD_DIR)
	$(RM) $(NAME)
	@echo "$(YELLOW) $(NAME) files removed! $(RESET)"
	
re : fclean
	$(MAKE)

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m