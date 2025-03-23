/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:28:01 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 22:28:12 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
