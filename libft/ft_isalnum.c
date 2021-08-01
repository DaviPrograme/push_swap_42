/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:03:01 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:03:14 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int letra)
{
	if ((letra >= 48 && letra <= 57) || (letra >= 65 && letra <= 122))
		if (!(letra > 90 && letra < 97))
			return (1);
	return (0);
}