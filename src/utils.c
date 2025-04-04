/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:54:15 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 21:19:25 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_pipe *x, char *str)
{
	perror(str);
	ft_cleaner(x);
}

void	ft_cleaner(t_pipe *x)
{
	if (x->cmd1)
		ft_clean_string(x->cmd1);
	if (x->cmd2)
		ft_clean_string(x->cmd2);
	if (x->path)
		ft_clean_string(x->path);
	if (x->command1)
		free(x->command1);
	if (x->command2)
		free(x->command2);
	free(x);
	exit(0);
}

void	ft_clean_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_initialise(t_pipe *x)
{
	x->cmd1 = 0;
	x->cmd2 = 0;
	x->command1 = 0;
	x->command2 = 0;
	x->str = 0;
	x->path = 0;
}
