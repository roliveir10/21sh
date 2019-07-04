# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:38:11 by oboutrol          #+#    #+#              #
#    Updated: 2019/06/15 10:40:57 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_PATH = ./srcs/exec/

EXEC_NAME = 	ft_exec.c		\
		ft_exec_tool.c		\
		ft_launch_cmd.c		\
		init_exe.c		\
		ft_split_path.c		\
		ft_free_exe.c		\
		ft_pipe_close.c		\
		ft_error.c		\
		ft_add_red.c		\
		ft_launch_red.c		\
		ft_heredoc.c		\
		ft_launch_pipe.c	\
		ft_pile.c		\
		exec_cmd.c		\
		ft_expend.c		\
		ft_expend_tool.c	\
		do_dup_pile.c		\
		ft_path.c

EXEC_SRCS = $(addprefix $(EXEC_PATH),$(EXEC_NAME))
SRCS += $(EXEC_SRCS)
