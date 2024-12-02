#include "../inc/fractol.h"
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


double scale(double num, double min_n, double max_n, double min, double max)
{
  return ((max_n - min_n) * (num - min) / (max - min) + min_n);
}

int main (void)
{
	for (int i = 0; i <= WIDTH; i++)
		printf("%d -> %f\n", i, scale((double)i, -2, 2, 0, WIDTH));
}
*/
/* typedef struct s_fractal {
    void    *mlx;           // Pointer to MiniLibX instance
    void    *win;           // Pointer to the window
    void    *img;           // Pointer to the image
    int     width;          // Image width
    int     height;         // Image height
    double  min;            // Minimum value for fractal range
    double  max;            // Maximum value for fractal range
    int     max_iterations; // Maximum iterations for fractal calculation
} t_fractal;

double scale(double num, double min_n, double max_n, double min, double max)
{
  return ((max_n - min_n) * (num - min) / (max - min) + min_n);
}

void draw_fractal(t_fractal *frac) {
    for (int x = 0; x < frac->height; x++) {
        for (int y = 0; y < frac->width; y++) {
            // Map pixel coordinates to fractal space
            double a = scale(y, frac->min, frac->max, 0, frac->width);
            double b = scale(x, frac->min, frac->max, 0, frac->height);
            double ca = a;
            double cb = b;

            // Mandelbrot iteration
            int n = 0;
            while (n < frac->max_iterations) {
                double aa = a * a - b * b;
                double bb = 2 * a * b;
                a = aa + ca;
                b = bb + cb;

                if (a * a + b * b > 16) {
                    break;
                }
                n++;
            }

            // Brightness mapping
            double bright = scale(n, 0, frac->max_iterations, 0, 1.0);
            bright = sqrt(bright) * 255.0;
            if (n == frac->max_iterations) {
                bright = 0; // Point is in the set
            }

            // Calculate color (grayscale)
            uint32_t color = (int)bright << 24 | (int)bright << 16 | (int)bright << 8 | 255;
            mlx_put_pixel(frac->img, y, x, color);
        }
    }
}


void key_hook(mlx_key_data_t keydata, void *param) {
    t_fractal *frac = param;

    if (keydata.action == MLX_PRESS) {
        if (keydata.key == MLX_KEY_EQUAL) { // '+' key to zoom in
            frac->min *= 0.9;
            frac->max *= 0.9;
        } else if (keydata.key == MLX_KEY_MINUS) { // '-' key to zoom out
            frac->min /= 0.9;
            frac->max /= 0.9;
        }
        draw_fractal(frac); // Redraw the fractal
        mlx_image_to_window(frac->mlx, frac->img, 0, 0);
    }
}



int main() {
    t_fractal frac;

    // Initialize MLX42
    frac.mlx = mlx_init(800, 600, "Fractal", true);
    if (!frac.mlx) {
        return (EXIT_FAILURE);
    }

    // Create an image
    frac.img = mlx_new_image(frac.mlx, 800, 600);
    if (!frac.img) {
        mlx_terminate(frac.mlx);
        return (EXIT_FAILURE);
    }

    // Initialize fractal parameters
    frac.width = 800;
    frac.height = 600;
    frac.min = -3.0;
    frac.max = 3.0;
    frac.max_iterations = 50;

    // Draw initial fractal
    draw_fractal(&frac);
    mlx_image_to_window(frac.mlx, frac.img, 0, 0);

    // Set up key hook for interaction
    mlx_key_hook(frac.mlx, key_hook, &frac);

    // Start event loop
    mlx_loop(frac.mlx);

    // Clean up
   // mlx_delete_image(frac.mlx, frac.img);
    mlx_terminate(frac.mlx);
    return (EXIT_SUCCESS);
} */