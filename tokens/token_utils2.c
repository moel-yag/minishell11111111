#include "tokens.h"

int	condition6(t_ddata *ddata, const char *input, int *i, int in_quote)
{
	t_token	*new_token;
	char	*substr;

	if (ddata->len > 0)
	{
		substr = ft_substr(input, *i, ddata->len);
		if (!substr)
			return (0);
		new_token = create_token(substr, TOKEN_WORD, in_quote);
		if (!new_token)
		{
			free(substr);
			return (0);
		}
		add_token(&ddata->head, new_token);
		*i += ddata->len;
		ddata->len = 0;
	}
	if (ddata->ptr[*i + 1] == '>')
	{
		add_token(&ddata->head, create_token(NULL, TOKEN_APPEND, 0));
		*i += 2;
	}
	else
	{
		add_token(&ddata->head, create_token(NULL, TOKEN_REDIRECT_OUT, 0));
		(*i)++;
	}
	return (1);
}

int	condition5(t_ddata *ddata, const char *input, int *i, int in_quote)
{
	t_token	*new_token;
	char	*substr;

	if (ddata->len > 0)
	{
		substr = ft_substr(input, *i, ddata->len);
		if (!substr)
			return (0);
		new_token = create_token(substr, TOKEN_WORD, in_quote);
		if (!new_token)
		{
			free(substr);
			return (0);
		}
		add_token(&ddata->head, new_token);
		*i += ddata->len;
		ddata->len = 0;
	}
	if (ddata->ptr[*i + 1] == '<')
	{
		add_token(&ddata->head, create_token(NULL, TOKEN_HEREDOC, 0));
		*i += 2;
	}
	else
	{
		add_token(&ddata->head, create_token(NULL, TOKEN_REDIRECT_IN, 0));
		(*i)++;
	}
	return (1);
}

int	condition4(t_ddata *ddata, const char *input, int *i, int in_quote)
{
	t_token	*new_token;
	char	*substr;

	if (ddata->len > 0)
	{
		substr = ft_substr(input, *i, ddata->len);
		if (!substr)
			return (0);
		new_token = create_token(substr, TOKEN_WORD, in_quote);
		if (!new_token)
		{
			free(substr);
			return (0);
		}
		add_token(&ddata->head, new_token);
		*i += ddata->len;
		ddata->len = 0;
	}
	add_token(&ddata->head, create_token(NULL, TOKEN_PIPE, 0));
	(*i)++;
	return (1);
}
