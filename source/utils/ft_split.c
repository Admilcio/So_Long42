/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-mata <ada-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:11:41 by ada-mata          #+#    #+#             */
/*   Updated: 2023/12/08 16:12:18 by ada-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	wordcounter(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*stringreturn(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_free(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		string;

	string = wordcounter(s, c);
	i = 0;
	ret = malloc(sizeof(char **) * (string + 1));
	if (!ret || !s)
		return (NULL);
	while (i < string)
	{
		while (*s == c)
			s++;
		ret[i] = stringreturn(s, c);
		if (ret[i] == NULL)
			ft_free(ret, i);
		s += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
