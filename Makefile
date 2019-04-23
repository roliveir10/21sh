# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 01:21:35 by roliveir          #+#    #+#              #
#    Updated: 2019/04/23 20:02:29 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

INC_PATH = includes/
LIB_INC_PATH = libft/includes/
OBJ_PATH = objs/
SRC_LEX_PATH = srcs/lexer/
SRC_PARS_PATH = srcs/parser/
SRC_EXEC_PATH = srcs/exec/
SRC_LINE_PATH = srcs/line_edition/
SRC_VI_PATH = srcs/line_edition/vi_mode/
SRC_SIG_PATH = srcs/sig_func/
SRC_BUILT_PATH = srcs/built_in/
SRC_PATH = srcs/
LIBFT_FLAG = -Llibft -lft

SRC_NAME = main.c\
		   term_config.c

SRC_LEX_NAME = lex.c\
			   process.c\
			   ft_init.c\
			   get_ch.c\
			   more.c\
			   add_char.c\
			   print_state.c\
			   get_state.c

SRC_PARS_NAME = pars.c\
				pars_line.c\
				ft_select_pars.c\
				ft_cleans_spa.c\
				pars_cmd.c\
				pars_pipe.c\
				pars_word.c\
				pars_nword.c\
				pars_part.c\
				pars_red.c\
				pars_rer_lr.c\
				tool_pars.c\
				print_tree.c\
				work_tree.c

SRC_EXEC_NAME = ft_exec.c\
				ft_launch_cmd.c\
				init_exe.c\
				ft_split_path.c\
				ft_free_exe.c\
				ft_pipe_close.c\
				ft_error.c\
				ft_add_red.c\
				ft_launch_red.c\
				ft_heredoc.c\
				ft_launch_pipe.c\
				ft_pile.c\
				exec_cmd.c\
				ft_path.c

SRC_LINE_NAME = line_edition.c\
		  		term_manager.c\
		  		line_read.c\
		 		termcaps.c\
		 		cursor_motion.c\
				line_alloc.c\
		 		history.c\
				get_keys.c\
				jump_words.c\
				del_env.c\
				coordinates_calc.c\
				cpy.c\
				isalt.c\
				print_line.c\
				reset_cursor.c\
				line_read_notty.c

SRC_BUILT_NAME = ft_echo.c\
				 ft_cd.c\
				 ft_env.c\
				 ft_setenv.c\
				 ft_env_tools.c\
				 ft_unsetenv.c\
				 envtolst.c\
				 lsttotab.c\
				 built_manager.c\
				 cdflag.c\
				 cdpwd.c\
				 cdfunc.c\
				 envoption.c

SRC_VI_NAME = getvi_keys.c\
				 setmode.c\
				 vi_command.c\
				 alloc_vi.c\
				 vi_edition.c\
				 jump_vi_manager.c\
				 jump_occur.c\
				 vi_repeat.c\
				 vi_com_motion.c\
				 vi_cdel.c\
				 vi_delete.c

SRC_SIG_NAME = signal_func.c signal_handler.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_LEX_NAME = $(SRC_LEX_NAME:.c=.o)
OBJ_PARS_NAME = $(SRC_PARS_NAME:.c=.o)
OBJ_EXEC_NAME = $(SRC_EXEC_NAME:.c=.o)
OBJ_LINE_NAME = $(SRC_LINE_NAME:.c=.o)
OBJ_SIG_NAME = $(SRC_SIG_NAME:.c=.o)
OBJ_BUILT_NAME = $(SRC_BUILT_NAME:.c=.o)
OBJ_VI_NAME = $(SRC_VI_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_LEX = $(addprefix $(OBJ_PATH), $(OBJ_LEX_NAME))
OBJ_PARS = $(addprefix $(OBJ_PATH), $(OBJ_PARS_NAME))
OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_EXEC_NAME))
OBJ_LINE = $(addprefix $(OBJ_PATH), $(OBJ_LINE_NAME))
OBJ_SIG = $(addprefix $(OBJ_PATH), $(OBJ_SIG_NAME))
OBJ_BUILT = $(addprefix $(OBJ_PATH), $(OBJ_BUILT_NAME))
OBJ_VI = $(addprefix $(OBJ_PATH), $(OBJ_VI_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(OBJ_LEX) $(OBJ_PARS) $(OBJ_EXEC) $(OBJ_LINE)\
	$(OBJ_SIG) $(OBJ_BUILT) $(OBJ_VI)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) -I $(INC_PATH) -ltermcap -I $(LIB_INC_PATH)\
		$(LIBFT_FLAG) -o $(NAME) $(OBJ) $(OBJ_LEX) $(OBJ_PARS) $(OBJ_EXEC)\
		$(OBJ_LINE) $(OBJ_SIG) $(OBJ_BUILT) $(OBJ_VI)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2>&-
$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_LEX_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_PARS_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_EXEC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_LINE_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_SIG_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_BUILT_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_VI_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ) $(OBJ_LEX) $(OBJ_PARS) $(OBJ_EXEC) $(OBJ_LINE)\
		$(OBJ_SIG) $(OBJ_BUILT) $(OBJ_VI)
	@rm -rf $(OBJ_PATH) 2>&-

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
