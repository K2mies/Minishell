/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_test_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:49:35 by jvarila           #+#    #+#             */
/*   Updated: 2025/04/09 10:37:42 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_minishell *data)
{
	char	*line;

	while (1)
	{
		line = readline("minishell heredoc test: ");
		if (!line)
			break ;
		add_history(line);
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		if (has_unclosed_quotes(line))
		{
			ft_putendl("Input has unclosed quotes");
			free(line);
			continue ;
		}
		data->raw_input = line;
		tokenization(data);
		heredoc(data);
		data->token_list = NULL;
		free(line);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	static t_minishell	data;

	(void)argc;
	(void)argv;
	(void)envp;
	data.arena = ft_new_memarena();
	data.initial_env = (const char **)envp;
	env_list_from_envp(&data, data.initial_env);
	if (!data.arena)
		return (ft_write_error_return_int(MSG_ERROR_ALLOC, ERROR_ALLOC));
	loop(&data);
	ft_free_memarena(data.arena);
	return (0);
}
