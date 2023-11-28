#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct savefile
{
    struct profile
    {
        char name[4];
    } profiles[2];
};

void read_savefile(struct savefile *save, FILE *in)
{
    uint8_t buf[2048];

    fread(buf, 1, sizeof(buf), in);

    uint8_t *p1_chunk = &buf[0x8];
    uint16_t p1_tag = ((uint16_t)p1_chunk[0] << 0) |
                      ((uint16_t)p1_chunk[1] << 8);

    save->profiles[0].name[0] = '@' + ((p1_tag >> 0) & 0x1f);
    save->profiles[0].name[1] = '@' + ((p1_tag >> 5) & 0x1f);
    save->profiles[0].name[2] = '@' + ((p1_tag >> 10) & 0x1f);
    save->profiles[0].name[3] = '\0';
}

int main(void)
{
    struct savefile save;

    freopen(NULL, "rb", stdin);
    read_savefile(&save, stdin);

    puts(save.profiles[0].name);

    return EXIT_SUCCESS;
}
