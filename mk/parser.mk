# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:35:29 by oboutrol          #+#    #+#              #
#    Updated: 2019/07/01 11:44:47 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSER_PATH = ./srcs/parser/

PARSER_NAME =	pars.c			\
		ft_prepars.c		\
		ft_select_pars.c	\
		ft_cleans_spa.c		\
		pars_cmd.c		\
		pars_pipe.c		\
		pars_word.c		\
		pars_nword.c		\
		pars_part.c		\
		pars_red.c		\
		tool_pars.c		\
		print_tree.c		\
		free_tree.c		\
		work_tree.c		\
		pars_line.c

PARSER_SRCS = $(addprefix $(PARSER_PATH), $(PARSER_NAME))
SRCS += $(PARSER_SRCS)
