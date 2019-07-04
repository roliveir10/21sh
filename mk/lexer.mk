# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lexer.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:29:33 by oboutrol          #+#    #+#              #
#    Updated: 2019/06/15 20:30:34 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_PATH = ./srcs/lexer/
LEXER_NAME = lex.c		\
		ft_init.c	\
		process.c	\
		get_ch.c	\
		more.c		\
		add_char.c	\
		print_state.c	\
		ft_free_stat.c	\
		ft_free_token.c	\
		get_state.c

LEXER_SRCS = $(addprefix $(LEXER_PATH),$(LEXER_NAME))
SRCS += $(LEXER_SRCS)
