#include <downy.h>

static int  check_yt_dlp(void)
{
    char    *paths[] = {"/usr/local/bin/yt-dlp", "/usr/bin/yt-dlp", "/bin/yt-dlp", NULL};

    for (int i = 0; paths[i]; i++)
        if (access(paths[i], X_OK) == 0)
            return (0);
    return (-1);
}

static int  check_ffmpeg(void)
{
    char    *paths[] = {"/usr/local/bin/ffmpeg", "/usr/bin/ffmpeg", "/bin/ffmpeg", NULL};

    for (int i = 0; paths[i]; i++)
        if (access(paths[i], X_OK) == 0)
            return (0);
    return (-1);
}

// Check all dependencies
// return 0 on success, -1 on error
int check_dependecies(void)
{
    if (check_yt_dlp() == -1 || check_ffmpeg() == -1)
        return (-1);
    return (0);
}