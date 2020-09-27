#include "minishell.h"
#include "structer.h"
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
static int	execute(t_command *cmd, t_command *prev, t_data *data)
{
	int pid;
	int pid2;

	if (data->counter != 0 && prev->pipe == 1)
	{
		pid2 = fork();
		if (pid2 < 0)
			return (1);
		if (pid2 == 0)
		{
			dup2(data->fd[0], STDIN_FILENO);
			close(data->fd[0]);
			close(data->fd[1]);
			execve(cmd->argv[0], cmd->argv, data->envp);
		}
	}
	if (cmd->pipe == 1)
	{
		if (pipe(data->fd) == -1)
			return (1);
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)
		{
			dup2(data->fd[1], STDOUT_FILENO);
			close(data->fd[1]);
			execve(cmd->argv[0], cmd->argv, data->envp);
		}
		data->counter++;
		close(data->fd[1]);
		wait(NULL);
		return (0);
	}
//	else
//	{
//		close(data->fd[0]);
//		close(data->fd[1]);
//		wait(NULL);
//		pid = fork();
//		if (pid < 0)
//			return (1);
//		if (pid == 0)
//		{
//			int status = execve(cmd->argv[0], cmd->argv, data->envp);
//			printf("%d", status);
//		}
//		return (0);
//	}

	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(pid2, NULL, 0);
	return (0);
}

int			cmd_caller(t_data *data, t_command *cmd)
{
	t_command *prev;
	data->counter = 0;
	prev = cmd;
	while (cmd)
	{
		if (execute(cmd, prev, data))
			return (1);
		prev = cmd;
		cmd = cmd->next;
	}
	return (0);
}