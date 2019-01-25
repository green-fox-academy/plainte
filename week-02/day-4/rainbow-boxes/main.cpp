#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void createRainbowSquare(int& x, int * y){
    SDL_SetRenderDrawColor(gRenderer, y[0], y[1], y[2], 255);
    //create a rectangle
    SDL_Rect fillRect = { 0 + x, 0 + x, 480 - x * 2,480 - x * 2};
    //draw rectangle
    SDL_RenderFillRect( gRenderer, &fillRect );
}

void draw()
{
    int size;
    int color[3];
    int *p_color = color;
    for (int i = 0; i < 7; i++){
        size = i * 30;
        if (i == 0) {
            color[0] = 255;
            color[1] = 0;
            color[2] = 0;
            createRainbowSquare(size, p_color);
        } else if (i == 1) {
            color[0] = 255;
            color[1] = 165;
            color[2] = 0;
            createRainbowSquare(size, p_color);
        } else if (i == 2) {
            color[0] = 255;
            color[1] = 255;
            color[2] = 0;
            createRainbowSquare(size, p_color);
        } else if (i == 3) {
            color[0] = 0;
            color[1] = 128;
            color[2] = 0;
            createRainbowSquare(size, p_color);
        } else if (i == 4) {
            color[0] = 0;
            color[1] = 255;
            color[2] = 255;
            createRainbowSquare(size, p_color);
        } else if (i == 5) {
            color[0] = 0;
            color[1] = 0;
            color[2] = 255;
            createRainbowSquare(size, p_color);
        } else if (i == 6) {
            color[0] = 238;
            color[1] = 130;
            color[2] = 238;
            createRainbowSquare(size, p_color);
        }
    }
    // Create a square drawing function that takes 2 parameters:
    // The square size, and the fill color,
    // and draws a square of that size and color to the center of the canvas.
    // Create a loop that fills the canvas with rainbow colored squares.
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Rainbow box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}