# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    builtins.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 11:49:45 by roliveir          #+#    #+#              #
#    Updated: 2019/06/04 17:29:45 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILTINS_PATH = ./srcs/built_in/
BUILTINS =	ft_echo.c		\
		ft_cd.c			\
		ft_env.c		\
		ft_setenv.c		\
		exec_env.c		\
		ft_setenv_eq.c		\
		ft_unsetenv.c		\
		blt_edition.c		\
		envtolst.c		\
		lsttotab.c		\
		built_manager.c		\
		cdflag.c		\
		cdpwd.c			\
		cdfunc.c		\
		envoption.c		\
		blt_history.c

BUILTINS_SRCS = $(addprefix $(BUILTINS_PATH),$(BUILTINS))
SRCS += $(BUILTINS_SRCS)
