# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 00:08:26 by roliveir          #+#    #+#              #
#    Updated: 2019/06/20 10:42:58 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include mk/builtins.mk
include mk/lexer.mk
include mk/parser.mk
include mk/exec.mk
include mk/line_edition.mk
include mk/option.mk

CC = gcc
LIBFT = libft
LIBS = -lft
LIBSFOLDERS = -L./$(LIBFT)
vpath %.c $(dir MAKEFILE_LIST)
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes -I./libft/includes
CPPFLAGS += -MMD -MP
OBJDIR = .o
UNAME = $(shell uname)
NAME = 21sh

OBJS = $(subst .c,.o,$(subst ./srcs/,./$(OBJDIR)/,$(SRCS)))
DEPS = $(subst .c,.d,$(subst ./srcs/,./$(OBJDIR)/,$(SRCS)))

all: $(NAME)

$(NAME): $(OBJS) | lib_rule
	@$(RM) tmp_log
	@$(RM) tmp_errors
	@if [ -e files_missing ]; then \
		printf "\033[1;31m\n[21SH COMPILATION FAILED]\033[0m\n"; \
	else \
		if [ -e /tmp/.21sh_makefile_link ] || [ ! -e $(NAME) ]; then \
			$(CC) $(OBJS) -o $(NAME) $(LIBSFOLDERS) $(LIBS) -ltermcap; \
			printf "\033[1;36m\n[42SH COMPILATION SUCCESSFUL]\033[0m\n"; \
		fi;\
	fi;
	@$(RM) files_missing
	@$(RM) /tmp/.21sh_makefile_link

$(OBJDIR):
	@$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	@$(shell mkdir -p $(dir $@))
	@$(shell touch /tmp/.21sh_makefile_link)
	@printf "%-50s" "Precompiling $(notdir $@)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 2> ./tmp_log || /usr/bin/touch ./tmp_errors
	@if [ -e tmp_errors ]; then \
		printf "\033[1;31m[KO]\n\033[0m" && /bin/cat 1>&2 ./tmp_log && touch files_missing; \
	elif test -s ./tmp_log; then \
		printf "\033[1;33m[WARNING]\n\033[0m" && /bin/cat ./tmp_log; \
	else \
		printf "\033[1;32m[OK]\n\033[0m"; \
	fi;
	@$(RM) ./tmp_errors

clean:
	@$(MAKE) -C $(LIBFT) clean --no-print-directory
	@$(RM) $(OBJS) $(DEPS)
	@printf "\033[1;33m[21SH OBJECT FILES CLEANED]\033[0m\n"

fclean:
	@$(MAKE) -C $(LIBFT) fclean --no-print-directory
	@$(RM) $(OBJS) $(DEPS)
	@printf "\033[1;33m[21SH OBJECT FILES CLEANED]\033[0m\n"
	@$(RM) $(NAME)
	@printf "\033[1;35m[21SH BINARY DELETED]\033[0m\n"

re: fclean all

lib_rule:
	@$(MAKE) -C $(LIBFT) --no-print-directory

.PHONY: lib_rule all clean fclean re
-include $(DEPS)
