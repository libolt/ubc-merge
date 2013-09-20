
#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return 1;
    }
return 0;
}