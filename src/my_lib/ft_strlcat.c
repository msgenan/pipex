/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:26:28 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 22:27:15 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;
	size_t	startlen;

	i = ft_strlen(dst);
	c = 0;
	startlen = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[c] && i < dstsize - 1)
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = 0;
	return (startlen + ft_strlen(src));
}
