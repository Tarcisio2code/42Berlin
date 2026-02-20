/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:58:40 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:00:03 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

enum
{
	WORD,
	DBL_QUOTE,
	SINGLE_QUOTE,
	REDIR,
	PIPE,
	CHAR_NULL,
};

typedef enum s_redir_types
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}				t_redir_types;

typedef struct s_token
{
	char			*data;
	int				type;
	int				concat_next;
	struct s_token	*next;
}				t_token;

typedef struct s_lexer
{
	t_token	*token_list;
	int		n_of_tokens;
	int		type_of_token;
}				t_lexer;

/* PARSER */
typedef struct s_redirect
{
	t_redir_types		type;
	char				*file;
	struct s_redirect	*next;
}				t_redir;

/* EXECUTION */
typedef struct s_heredoc
{
	char				*delimiter;
	int					*fds;
	struct s_heredoc	*next;
}				t_h_doc;

typedef struct s_cmd
{
	char			**cmd_array;
	char			*path;
	int				*redir_in;
	int				*redir_out;
	int				index;
	int				n_args;
	bool			has_heredoc;
	bool			redir_error;
	t_h_doc			*heredoc_ptr;
	t_redir			*redirs;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_cmd_table
{
	t_cmd	*entry;
	int		n_cmds;
	int		**pipes;
	t_list	*children_pids;
	t_h_doc	*heredoc;
}				t_cmd_table;

typedef struct s_msh_core
{
	t_lexer			*lexer;
	t_cmd_table		*cmd_table;
	int				exit_status;
	pid_t			minishell_pid;
	t_list			*envp;
	char			**path_slash;
	bool			heredoc_error;
	char			*first_home_path;
}				t_msh;

typedef struct s_delim_data
{
	char	*line;
	char	*expanded_line;
	char	**env;
	t_msh	*msh_core;
}				t_delim_data;

typedef struct s_proc_data
{
	int		increm;
	int		wspace;
	t_token	*prev;
}				t_proc_data;
extern volatile sig_atomic_t	g_signal_value;

#endif
