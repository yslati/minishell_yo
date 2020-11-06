/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:59:53 by obouykou          #+#    #+#             */
/*   Updated: 2020/11/06 18:02:29 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*b1;
	unsigned char		*b2;

	b1 = (unsigned char*)s1;
	b2 = (unsigned char*)s2;
	i = 0;
	while (i < n && b1[i] && b2[i])
	{
		if (b1[i] != b2[i])
			return ((int)(b1[i] - b2[i]));
		i++;
	}
	return (0);
}
