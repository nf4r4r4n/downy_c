#include <downy.h>

int main(int argc, char **argv, char **envp)
{
    (void)envp;
    if (argc < 2 || argc > 3)
    {
        print_help();
        return (0);
    }
    if (argc == 2 && strncmp(argv[1], "--version", 9) == 0)
    {
        print_version();
        return (0);
    }
    else if (argc == 2 && strncmp(argv[1], "--version", 9) != 0)
    {
        print_help();
        print_error("[Error] Bad command");
    }
    else if (argc == 3)
    {
        char    **paths = split(getenv("PATH"), ':');

        if (paths == NULL)
        {
            print_error("An error occured");
            free_split(paths);
            return (1);
        }
        if (check_dependecies(paths) == -1)
        {
            print_error("You may install dependencies first: yt-dlp & ffmpeg");
            return (1);
        }        
        int     command_id = command_exists("/yt-dlp", paths);
        char    *real_command = strjoin(strdup(paths[command_id]), "/yt-dlp");

        if (strncmp(argv[1], "--audio", 7) == 0)
        {
            char    *args[] = {real_command, "--extract-audio", "--audio-format", "mp3", argv[2], NULL};

            execute_command(args, envp);
            free_split(paths);
            free(real_command);
            return (0);
        }
        else if (strncmp(argv[1], "--video", 7) == 0)
        {
            char    *args[] = {real_command, "--format", "bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best", argv[2], NULL};

            execute_command(args, envp);
            free_split(paths);
            free(real_command);
            return (0);
        }
        else
        {
            print_help();
            print_error("[Error] Bad command");
            free_split(paths);
            free(real_command);
        }
    }
    return (0);
}