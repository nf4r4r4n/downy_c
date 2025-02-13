#include <downy.h>

int execute_command(char **args, char **envp)
{
    int     status;
    pid_t   pid = fork();

    if (pid < 0)
    {
        printf("[Error(error)] Executing command \"%s\"\n", args[0]);
        return (-1);
    }
    else if (pid == 0)
    {
        if (execve(args[0], args, envp) == -1)
        {
            printf("[Error(child)] Executing command \"%s\"\n", args[0]);
            return (-1);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            printf("[Error(parent)] Executing command \"%s\"\n", args[0]);
            return (-1);
        }
        WIFEXITED(status);
        WEXITSTATUS(status);
    }
    return (0);
}