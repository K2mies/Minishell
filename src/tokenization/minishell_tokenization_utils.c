/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenization_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:42:24 by jvarila           #+#    #+#             */
/*   Updated: 2025/04/21 16:37:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Toggles quote flag to be equal to the char c if not set (0), if it was
 * already set to c, it toggles the value back to 0.
 *
 * @param quote_flag	Pointer to character that holds the encountered quote
 * @param c				Character that holds either '\'' or '"'
 */
void	toggle_quote_flag(char *quote_flag, char c)
{
	if (!(c == '\'' || c == '"'))
		return ;
	if (*quote_flag == 0)
		*quote_flag = c;
	else if (*quote_flag == c)
		*quote_flag = 0;
}

/**
 * Creates new token node using str, uses memory arena to request heap memory.
 *
 * Does an initial categorization for operators, everything else will be a word
 * at first. More granular categorization will follow after all possible
 * expansions, word splits and quote removals are completed.
 *
 * @param arena	Pointer to first node in memarena
 * @param str	String is assigned to be the value of the new token node
 *
 * @return		Return newly created token node
 */
t_token	*new_token_node(t_minishell *data, const char *str)
{
	t_token	*new;

	new = ms_calloc(data, 1, sizeof(t_token));
	new->value = (char *)str;
	if (*str == '|')
		new->type = PIPE;
	else if (ft_strcmp(str, "<") == 0)
		new->type = REDIRECT_INPUT;
	else if (ft_strcmp(str, ">") == 0)
		new->type = REDIRECT_OUTPUT;
	else if (ft_strcmp(str, "<<") == 0)
		new->type = HEREDOC;
	else if (ft_strcmp(str, ">>") == 0)
		new->type = APPEND;
	else
		new->type = WORD;
	return (new);
}

/**
 * Adds a given token node to the end of given list of tokens.
 *
 * @param list	First node in list of tokens
 * @param token	Pointer to token node that will be added to the end of the list
 */
void	append_token(t_token **list, t_token *token)
{
	t_token	*end;

	if (!list || !token)
		return ;
	if (!*list)
	{
		*list = token;
		return ;
	}
	end = *list;
	while (end->next)
		end = end->next;
	end->next = token;
	token->prev = end;
	token->index = end->index + 1;
}

/**
 * Inserts node "new" to be the prev node of node "current".
 *
 * @param current	Pointer to selected token node
 * @param new		Pointer to instertable token node
 */
void	insert_token_left(t_token *current, t_token *new)
{
	t_token	*prev;

	if (!current || !new)
		return ;
	prev = current->prev;
	if (prev)
		prev->next = new;
	current->prev = new;
	new->next = current;
	new->prev = prev;
}
