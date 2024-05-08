# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                           :+:      :+:    :+:    #
#                                                         (@)-=-(@)            #
#    By: fwhite42 <FUCK THE NORM>                          (  o  )             #
#                                                        _/'-----'\_           #
#    Created: 2024/02/17 06:39:55 by fwhite42          \\ \\     // //         #
#    Updated: 2024/03/29 18:11:47 by fwhite42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		:= libftprintf.a
HEADER		:= libftprintf.h
# **************************************************************************** #
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I.

AR			:= ar
ARFLAGS		:= -rcs
# **************************************************************************** #
define	FILES
	ft_printf				\
	ftpf_format				\
	ftpf_load_printer		\
	ftpf_print_c			\
	ftpf_print_escape		\
	ftpf_print_i			\
	ftpf_print_p			\
	ftpf_print_s			\
	ftpf_print_u			\
	ftpf_print_x_lc			\
	ftpf_print_x_uc			\
	ftpf_character_utils	\
	ftpf_number_utils		\
	ftpf_read_write_utils
endef
vpath %.c source
vpath %.h include
# **************************************************************************** #

all: $(NAME)

bonus: all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

$(NAME):
	$(MAKE) re

re : $(HEADER) $(NAME)($(FILES:%=%.o))
