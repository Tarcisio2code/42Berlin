/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utilities.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:54:13 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 13:11:23 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILITIES_H
# define GENERAL_UTILITIES_H

# include "libraries.h"

void	malloc_error_check(void	*data);
void	print_shell_error(char *message, char *cmd);
t_list	*ft_lstlast(t_list *lst);
void	print_shell_erro_exit(char *message, char *cmd);

#endif
