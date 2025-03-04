#include "pipex.h"

void    ft_error(t_pipe *x, char *str)
{
    perror(str);
	ft_cleaner(x);
    exit(0);
}

void	ft_cleaner(t_pipe *x)
{
	if (x->cmd1)
		ft_clean_string(x->cmd1);
	if (x->cmd2)
		ft_clean_string(x->cmd2);
	if (x->path)
		ft_clean_string(x->path);
	if (x->str)
		free(x->str);
}

void	ft_clean_string(char **str)
{
	int i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}