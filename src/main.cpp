#include <SDL.h>
#include <stdio.h>

const int tela_largura = 640;
const int tela_altura = 480;

int main (int argc, char* args[]) 
{
    SDL_Window* window = NULL;

    SDL_Surface* superficie_tela = NULL;

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf ( "SDL nao conseguiu inicializar, SDL_ERROR: %s\n", SDL_GetError() );
    } 

    else
    {
        window = SDL_CreateWindow ( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, tela_largura, tela_altura, SDL_WINDOW_SHOWN );

        if ( window == NULL ) 
        { 
            printf ( "a janela pode inicializar! SDL_Error: %s\n", SDL_GetError() );
        }

        else 
        {
        superficie_tela = SDL_GetWindowSurface ( window );

        SDL_FillRect ( superficie_tela, NULL, SDL_MapRGB( superficie_tela->format, 0xFF, 0xFF, 0xFF ) );

        SDL_UpdateWindowSurface( window );

        SDL_Event e; bool quit = false;
            while ( quit == false ) 
            {
                while ( SDL_PollEvent ( &e ) )
                        {
                            if (e.type == SDL_QUIT )
                            {
                                quit = true;
                            }
                        }
            }
        }
    }

    SDL_DestroyWindow ( window );
    SDL_Quit();
    return 0;
}

















