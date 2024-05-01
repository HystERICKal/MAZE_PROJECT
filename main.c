#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

const int DISPLAY_WIDENESS = 640;
const int DISPLAY_HEIGHT = 480;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *args[])
{
    SDL_Window *screen = NULL;

    SDL_Surface *surface_of_window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Starting SDL Failed!: %s\n", SDL_GetError());
    }
    else
    {
        screen = SDL_CreateWindow("SDL How To", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDENESS, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
        if (screen == NULL)
        {
            printf("Screen creation Failed!: %s\n", SDL_GetError());
        }
        else
        {
            surface_of_window = SDL_GetWindowSurface(screen);

            SDL_FillRect(surface_of_window, NULL, SDL_MapRGB(surface_of_window->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(screen);

            SDL_Event sv;
            bool leave = false;
            while (leave == false)
            {
                while (SDL_PollEvent(&sv))
                {
                    if (sv.type == SDL_QUIT)
                        leave = true;
                }
            }
        }
    }

    SDL_DestroyWindow(screen);

    SDL_Quit();

    return 0;
}