#include <stdint.h>

#include "savefile.h"

static void load_profile(struct profile *profile, uint8_t const *data)
{
    uint16_t tag = ((uint16_t)data[0] << 0) |
                   ((uint16_t)data[1] << 8);

    profile->name[0] = '@' + ((tag >> 0) & 0x1f);
    profile->name[1] = '@' + ((tag >> 5) & 0x1f);
    profile->name[2] = '@' + ((tag >> 10) & 0x1f);
    profile->name[3] = '\0';
}

void read_savefile(struct savefile *save, FILE *in)
{
    uint8_t buf[2048];

    fread(buf, 1, sizeof(buf), in);

    load_profile(&save->slot1, &buf[0x8]);
    load_profile(&save->slot2, &buf[0x100]);
}
