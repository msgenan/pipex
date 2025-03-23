/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:54:25 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 21:40:20 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "./my_lib/my_lib.h"

typedef struct s_pipe
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*command1;
	char	*command2;
	char	*str;
	int		fdpipe[2];

}			t_pipe;

char	*ft_search_path(t_pipe *x, char *cmd);
void	ft_take_path(t_pipe *x, char **env);
void	ft_take_arg(t_pipe *x, char **av);
void	ft_error(t_pipe *x, char *str);
void	ft_clean_string(char **str);
void	ft_cleaner(t_pipe *x);
void	ft_initialise(t_pipe *x);

#endif