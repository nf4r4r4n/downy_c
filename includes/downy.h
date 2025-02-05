#ifndef DOWNY_H
# define DOWNY_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>

# ifndef DOWNY_VERSION
#  define DOWNY_VERSION "5th Feb 2025"
# endif //  DOWNY_VERSION

# ifndef DOWNY_CREATOR
#  define DOWNY_CREATOR "nf4r4r4n<baibs.fararano@gmail.com>"
# endif //  DOWNY_CREATOR

// utils.c
void    print_error(const char *msg);
void    print_help(void);
void    print_version(void);

// check.c
int     check_dependecies(void);

#endif  //  DOWNY_H