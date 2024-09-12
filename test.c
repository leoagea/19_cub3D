#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define ESC_KEY 53  // Keycode pour la touche "ESC" sur Mac

// Gestionnaire d'événements pour fermer la fenêtre avec la touche ESC
int handle_keypress(int keycode, void *param)
{
    if (keycode == ESC_KEY) {
        printf("ESC pressed, closing the window.\n");
        exit(0);  // Fermer le programme
    }
    return (0);
}

// Gestionnaire d'événements pour fermer la fenêtre via la croix de fermeture
int handle_close(void *param)
{
    printf("Window closed, exiting.\n");
    exit(0);  // Fermer le programme
    return (0);
}

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img;
    void *img_2;
    int x;
    int y;

    // Initialisation de la connexion à la bibliothèque MLX
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL) {
        fprintf(stderr, "Erreur: Impossible d'initialiser MiniLibX.\n");
        return (1);
    }

    // Création d'une fenêtre
    win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "MiniLibX Test");
    if (win_ptr == NULL) {
        fprintf(stderr, "Erreur: Impossible de créer la fenêtre.\n");
        return (1);
    }

    img = mlx_xpm_file_to_image(mlx_ptr,"./assets/menu/Victory.xpm", &x, &y);
    img_2 = mlx_xpm_file_to_image(mlx_ptr,"./assets/menu/Waiting_victory.xpm", &x, &y);

    mlx_put_image_to_window(mlx_ptr, win_ptr, img, 440, 275);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_2, 375,500);
    // Gestion de la fermeture avec la croix de fermeture de la fenêtre
    mlx_hook(win_ptr, 17, 0, handle_close, NULL);

    // Gestion de la touche ESC pour quitter le programme
    mlx_key_hook(win_ptr, handle_keypress, NULL);

    // Boucle d'événements MLX (nécessaire pour garder la fenêtre ouverte)
    mlx_loop(mlx_ptr);

    return (0);
}
