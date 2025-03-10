/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlinexample00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:29:11 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/10 14:10:38 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// Function to strn cmp and check wether EOF is entered or not
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// Function to print the history of readline
void	print_history()
{
	HIST_ENTRY	**history = history_list();
	if (history)
	{
		int i = -1;
		while (history[++i])
		{
			printf("%d: %s\n", i + 1, history[i]->line);
		}
	}
}

int	main()
{
	printf("Welcome weary traveller! You can safeoword by pressing Ctrl+D at any time...\n");
	char	*input;
	while (1)
	{
		input = readline(">> ");
		if (!input)
			return (1);
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			printf("exiting program...\n");
			free(input);
			break ;
		}
		printf("you shouted: %s into the void\n", input);
		add_history(input);
		free(input);
		printf("the void shouts back the following:\n");
		print_history();
	}
	return (0);
}
