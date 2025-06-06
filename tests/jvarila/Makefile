# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 17:10:47 by jvarila           #+#    #+#              #
#    Updated: 2025/03/11 17:17:01 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
DEBUGFLAGS	:= -g
INC		:= -I ../../libft -I ../../include
#------------------------------------------------------------------------------#
LIBFT_DIR	:= ../../libft
LIBFT		:= $(LIBFT_DIR)/libft.a
#------------------------------------------------------------------------------#
SRC_DIR	:=	../../src
OBJ_DIR	:=	./obj
#------------------------------------------------------------------------------#
SRC :=	$(SRC_DIR)/tokenization/minishell_tokenization.c		\
	$(SRC_DIR)/tokenization/minishell_variable_expansion.c		\
	$(SRC_DIR)/tokenization/minishell_word_splitting.c		\
	$(SRC_DIR)/tokenization/minishell_quote_removal.c		\
	$(SRC_DIR)/tokenization/minishell_token_classification.c	\
	$(SRC_DIR)/tokenization/minishell_is_token_01.c			\
	$(SRC_DIR)/tokenization/minishell_is_token_02.c			\
	$(SRC_DIR)/tokenization/minishell_is_token_03.c			\
	$(SRC_DIR)/tokenization/minishell_assign_token_indices.c	\
	$(SRC_DIR)/tokenization/minishell_token_getters.c		\
	$(SRC_DIR)/tokenization/minishell_token_analysis.c		\
	$(SRC_DIR)/tokenization/minishell_tokenization_utils.c		\
	$(SRC_DIR)/tokenization/minishell_quote_validation.c		\
	\
	$(SRC_DIR)/error_handling/minishell_error_handling.c		\
	$(SRC_DIR)/error_handling/minishell_error_logging.c		\
	$(SRC_DIR)/error_handling/minishell_syntax_error.c		\
	$(SRC_DIR)/error_handling/minishell_exit_value_handling.c	\
	\
	$(SRC_DIR)/signals/minishell_signals.c				\
	\
	$(SRC_DIR)/piping/minishell_piping_01.c				\
	$(SRC_DIR)/piping/minishell_piping_02.c				\
	\
	$(SRC_DIR)/redirections/minishell_redirections.c		\
	$(SRC_DIR)/redirections/minishell_redirect_input.c		\
	$(SRC_DIR)/redirections/minishell_redirect_output.c		\
	$(SRC_DIR)/redirections/minishell_redirect_heredoc.c		\
	$(SRC_DIR)/redirections/minishell_redirect_append.c		\
	\
	$(SRC_DIR)/execution/minishell_execution.c			\
	\
	$(SRC_DIR)/environment/minishell_environment.c			\
	$(SRC_DIR)/environment/minishell_environment_list.c		\
	$(SRC_DIR)/environment/minishell_environment_print_alpha.c	\
	\
	$(SRC_DIR)/builtins/minishell_builtin_cd.c			\
	$(SRC_DIR)/builtins/minishell_builtin_echo.c			\
	$(SRC_DIR)/builtins/minishell_builtin_env.c			\
	$(SRC_DIR)/builtins/minishell_builtin_exit.c			\
	$(SRC_DIR)/builtins/minishell_builtin_export.c			\
	$(SRC_DIR)/builtins/minishell_builtin_pwd.c			\
	$(SRC_DIR)/builtins/minishell_builtin_unset.c			\
	$(SRC_DIR)/builtins/minishell_builtin_handler.c			\
	\
	$(SRC_DIR)/redirections/minishell_heredoc_01.c			\
	$(SRC_DIR)/redirections/minishell_heredoc_02.c			\
	\
	$(SRC_DIR)/utils/minishell_var_name_len.c			\
	$(SRC_DIR)/utils/minishell_cleanup_and_exiting.c		\
	$(SRC_DIR)/utils/minishell_safe_fd_management.c			\
	$(SRC_DIR)/utils/minishell_safe_pipe_management.c		\
	$(SRC_DIR)/utils/minishell_token_helpers_01.c			\
	$(SRC_DIR)/utils/minishell_token_helpers_02.c			\
	$(SRC_DIR)/utils/minishell_token_helpers_03.c			\
	$(SRC_DIR)/utils/minishell_directory_validation.c		\
	$(SRC_DIR)/utils/minishell_print_debug.c			\
	$(SRC_DIR)/utils/minishell_environment_utils.c			\
	$(SRC_DIR)/utils/minishell_data_reset_01.c			\
	$(SRC_DIR)/utils/minishell_data_reset_02.c
#------------------------------------------------------------------------------#
TESTS :=	minishell_test_word_lexing_01.out	\
		minishell_test_quotes_01.out		\
		minishell_test_signals.out		\
		minishell_test_pipe.out			\
		minishell_test_redirections.out		\
		minishell_test_heredoc.out		\
		minishell_test_heredoc_pipe_redir.out	\
		minishell_perror_testing.out
#------------------------------------------------------------------------------#
OBJ :=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
#------------------------------------------------------------------------------#
all: $(TESTS)

$(TESTS): %.out: %.c $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $< $(LIBFT) -lreadline -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< $(INC) -o $@
#------------------------------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TESTS)

re: fclean all
#------------------------------------------------------------------------------#
debug: CFLAGS += $(DEBUGFLAGS)
debug: re
#------------------------------------------------------------------------------#
.PHONY: all clean fclean re debug libftdebug
#------------------------------------------------------------------------------#
