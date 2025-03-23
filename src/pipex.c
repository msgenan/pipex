/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:53:48 by mugenan           #+#    #+#             */
/*   Updated: 2025/03/23 21:16:53 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipe *x, char *av, char **env)
{
	int	fd;

	fd = open(av, O_RDONLY, 0777);
	if (fd == -1)
		ft_error(x, "fd failed to open the file! (infile)");
	close(x->fdpipe[0]);
	dup2(x->fdpipe[1], 1);
	close(x->fdpipe[1]);
	dup2(fd, 0);
	close(fd);
	if (execve(x->command1, x->cmd1, env) == -1)
		ft_error(x, "problem with execve on child");
}

void	ft_parent_process(t_pipe *x, char *av, char **env)
{
	int	fd;

	fd = open(av, O_CREAT | O_TRUNC | O_RDWR | O_APPEND, 0777);
	if (fd == -1)
		ft_error(x, "fd failed to open the file! (outfile)");
	close(x->fdpipe[1]);
	dup2(x->fdpipe[0], 0);
	close(x->fdpipe[0]);
	dup2(fd, 1);
	close(fd);
	if (execve(x->command2, x->cmd2, env) == -1)
		ft_error(x, "problem with execve on parent");
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*x;
	int		pid;

	if (ac != 5)
		return (perror("Argument count is not 5!"), exit(0), 0);
	x = malloc(sizeof(t_pipe));
	if (!x)
		ft_error(x, "t_pipe allocation failed!");
	ft_initialise(x);
	ft_take_arg(x, av);
	ft_take_path(x, env);
	x->command1 = ft_search_path(x, x->cmd1[0]);
	if (!x->command1)
		ft_error(x, "Valid path for cmd1 not found!");
	x->command2 = ft_search_path(x, x->cmd2[0]);
	if (!x->command2)
		ft_error(x, "Valid path for cmd2 not found!");
	if (pipe(x->fdpipe) == -1)
		ft_error(x, "Pipe creation failed!");
	pid = fork();
	if (pid == -1)
		ft_error(x, "Fork error occurred!");
	if (pid == 0)
		ft_child_process(x, av[1], env);
	ft_parent_process(x, av[4], env);
}
