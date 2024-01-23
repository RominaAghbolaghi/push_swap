/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:13:36 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 09:13:41 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h>

compares the first n bytes (each interpreted as UNSIGNED CHAR) of the memory 
areas s1 and s2.

returns an integer less than, equal to, or greater than zero if the first n 
bytes  of  s1 is found, respectively, to be less than, to match, or be greater 
than the first n bytes of s2.

For  a  nonzero  return  value,  the sign is determined by the sign of the 
difference between the first pair of bytes (interpreted as unsigned char) 
that differ in s1 and s2.

If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
