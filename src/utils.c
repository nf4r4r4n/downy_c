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

char    *strjoin(char *s1, char *s2)
{
    char    *join;
    int     i;
    int     j;

    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
        return (strdup(s2));
    if (s2 == NULL)
        return (strdup(s1));
    join = calloc(sizeof(char), strlen(s1) + strlen(s2) + 1);
    if (join == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        join[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        join[j] = s2[i];
        i++;
        j++;
    }
    join[j] = '\0';
    free(s1);
    return (join);
}

void free_split(char **array)
{
    if (array == NULL)
        return ;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
