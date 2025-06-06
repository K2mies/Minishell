/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quote_removal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:47:23 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/26 18:53:09 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		remove_quotes_from_token(t_minishell *data, t_token *token);
static size_t	remove_quotes_at_index(t_minishell *data, t_token *token,
					size_t i);

/**
 * Loops through tokens and calls remove_quotes_from_token with all of them.
 * Also removes empty, unquoted tokens that should only be produced by invalid
 * expansions.
 *
 * @param data	Pointer to main data struct
 */
void	quote_removal(t_minishell *data)
{
	t_token	*token;

	token = data->token_list;
	while (token)
	{
		if (token->value[0] != '\0')
			remove_quotes_from_token(data, token);
		else
		{
			if (token->prev)
				token->prev->next = token->next;
			else
			{
				data->token_list = token->next;
				if (data->token_list)
					data->token_list->prev = NULL;
			}
		}
		reactivate_quotes(token->value);
		token = token->next;
	}
}

/**
 * Looks for quotes within token->value, calls remove_quotes_at_index when it
 * finds '"' or '\''.
 *
 * @param data	Pointer to main data struct
 */
static void	remove_quotes_from_token(t_minishell *data, t_token *token)
{
	size_t		i;

	i = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'' || token->value[i] == '"')
			i = remove_quotes_at_index(data, token, i);
		++i;
	}
}

/**
 * Saves the quote character at index i, looks for the closing quote further
 * in the string. Calculates the length of the portion of the string that is
 * within these quotes, then creates the resulting string with quotes removed
 * out of three parts: the portion before the opening quote, the portion
 * between quotes, and the portion after the closing quote. token->value is
 * then set to the new string, and the index of the character that was next to
 * the closing quote is returned, so that the rest of token->value can be
 * traversed correctly.
 *
 * @param data	Pointer to main data struct
 * @param token	Pointer to token from which quotes are being removed
 * @param i		Index of opening quote, which will be removed as well as the
 *				matching closing quote
 *
 * @return	Index of the character that used to be the next character of the
 *			closing quote in the new string
 */
static size_t	remove_quotes_at_index(t_minishell *data, t_token *token,
									size_t i)
{
	char	quote;
	size_t	opening_quote_index;
	char	*within_quotes;
	size_t	within_quotes_len;
	char	*result;

	quote = token->value[i];
	opening_quote_index = i++;
	while (token->value[i] != quote)
		++i;
	within_quotes_len = i - opening_quote_index - 1;
	within_quotes = ms_substr(data, token->value,
			opening_quote_index + 1, within_quotes_len);
	result = ms_substr(data, token->value, 0, opening_quote_index);
	result = ms_strjoin(data, result, within_quotes);
	result = ms_strjoin(data, result, &token->value[i + 1]);
	token->value = result;
	return (i - 2);
}
