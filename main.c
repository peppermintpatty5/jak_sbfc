#include <stdio.h>
#include <stdlib.h>

#include "savefile.h"

int main(void)
{
    struct savefile save;

    freopen(NULL, "rb", stdin);
    read_savefile(&save, stdin);

    printf("%s: %i, %i\n",
           save.slot1.name,
           save.slot1.pb.grill_skating,
           save.slot1.pb.air_patty);

    return EXIT_SUCCESS;
}
