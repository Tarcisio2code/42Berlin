NAME = minishell
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRC_DIR = ./sources
SRC = $(SRC_DIR)/minishell.c \
      $(SRC_DIR)/minishell_utils.c \
      $(SRC_DIR)/cleaner/free_parser.c \
      $(SRC_DIR)/cleaner/free_env.c \
      $(SRC_DIR)/cleaner/free_everything.c \
      $(SRC_DIR)/cleaner/free_exe.c \
      $(SRC_DIR)/commands/cmd_cd.c \
      $(SRC_DIR)/commands/cmd_echo.c \
      $(SRC_DIR)/commands/cmd_env.c \
      $(SRC_DIR)/commands/cmd_exit.c \
      $(SRC_DIR)/commands/cmd_exit_utils.c \
      $(SRC_DIR)/commands/cmd_export.c \
      $(SRC_DIR)/commands/cmd_pwd.c \
      $(SRC_DIR)/commands/cmd_unset.c \
      $(SRC_DIR)/commands/cmd_utils.c \
      $(SRC_DIR)/environment/environment.c \
      $(SRC_DIR)/environment/environment_utils.c \
      $(SRC_DIR)/execution/exe_main.c \
      $(SRC_DIR)/execution/exe_main_builtins.c \
      $(SRC_DIR)/execution/exe_main_cmd.c \
      $(SRC_DIR)/execution/exe_main_wait.c \
      $(SRC_DIR)/execution/exe_main_utils.c \
      $(SRC_DIR)/execution/exe_free.c \
      $(SRC_DIR)/execution/exe_utils.c \
      $(SRC_DIR)/execution/exe_utils_two.c \
      $(SRC_DIR)/execution/exe_pipes.c \
      $(SRC_DIR)/execution/exe_redirect_utils.c \
      $(SRC_DIR)/execution/exe_redirect.c \
      $(SRC_DIR)/execution/heredocs.c \
      $(SRC_DIR)/execution/heredoc_utils_1.c \
      $(SRC_DIR)/execution/heredoc_utils_2.c \
      $(SRC_DIR)/history/history.c \
      $(SRC_DIR)/lexer/lexer_init.c \
      $(SRC_DIR)/lexer/lexer.c \
      $(SRC_DIR)/lexer/lexer_utils.c \
      $(SRC_DIR)/parser/parser.c \
      $(SRC_DIR)/parser/parser_utils.c \
      $(SRC_DIR)/parser/parser_init.c \
      $(SRC_DIR)/parser/parser_heredoc.c \
      $(SRC_DIR)/replace_env_vars/replace_env_vars.c \
      $(SRC_DIR)/replace_env_vars/replace_env_vars_utils.c \
      $(SRC_DIR)/replace_env_vars/replace_env_vars_aux.c \
      $(SRC_DIR)/signal/signals.c \
      $(SRC_DIR)/general_utilities/general_utilities.c \
      $(SRC_DIR)/input_handling/validate_user_input.c \
      $(SRC_DIR)/input_handling/validate_user_input_utils.c

OBJ = $(SRC:.c=.o)
LIBFT_DIR = $(SRC_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

CYAN          = \033[0;36m
GRAY          = \033[0;90m
BOLD_CYAN     = \033[1;36m
BOLD_GRAY     = \033[1;90m
BOLD_BROWN    = \033[1;33m

# Rules
all: $(LIBFT) $(NAME)
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) --silent
$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Linking objects and creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft -lreadline
	@echo "$(CYAN)"
	@echo "▓▓▓╗   ▓▓▓╗▓▓╗▓▓▓╗   ▓▓╗▓▓╗▓▓▓▓▓▓▓╗▓▓╗  ▓▓╗▓▓▓▓▓▓▓╗▓▓╗     ▓▓╗     "
	@echo "▓▓▓▓╗ ▓▓▓▓║▓▓║▓▓▓▓╗  ▓▓║▓▓║▓▓╔════╝▓▓║  ▓▓║▓▓╔════╝▓▓║     ▓▓║     "
	@echo "▓▓╔▓▓▓▓╔▓▓║▓▓║▓▓╔▓▓╗ ▓▓║▓▓║▓▓▓▓▓▓▓╗▓▓▓▓▓▓▓║▓▓▓▓▓╗  ▓▓║     ▓▓║     "
	@echo "▓▓║╚▓▓╔╝▓▓║▓▓║▓▓║╚▓▓╗▓▓║▓▓║╚════▓▓║▓▓╔══▓▓║▓▓╔══╝  ▓▓║     ▓▓║     "
	@echo "▓▓║ ╚═╝ ▓▓║▓▓║▓▓║ ╚▓▓▓▓║▓▓║▓▓▓▓▓▓▓║▓▓║  ▓▓║▓▓▓▓▓▓▓╗▓▓▓▓▓▓▓╗▓▓▓▓▓▓▓╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
	@echo
	@echo "						By tsilva & fdunkel"
	@echo "$(RESET)"
	@echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean --silent
fclean: clean
	@echo "$(RED)Cleaning everything...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent
re: fclean all
check_leaks:
	@echo "$(BOLD_BROWN)Running minishell under Valgrind Memcheck (leak detection)$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
# Special targets
.PHONY: all clean fclean re
