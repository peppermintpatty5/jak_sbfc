#ifndef SAVEFILE_H_
#define SAVEFILE_H_

#include <stdio.h>

struct savefile
{
    struct profile
    {
        char name[4];
    } profiles[2];
};

extern void read_savefile(struct savefile *save, FILE *in);

#endif