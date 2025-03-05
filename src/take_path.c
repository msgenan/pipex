#include "pipex.h"

void	ft_take_arg(t_pipe *x, char **av)
{
	x->cmd1 = ft_split(av[2], ' ');
    if (!x->cmd1 || !x->cmd1[0])
        ft_error(x, "Problem with cmd1 argument!");
	x->cmd2 = ft_split(av[3], ' ');
	if (!x->cmd2 || !x->cmd2[0])
        ft_error(x, "Problem with cmd1 argument!");
}

void	ft_take_path(t_pipe *x, char **env)
{
	int i;
	int j;
	int flag;
	char *str;
	
	i = 0;
    str = "PATH=";
	while(env[i])
	{
		j = 0;
		flag = 0;
		while(env[i][j] == str[j])
		{
			flag++;
			j++;
		}
		if (flag == 5)
		{
			x->path = ft_split(env[i] + 5, ':');
			break;
		}
		i++;
	}
	if (!x->path)
		ft_error(x, "Valid path not found!");
}

char	*ft_search_path(t_pipe *x, char *cmd)
{
	int i;
    int j;
    int size;

	i = 0;
	while (x->path[i])
	{
        j = 0;
		size = strlen(x->path[i]) + strlen(cmd);
		x->str = malloc(size + 2);
		if (!x->str)
            ft_error(x, "Memory allocation failed for str!");
		ft_strlcpy(x->str, x->path[i], ft_strlen(x->path[i]) + 1);
		ft_strlcat(x->str, "/", size + 1);
		ft_strlcat(x->str, cmd, size + 2);
		if (access(x->str, X_OK) == 0)
			return(x->str);
		i++;
	}
	return(x->str);
}
