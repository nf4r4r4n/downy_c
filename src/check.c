#include <downy.h>

// Return the index of the command on success, -1 on error
int  command_exists(char *command, char **paths)
{
    if (paths == NULL)
        return (-1);
    for (int i = 0; paths[i]; i++)
    {
        char    *path = strjoin(strdup(paths[i]), command);

        if (path == NULL)
        {
            free_split(paths);
            return (-1);
        }
        if (access(path, X_OK) == 0)
        {
            free(path);
            return (i);
        }
        free(path);
    }
    free_split(paths);
    return (-1);
}

// Check all dependencies
// return 0 on success, -1 on error
int check_dependecies(char **paths)
{
    if (command_exists("/yt-dlp", paths) == -1 || command_exists("/ffmpeg", paths) == -1)
        return (-1);
    return (0);
}