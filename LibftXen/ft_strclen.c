/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:43:23 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/15 14:09:47 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclen(const char *s, char c)
{
	int		i;

	i = 0;
	if (!*s || !c)
		return (0);
	while (s[i] && s[i] != c)
	{
		i++;
		if (!s[i])
			return (i);
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
