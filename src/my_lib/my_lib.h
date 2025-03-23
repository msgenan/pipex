/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:28:31 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 22:30:14 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif