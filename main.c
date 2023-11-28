#include <stdio.h>
#include <stdlib.h>

#include "savefile.h"

int main(void)
{
    struct savefile save;

    freopen(NULL, "rb", stdin);
    read_savefile(&save, stdin);

    puts(save.profiles[0].name);

    return EXIT_SUCCESS;
}
