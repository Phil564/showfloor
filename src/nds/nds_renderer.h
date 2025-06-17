#ifndef NDS_RENDERER_H
#define NDS_RENDERER_H

enum Sprites {
    C_LEFT,
    C_RIGHT,
    STICK,
    STICK_BASE_1,
    STICK_BASE_2,
    STICK_BASE_3,
    STICK_BASE_4,
    MAX_SPRITES
};

struct Sprite {
    uint16_t *gfx_press;
    uint16_t *gfx_release;
    int x, y;
    bool vflip;
    bool pressed;
};

extern struct Sprite sprites[MAX_SPRITES];

extern void renderer_init();
extern void draw_frame(Gfx *display_list);

#endif // NDS_RENDERER_H
