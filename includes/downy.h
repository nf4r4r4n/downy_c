#ifndef DOWNY_H
# define DOWNY_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>

# ifndef DOWNY_VERSION
#  define DOWNY_VERSION "7th Feb 2025"
# endif //  DOWNY_VERSION

# ifndef DOWNY_CREATOR
#  define DOWNY_CREATOR "nf4r4r4n<baibs.fararano@gmail.com>"
# endif //  DOWNY_CREATOR

// utils.c
void    print_error(const char *msg);
void    print_help(void);
void    print_version(void);
char	*strjoin(char *s1, char *s2);
void 	free_split(char **array);

// check.c
int  	command_exists(char *command, char **paths);
int     check_dependecies(char **paths);

// split.c
char	**split(char const *str, char sep);

// execute.c
int     execute_command(char **args);

#endif  //  DOWNY_H