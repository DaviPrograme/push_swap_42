/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:20:41 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/10 18:52:44 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	cont;
	unsigned int	cont2;
	char			*ptr;

	cont = 0;
	ptr = 0;
	if (!s && !start)
		return (NULL);
	while (s[cont] != '\0')
		++cont;
	if (len > cont)
		return (NULL);
	if ((cont - start) <= len)
		len = cont - start;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s || !ptr)
		return (NULL);
	cont2 = 0;
	while (cont2 < len && ft_strlen(s) > start)
	{
		ptr[cont2] = s[cont2 + start];
		++cont2;
	}
	return (ptr);
}
