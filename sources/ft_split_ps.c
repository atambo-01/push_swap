/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:55:22 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 01:55:25 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	word_count(char *str, char div)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == div)
			i++;
		if (str[i] && str[i] != div)
		{
			wc++;
			while (str[i] && str[i] != div)
				i++;
		}
	}
	return (wc);
}

static int	total_word_count(char **str, char div)
{
	int	total_wc;
	int	i;

	i = 0;
	total_wc = 0;
	while (str[i])
		total_wc += word_count(str[i++], div);
	return (total_wc);
}

static char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**split_string(char *str, char div, char **out, int *k)
{
	int	start;
	int	j;

	j = 0;
	while (str[j])
	{
		while (str[j] && str[j] == div)
			j++;
		start = j;
		while (str[j] && str[j] != div)
			j++;
		if (j > start)
			out[(*k)++] = word_dup(str, start, j);
	}
	return (out);
}

char	**ft_split_ps(char **str, char div)
{
	char	**out;
	int		k;
	int		i;

	out = (char **)malloc(sizeof(char *) * (total_word_count(str, div) + 1));
	if (!out)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		out = split_string(str[i], div, out, &k);
		i++;
	}
	out[k] = NULL;
	return (out);
}
