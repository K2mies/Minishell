/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:28:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/04/09 17:05:22 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*fetch_builtin(t_minishell *data)
{
	t_token	*token;

	token = data->token_list;
	if (data->pipe_count == 0 )
	{
		while (token)
		{
			if (token->type == BUILTIN)
				return (token);
			token = token->next;
		}
	}
	return (NULL);
}

void	builtin_handler(t_minishell *data)
{
	t_token *builtin_token;

	builtin_token = fetch_builtin(data);
	if (builtin_token)
	{

		if (ft_strncmp(builtin_token->value, "echo", 4) == 0)
		{
			ft_putendl_fd("echo called", 1);
		}
		if (ft_strncmp(builtin_token->value, "cd", 2) == 0)
		{
//			ft_putendl_fd("cd called", 1);
			builtin_cd(data, builtin_token, data->minishell_env);
		}
		if (ft_strncmp(builtin_token->value, "pwd", 3) == 0)
		{
//			ft_putendl_fd("pwd called", 1);
			builtin_pwd(data);
		}
		if (ft_strncmp(builtin_token->value, "export", 6) == 0)
		{
			ft_putendl_fd("export called", 1);
		}
		if (ft_strncmp(builtin_token->value, "unset", 5) == 0)
		{
			ft_putendl_fd("unset called", 1);
		}
		if (ft_strncmp(builtin_token->value, "env", 3) == 0)
		{
			ft_putendl_fd("env called", 1);
		}
		if (ft_strncmp(builtin_token->value, "exit", 4) == 0)
		{
			ft_putendl_fd("exit called", 1);
		}

	}
//	data->last_rval = EXIT_SUCCESS;
}
