/*
#include "mlx.h"  // Include appropriate mlx header

#define WIDTH 800
#define HEIGHT 600
#define RED 0xFF0000

typedef struct s_fractal {
    void        *mlx;
    mlx_image_t *img;
    int         width;
    int         height;
} t_fractal;

static void draw_pixel(t_fractal *frac, uint32_t color)
{
    int x, y;

    for (x = 0; x < frac->height; x++) {
        for (y = 0; y < frac->width; y++) {
            mlx_put_pixel(frac->img, y, x, color);
        }
    }
}

void resize_hook(int32_t width, int32_t height, void *param)
{
    t_fractal *frac = (t_fractal *)param;

    frac->width = width;
    frac->height = height;

    // Resize the image
    mlx_delete_image(frac->mlx, frac->img);
    frac->img = mlx_new_image(frac->mlx, width, height);
    if (!frac->img) {
        write(1, "Image resizing failed\n", 23);
        mlx_terminate(frac->mlx);
        exit(1);
    }

    // Redraw the content
    draw_pixel(frac, RED);
    mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}

int main(void)
{
    t_fractal frac;

    frac.width = WIDTH;
    frac.height = HEIGHT;
    frac.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
    if (!frac.mlx)
        ft_error();
    frac.img = mlx_new_image(frac.mlx, WIDTH, HEIGHT);
    if (!frac.img) {
        write(1, "Image creation failed\n", 22);
        return 1;
    }

    draw_pixel(&frac, RED);
    mlx_image_to_window(frac.mlx, frac.img, 0, 0);

    // Hook for window resize
    mlx_resize_hook(frac.mlx, resize_hook, &frac);

    mlx_loop(frac.mlx);
    mlx_terminate(frac.mlx);
    return 0;
}

*/