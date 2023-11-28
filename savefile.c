#include <stdint.h>

#include "savefile.h"

#define SAVEFILE_SIZE 2048
#define SLOT1_OFFSET 0x8
#define SLOT2_OFFSET 0x100

/**
 * Decode 16-bit value from little endian.
 */
static inline uint16_t le16(uint8_t const *bytes)
{
    return ((uint16_t)bytes[0] << 000) | ((uint16_t)bytes[1] << 010);
}

/**
 * Decode 32-bit value from little endian.
 */
static inline uint32_t le32(uint8_t const *bytes)
{
    return ((uint32_t)bytes[0] << 000) | ((uint32_t)bytes[1] << 010) |
           ((uint32_t)bytes[2] << 020) | ((uint32_t)bytes[3] << 030);
}

static void load_profile(struct profile *profile, uint8_t const *data)
{
    uint16_t tag = le16(&data[0]);

    // letters A-Z encoded as 1-26, 5 bits each
    profile->name[0] = 'A' - 1 + ((tag >> 0) & 0x1f);
    profile->name[1] = 'A' - 1 + ((tag >> 5) & 0x1f);
    profile->name[2] = 'A' - 1 + ((tag >> 10) & 0x1f);
    profile->name[3] = '\0';

    // 24-bit values offset left by 3 bits
    profile->pb.grill_skating =
        (le32(&data[0x41]) >> 3) & 0xffffff;
    profile->pb.air_patty =
        (le32(&data[0x44]) >> 3) & 0xffffff;
}

void read_savefile(struct savefile *save, FILE *in)
{
    uint8_t buf[SAVEFILE_SIZE];

    fread(buf, 1, sizeof(buf), in);

    load_profile(&save->slot1, &buf[SLOT1_OFFSET]);
    load_profile(&save->slot2, &buf[SLOT2_OFFSET]);
}
