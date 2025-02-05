#include <downy.h>

void    print_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void    print_help(void)
{
    printf("Usage: downy <command> [arg]\n");
    printf("Commands:\n");
    printf("\t--version:       Print the version of downy\n");
    printf("\t--audio [url]:   Download audio at \"url\"\n");
    printf("\t--video [url]:   Download video at \"url\"\n");
}

void    print_version(void)
{
    printf("Downy created by " DOWNY_CREATOR "\n");
    printf("Version: " DOWNY_VERSION "\n");
}
