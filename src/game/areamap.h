#ifndef AREAMAP_H
#define AREAMAP_H

#include "types.h"

// Actual variables from the iQue source's areamap.h
struct AreaMapData {
    u8 *image_upper;	/* Texture Top Half */
    u8 *image_lower;	/* Texture Bottom Half */
    float xo_g;		/* Arrow X Offset */
    float zo_g;		/* Arrow Z Offset */
    float side_g;	/* Areamap Size (used for arrow placement) */
};

Gfx *AreaMap(s32 callContext, struct GraphNode *node, UNUSED void *data);

#endif /* AREAMAP_H */
