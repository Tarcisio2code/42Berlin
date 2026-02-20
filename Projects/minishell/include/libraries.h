/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libraries.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:08:11 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 13:04:32 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARIES_H
# define LIBRARIES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../sources/libft/libft.h"
# include "structures.h"
# include "macros.h"

# include "history.h"
# include "environment.h"
# include "signals.h"
# include "commands.h"
# include "lexer.h"
# include "replace_env_vars.h"
# include "general_utilities.h"
# include "cleaner.h"
# include "parser.h"
# include "execution.h"
# include "input_handling.h"
# include "heredocs.h"
# include "pipes.h"
# include "redirections.h"

#endif
