#include <SDL.h>
#include <stdio.h>

//declaração dos métodos e variáveis
bool init();

bool loadMedia();

void close();

int tela_altura = 640;
int tela_largura = 640;

SDL_Surface* gSurface = NULL;

SDL_Window* gWindow = NULL;

SDL_Surface* gImage = NULL;

bool init() 
{  
    //bool que controla o sucesso da inicialização da janela
    bool success = true;

    //tratamento se SDL nao conseguir iniciar
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf ("erro ao inicializar o SDL: %s\n", SDL_GetError());
        success = false;
    }

    //inicialização real do SDL
    else 
    {
        //definindo a janela (titulo, posição)
        gWindow = SDL_CreateWindow ( "SDL_class2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, tela_largura, tela_altura, SDL_WINDOW_SHOWN );
        if ( gWindow == NULL ) 
        {
            printf ("erro ao inicializar window: %s\n" , SDL_GetError());
            success = false;
        }

        //em que janela a superficie faz referência?
        gSurface = SDL_GetWindowSurface ( gWindow );
    } 
    return success;
}

bool loadMedia() 
{
   bool success = true; 

   gImage = SDL_LoadBMP ("../assets/Draw.bmp");
   if (gImage == NULL ) 
   {
        printf( "nao foi possivel carregar a imagem: %s\n", SDL_GetError() );
        success = false; 
   }  
   return success;
}

void close() 
{
    SDL_FreeSurface ( gImage );
    gImage = NULL;

    SDL_DestroyWindow ( gWindow );
    gWindow = NULL;

    SDL_Quit();
}

int main (int argc, char* args[]) 
{
    if (!init() ) 
    {
        printf("falhou em inicializar");

    }

    else
    {
        if (!loadMedia())
        {
            printf("falhou em carregar midia");

        }
        else
        {
            //aplicando a imagem
            SDL_BlitSurface ( gImage, NULL, gSurface, NULL);

        SDL_UpdateWindowSurface( gWindow );

        SDL_Event e;
        bool quit = false;
        while ( quit == false )
        { while (SDL_PollEvent( &e)) { if (e.type == SDL_QUIT ){ quit = true; } }

        }
    }

    close();
    return 0;
    }
}   






























