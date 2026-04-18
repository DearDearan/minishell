# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/04/17 14:02:20 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude -I$(LIBFT_DIR)include
ifeq ($(DEBUG),true)
    CFLAGS += -g
endif

SRC_DIR := src/
PARSE_DIR := parsing/
LEXER_DIR := parsing/lexer/
EXEC_DIR := exec/
EXPAND_DIR := expander/
BUILT_IN_DIR := built_in/

SRC_BASENAMES := minishell ft_freeall cleaning
PARSE_BASENAMES := fill_io parsing trim_quotes
LEXER_BASENAMES := ft_lexlast lexer split_quotes
<<<<<<< HEAD
EXEC_BASENAMES := exec built_in redirections fds_utils pipes children exit_code
=======
EXEC_BASENAMES := exec redirections fds_utils pipes children exit_code
>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
EXPAND_BASENAMES := expand get_var is_in_sq
BUILT_IN_BASENAMES := get_envp set_envp ft_pwd

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(PARSE_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(LEXER_DIR), $(addsuffix .c,$(LEXER_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(EXEC_DIR), $(addsuffix .c,$(EXEC_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(EXPAND_DIR), $(addsuffix .c,$(EXPAND_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(BUILT_IN_DIR), $(addsuffix .c,$(BUILT_IN_BASENAMES))) 


OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@ -lreadline

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
