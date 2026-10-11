
#include <3ds.h>
#include <stdio.h>

int main(void)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    const char *mods[] = {
        "Yoshi 3D Land",
        "Luigi",
        "Peach",
        "Toad"
    };

    const int count = sizeof(mods) / sizeof(mods[0]);
    int selected = 0;

    while (aptMainLoop()) {
        hidScanInput();
        u32 keys = hidKeysDown();

        if (keys & KEY_START)
            break;

        if (keys & KEY_UP)
            selected = (selected + count - 1) % count;

        if (keys & KEY_DOWN)
            selected = (selected + 1) % count;

        consoleClear();
        printf("=== 3D LAND MOD HUB ===\n\n");
        printf("Choose a mod:\n\n");

        for (int i = 0; i < count; i++) {
            printf("%s %s\n",
                i == selected ? ">" : " ",
                mods[i]);
        }

        printf("\nD-Pad: Navigate\n");
        printf("A: View status\n");
        printf("START: Exit\n");

        if (keys & KEY_A) {
            printf("\nSelected: %s\n", mods[selected]);
            printf("Menu prototype only.\n");
            printf("No game files changed.\n");
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
