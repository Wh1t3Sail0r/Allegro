#include "header/vector.h"
#include "header/display.h"

const int N_POINTS = 729;
vec3_t cube_points[N_POINTS];    // 9x9x9 cube

bool is_running = false;

void setup() {

    // Allocate 32 bits of memory for color for each pixel on the screen
    color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * win_width * win_height);

    // Pass the color buffer data to the color buffer texture
    color_buffer_texture = SDL_CreateTexture(
        renderer,   // Pointer to renderer
        SDL_PIXELFORMAT_ARGB8888,   // Pixel format (argb, 8 bits each)
        SDL_TEXTUREACCESS_STREAMING,    // Access type - we are updating every frame so use streaming
        win_width,  // Width to apply over
        win_height  // Height to apply over
    );

    // Start loading my array of vectors
    int i = 0;

    for(float x = -1; x <= 1; x += 0.25) {
        for(float y = -1; y <= 1; y += 0.25) {
            for(float z = -1; x <= 1; x += 0.25) {
                vec3_t point = { x, y, z };
                cube_points[i] = point;
                i++;
            }
        }
    }
}

void process_input() {

    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type) {

        case SDL_QUIT:

            is_running = false;

            break;

        case SDL_KEYDOWN:

            if(event.key.keysym.sym == SDLK_q) {    // Quit on Q key
                is_running = false;
            }

            break;
    }
}

void update() {

}

void render() {

    SDL_SetRenderDrawColor( // Select the draw color
        renderer,   // Pointer to renderer
        255,    // Red value
        255,    // Green value
        255,    // Blue value
        255     // Alpha value
    );

    SDL_RenderClear(renderer);  // Clear the renderer

    draw_grid(60, 0xFF606060);  // Draw a gray grid

    // draw_pixel(245, 425, 0xFFFFFFFF);   // Draw a white pixel

    // draw_rect(240, 180, 800, 600, 0xFFFF0000);  // Draw a red rectangle

    render_color_buffer();  // Render the color buffer texture

    clear_color_buffer(0xFF000000);   // Clear the color buffer to gray (hexa)

    SDL_RenderPresent(renderer);    // Draw on the renderer
}

int main() {

    // Create an SDL Window
    is_running = init_window();

    setup();

    while(is_running) {
        process_input();
        update();
        render();
    }

    quit();

    return 0;
}