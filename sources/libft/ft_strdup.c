/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:51 by atambo            #+#    #+#             */
/*   Updated: 2024/05/15 09:18:14 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	n;
	size_t	i;
	char	*dst;

	n = 0;
	while (*src)
	{	
		src ++;
		n ++;
	}
	src = src - n;
	dst = (char *)malloc((n + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
