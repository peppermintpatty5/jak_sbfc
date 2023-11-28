#ifndef SAVEFILE_H_
#define SAVEFILE_H_

#include <stdio.h>

struct savefile
{
    struct profile
    {
        char name[4];
        struct pb_set
        {
            int grill_skating;
            int air_patty;
        } pb;
    } slot1, slot2;
};

extern void read_savefile(struct savefile *save, FILE *in);

#endif
