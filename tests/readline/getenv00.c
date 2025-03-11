/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:31:46 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/11 11:59:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int	main(int argc, char **argv, char **envp) 
{
	(void)argc;
	(void)argv;
	int	i = 0;
	char	*env_variable = envp[i];
	while(env_variable != NULL)
	{
//		printf("%s\n", env_variable);
		char	*key = strtok(env_variable, "=");
		char	*value = strtok(NULL, "=");
		if (strcmp(key, "API_KEY") == 0)
		{
			printf("API_KEY value is %s\n\n", value);
		}
		i++;
		env_variable = envp[i];
	}
////	char * env_variable = getenv("PATH");
//	char * env_variable = getenv("API_KEY");
//	if (env_variable == NULL)
//	{
//		printf("No enviroment variable was found\n");
//		return (1);
//	}
//	printf("The value of our enviroment variable is %s\n\n", env_variable);
	return (0);
}
