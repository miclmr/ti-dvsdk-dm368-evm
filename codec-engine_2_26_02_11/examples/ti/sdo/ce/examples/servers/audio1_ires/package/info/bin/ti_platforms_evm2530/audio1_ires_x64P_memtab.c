#include <ti/sdo/ce/osal/Global.h>

static Global_ArmDspLinkConfigMemTableEntry memTable_audio1_ires_x64P[] = {
    {"DDR2", 0x82C00000, 0x82C00000, 0x00300000, 1, 0},
    {"DSPLINKMEM", 0x82F01000, 0x82F01000, 0x000FF000, 1, 0},
    {"RESET_VECTOR", 0x82F00000, 0x82F00000, 0x00001000, 1, 0},
    {"L4PER", 0x49000000, 0x49000000, 0x00800000, 0, 0},
    {"BUFMEM", 0x10F0FB00, 0x5CF0FB00, 0x00000500, 1, 0},
    {"L1DSRAM", 0x10F04000, 0x5CF04000, 0x0000BB00, 1, 0},
    {"DDRALGHEAP", 0x83000000, 0x83000000, 0x01000000, 0, 0},
    {"L4CORE", 0x48000000, 0x48000000, 0x01000000, 0, 0},
    {"CMEM", 0x00000000, 0x00000000, 0x00000000, 0, 0},
    {NULL, 0, 0, 0, 0, 0}
};
