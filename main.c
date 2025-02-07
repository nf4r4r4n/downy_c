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
        if (check_dependecies() == -1)
        {
            print_error("You may install dependencies first: yt-dlp & ffmpeg");
            return (1);
        }        
        if (strncmp(argv[1], "--audio", 7) == 0)
        {
            printf("AUDIO\n");
            return (0);
        }
        else if (strncmp(argv[1], "--video", 7) == 0)
        {
            printf("VIDEO\n");
            return (0);
        }
        else
        {
            print_help();
            print_error("[Error] Bad command");
        }
    }
    return (0);
}