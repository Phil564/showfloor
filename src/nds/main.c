#include <stdio.h>

#include "nds_include.h"
#include <fat.h>

#include "audio/data.h"
#include "audio/external.h"
#include "audio/load.h"
#include "audio/seqplayer.h"
#include "game/game_init.h"
#include "nds_renderer.h"

u8 nds_audio_state;
static u8 audio_step;
static u8 fps;

void exec_display_list(struct SPTask *spTask) {
    draw_frame((Gfx*)spTask->task.t.data_ptr);
    fps++;
}

static void update_audio(void) {
    // Update audio at the ARM7's request
    if (nds_audio_state == 0) {
        // Update the audio logic at 30 Hz
        if ((audio_step = (audio_step + 1) & 7) == 0) {
            update_game_sound();
            gAudioFrameCount += 2;
            gAudioRandom = ((gAudioRandom + gAudioFrameCount) * gAudioFrameCount);
        }

        // Update the sequences at 240 Hz
        process_sequences(0);
    } else if (nds_audio_state == 1) {
        // Disable audio
        for (int i = 0; i < 16; i++) {
            gNotes[i].enabled = false;
        }
        nds_audio_state = 2;
    }

    // Tell the ARM7 it can go ahead
    IPC_SendSync(0);
}

static void update_fps(void) {
    // Draw and reset the FPS counter
    consoleClear();
    printf("FPS: %d\n", fps);
    fps = 0;
}


static void *fs_load_file(const char *vpath, int *outsize) {
    FILE* f = fopen(vpath, "rb");
    if (!f) return NULL;

    fseek(f,0,SEEK_END);
	int size = ftell(f);
	fseek(f,0,SEEK_SET);
    if (size <= 0) {
        fclose(f);
        return NULL;
    }

    void *buf = malloc(size);
    if (!buf) {
        fclose(f);
        return NULL;
    }

    int rx = fread(buf, 1, size, f);
    fclose(f);

    if (rx < size) {
        free(buf);
        return NULL;
    }

    if (outsize) *outsize = size;
    return buf;
}

int main(void) {
    static u64 pool[0x165000 / sizeof(u64)];
    main_pool_init(pool, pool + sizeof(pool) / sizeof(pool[0]));
    gEffectsMemoryPool = mem_pool_init(0x4000, MEMORY_POOL_LEFT);

    // Initialize various components
    fatInitDefault();
    renderer_init();
    audio_init();
    sound_init();

    // Set up audio on the ARM9 side
    irqSet(IRQ_IPC_SYNC, update_audio);
    irqEnable(IRQ_IPC_SYNC);

    // Give the ARM7 a pointer to the audio data
    fifoSendValue32(FIFO_USER_01, (u32)gNotes);

#ifdef ENABLE_FPS
    // Update the FPS counter every second
    timerStart(0, ClockDivider_1024, TIMER_FREQ_1024(1), update_fps);
#endif

    // Run the game
    thread5_game_loop(NULL);

    return 0;
}
