/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:29:48 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/19 10:29:48 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_path(char **env, int help, int argc, char **argv)
{
	int	i;

	if (help)
	{
		if (argc != 5)
		{
			ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile \n", 2);
			return (1);
		}
		if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
			return (1);
	}
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_exe(char *cmd, char *path)
{
	char	**dirs;
	char	*exe;
	char	*tmp;
	int		i;

	dirs = ft_split(path + 5, ':');
	i = 0;
	while (dirs[i])
	{
		tmp = ft_strjoin(dirs[i++], "/");
		exe = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(exe, F_OK) == 0)
			break ;
		free(exe);
		exe = NULL;
	}
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
	if (exe != NULL)
		return (exe);
	else
		return (NULL);
}

void	child(char **argv, int *da_pipe, char **env)
{
	int		fd;
	char	*exe;
	char	**args;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	close(da_pipe[0]);
	dup2(fd, STDIN_FILENO);
	dup2(da_pipe[1], STDOUT_FILENO);
	args = ft_split(argv[2], ' ');
	exe = get_exe(args[0], env[get_path(env, 0, 0, NULL)]);
	if (exe == NULL || execve(exe, args, env) == -1)
	{
		while (args[i])
			free(args[i++]);
		free(args);
		free(exe);
		exit(127);
	}
	free(exe);
}

void	child2(char **argv, int *da_pipe, char **env)
{
	int		fd;
	char	*exe;
	char	**args;
	int		i;

	i = 0;
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit(1);
	close(da_pipe[1]);
	dup2(fd, STDOUT_FILENO);
	dup2(da_pipe[0], STDIN_FILENO);
	args = ft_split(argv[3], ' ');
	exe = get_exe(args[0], env[get_path(env, 0, 0, NULL)]);
	if (exe == NULL || execve(exe, args, env) == -1)
	{
		while (args[i])
			free(args[i++]);
		free(args);
		free(exe);
		exit(127);
	}
	free(exe);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	if (get_path(env, 1, argc, argv) == 1)
		return (1);
	if (pipe(data.pipe) == -1)
		return (1);
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (1);
	else if (data.pid1 == 0)
		child(argv, data.pipe, env);
	data.pid2 = fork();
	if (data.pid2 == -1)
		return (1);
	else if (data.pid2 == 0)
		child2(argv, data.pipe, env);
	close(data.pipe[0]);
	close(data.pipe[1]);
	waitpid(data.pid1, &data.status1, 0);
	waitpid(data.pid2, &data.status2, 0);
	if (WIFEXITED(data.status1) && WEXITSTATUS(data.status1) != 0)
		return (WEXITSTATUS(data.status1));
	if (WIFEXITED(data.status2) && WEXITSTATUS(data.status2) != 0)
		return (WEXITSTATUS(data.status2));
	return (0);
}
