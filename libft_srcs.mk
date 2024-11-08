# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_srcs.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 06:32:49 by ibertran          #+#    #+#              #
#    Updated: 2024/11/03 21:37:46 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

override SRCS_DIR = srcs/
override SRCS = \
	$(addprefix $(SRCS_DIR),$(SRC))	

# *** CHAR ******************************************************************* #

SRC += $(addprefix $(CHAR_DIR)ft_, $(addsuffix .c, $(CHAR_SRC))) \

override CHAR_DIR := char/
override CHAR_SRC := \
	isalnum \
	isalpha \
	isascii \
	ischarset \
	isdigit \
	isprint \
	isspace \
	tolower \
	toupper \

# *** STRING ***************************************************************** #

SRC += $(addprefix $(STR_DIR)ft_, $(addsuffix .c, $(STR_SRC)))

override STR_DIR := str/
override STR_SRC := \
	countwords \
	generate_rand_str \
	isnumber \
	split \
	str_in_array \
	strchr \
	strcmp \
	strcpy \
	strdup \
	striteri \
	strjoin \
	strjoin2 \
	strlcat \
	strlcpy \
	strlen \
	strmapi \
	strncmp \
	strndup \
	strnstr \
	strpbrk \
	strrchr \
	strtok \
	strtrim \
	substr \

# *** INTERGER *************************************************************** #

SRC += $(addprefix $(INT_DIR)ft_, $(addsuffix .c, $(INT_SRC)))

override INT_DIR := int/
override INT_SRC := \
	abs \
	atoi \
	fabs \
	isrange \
	itoa \
	itoalen \
	strtoi \
	strtol \

# *** MEMORY ***************************************************************** #

SRC += $(addprefix $(MEM_DIR)ft_, $(addsuffix .c, $(MEM_SRC)))

override MEM_DIR := mem/
override MEM_SRC := \
	bzero \
	calloc \
	fmalloc \
	memchr \
	memcmp \
	memcpy \
	memcpy2 \
	memmove \
	memset \

# *** VECTOR ***************************************************************** #

SRC += $(addprefix $(VECTOR_DIR)ft_,$(addsuffix .c, $(VECTOR_SRC)))

override VECTOR_DIR := vector/
override VECTOR_SRC := \
	vector_add \
	vector_add_ptr \
	vector_alloc \
	vector_dealloc \
	vector_delete \
	vector_deleten \
	vector_free \
	vector_get \
	vector_init \
	vector_insert \
	vector_insert_ptr \
	vector_insertn \
	vector_join \
	vector_merge \
	vector_print \
	vector_replace \
	vector_resize \
	vector_search \
	vector_set \
	vector_set_ptr \
	vector_setn \
	vector_split \
	vector_strncat \
	vector_trim \
	vector_unlink \
	vector_sort \

SRC += $(addprefix $(VUTILS_DIR)ft_,$(addsuffix .c, $(VUTILS_SRC)))

override VUTILS_DIR := $(VECTOR_DIR)utility/
override VUTILS_SRC := \
	vclose \
	vfree \
	vprint_char \
	vprint_int \
	vprint_vchar \
	vprint_str \
	vvector_free \
	vsort_intascend \

# *** LINKED LIST ************************************************************ #

SRC += $(addprefix $(LST_DIR)ft_, $(addsuffix .c, $(LST_SRC)))

override LST_DIR := lst/
override LST_SRC := \
	lstadd_back \
	lstadd_front \
	lstclear \
	lstdelone \
	lstiter \
	lstlast \
	lstmap \
	lstnew \
	lstsize \

# *** GET_NEXT_LINE ********************************************************** #

SRC += $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_SRC)))

override GNL_DIR := get_next_line/
override GNL_SRC := \
	get_next_line \

# *** GET_FD_CONTENT ********************************************************* #

SRC += $(addprefix $(GFC_DIR), $(addsuffix .c, $(GFC_SRC)))

override GFC_DIR := get_fd_content/
override GFC_SRC := \
	get_fd_content \

# *** FT_PRINTF ************************************************************** #

SRC += $(addprefix $(PRINTF_DIR)ft_, $(addsuffix .c, $(PRINTF_SRC)))

override PRINTF_DIR := ft_printf/
override PRINTF_SRC := \
	converter/convert_char \
	converter/convert_hexlow \
	converter/convert_hexup \
	converter/convert_int \
	converter/convert_percent \
	converter/convert_string \
	converter/convert_uint \
	addconversion \
	dprintf \
	pf_build_buffer \
	pf_print_buffer \
	sprintf \

# *** MISCELLANEOUS ********************************************************** #

SRC += $(addprefix $(MISC_DIR)ft_, $(addsuffix .c, $(MISC_SRC)))

override MISC_DIR := misc/
override MISC_SRC := \
	close \
	free_array \
	free_2darray_char \
	tmp_file \
