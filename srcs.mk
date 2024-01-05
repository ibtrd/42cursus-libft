# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 06:32:49 by ibertran          #+#    #+#              #
#    Updated: 2024/01/05 06:41:56 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/
SRCS = \
	$(addprefix $(SRCS_DIR)$(MISC_DIR)ft_, $(addsuffix .c, $(SRC_LIBFT))) \
	$(addprefix $(SRCS_DIR)$(GNL_DIR), $(addsuffix .c, $(SRC_GNL))) \
	$(addprefix $(SRCS_DIR)$(PRINTF_DIR)ft_, $(addsuffix .c, $(SRC_PRINTF))) \
	$(addprefix $(SRCS_DIR)$(LST_DIR)ft_, $(addsuffix .c, $(LST_SRC))) \
	$(addprefix $(SRCS_DIR)$(CHAR_DIR)ft_, $(addsuffix .c, $(CHAR_SRC)))

# *** CHAR ******************************************************************* #

CHAR_DIR = char/
CHAR_SRC = \
	isalnum \
	isalpha \
	isascii \
	ischarset \
	isdigit \
	isprint \
	isspace \

# *** LINKED LISTS *********************************************************** #

LST_DIR = lst/
LST_SRC = \
	lstnew \
	lstadd_front \
	lstsize \
	lstlast \
	lstadd_back \
	lstdelone \
	lstclear \
	lstiter \
	lstmap \

# *** GET_NEXT_LINE ********************************************************** #

GNL_DIR = get_next_line/
SRC_GNL = \
	get_next_line \
	get_next_line_utils \
	get_next_line_multifd \

# *** FT_PRINTF ************************************************************** #

PRINTF_DIR = ft_printf/
SRC_PRINTF = \
			printf dprintf format \
			convert_char convert_string \
			convert_decimal convert_decimal_utils \
			convert_unsigned_decimal \
			convert_pointer convert_pointer_utils \
			convert_lower_hexa convert_upper_hexa \
			convert_percent

# *** MISCELLANEOUS ********************************************************** #

MISC_DIR	=	misc/
SRC_LIBFT	=	strlen memset bzero \
				memcpy memmove strlcpy strlcat toupper tolower strchr strrchr \
				strncmp memchr memcmp strnstr atoi calloc strdup \
				substr strjoin strtrim split itoa strmapi striteri putchar_fd \
				putstr_fd putendl_fd putnbr_fd itoalen isrange \
				strcmp




