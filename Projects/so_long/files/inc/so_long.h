/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:11:36 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 17:53:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**
 * @file so_long.h
 * @brief Core definitions and prototypes for the so_long game.
 */

# include "../lib/libft/src/libft.h"
# include "../gnl/get_next_line.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* -------------------------------------------------------------------------- */
/* Constants                                                                  */
/* -------------------------------------------------------------------------- */

/** @name Game Settings */
/**@{*/
# define IMG_SIZE       50               /**< Pixel size of each square tile */
# define IMG_WALL       "./img/wall.xpm"
# define IMG_PLAYER_U   "./img/player_U.xpm"
# define IMG_PLAYER_D   "./img/player_D.xpm"
# define IMG_PLAYER_R   "./img/player_R.xpm"
# define IMG_PLAYER_L   "./img/player_L.xpm"
# define IMG_EXIT_CLOSE "./img/exit_close.xpm"
# define IMG_EXIT_OPEN  "./img/exit_open.xpm"
# define IMG_EMPTY      "./img/empty.xpm"
# define IMG_COLLECT    "./img/collect.xpm"
# define IMG_WINNER     "./img/winner.xpm"
/**@}*/

/** @name Error Messages */
/**@{*/
# define ERR_ARG        "Invalid argument"
# define ERR_MEM        "Cannot allocate memory"
# define ERR_MLX        "MLX cannot be initialized"
# define ERR_IMG        "\nFailed to load textures"
# define ERR_MAP_TYPE   "Invalid map type"
# define ERR_MAP_SIZE   "Invalid map size"
# define ERR_MAP_FILE   "Cannot access the map or does not exist"
# define ERR_MAP_FORM   "The map must be rectangular"
# define ERR_MAP_CHAR   "Map contains invalid characters"
# define ERR_MAP_WALL   "The map must be surrounded by walls"
# define ERR_NO_PLAYER  "The map dont have starting position"
# define ERR_NO_EXIT    "The map dont have exit"
# define ERR_DUPLCATE   "The map contains a duplicates characters (exit/start)"
# define ERR_COLLECT    "The map dont have collectibles"
# define ERR_MAP_PATH   "The map does not have a valid path"
/**@}*/

/* -------------------------------------------------------------------------- */
/* Structures                                                                 */
/* -------------------------------------------------------------------------- */

/**
 * @struct s_player
 * @brief Player coordinates and movement state.
 */
typedef struct s_player
{
    int     x;      /**< Current x position on the grid */
    int     y;      /**< Current y position on the grid */
    int     old_x;  /**< Previous x position for redrawing floor */
    int     old_y;  /**< Previous y position for redrawing floor */
    char    item;   /**< Identifier of the item the player is on */
}               t_player;

/**
 * @struct s_map_img
 * @brief Container for all MLX image pointers (textures).
 */
typedef struct s_map_img
{
    void    *empty;   /**< Floor sprite pointer */
    void    *wall;    /**< Wall sprite pointer */
    void    *collect; /**< Collectible sprite pointer */
    void    *exit;    /**< Exit (open or closed) sprite pointer */
    void    *player;  /**< Active player sprite pointer */
    void    *winner;  /**< Victory screen overlay pointer */
}               t_map_img;

/**
 * @struct s_vars
 * @brief Main engine structure containing all game state data.
 */
typedef struct s_vars
{
    void        *mlx;          /**< MLX library connection */
    void        *win;          /**< Window pointer */
    int         map_w;         /**< Map width in tiles */
    int         map_h;         /**< Map height in tiles */
    int         collect;       /**< Total collectibles to be picked up */
    int         spaces;        /**< Count of empty floor spaces */
    int         has_exit;      /**< Exit presence flag */
    int         exit_x;        /**< Exit x-coordinate */
    int         exit_y;        /**< Exit y-coordinate */
    int         map_file;      /**< File descriptor for .ber file */
    char        **map_data;    /**< 2D grid representing the map */
    char        *map_line;     /**< Buffer for current line reading */
    int         map_updated;   /**< Trigger for screen refresh */
    int         test_collect;  /**< Current collected count for win condition */
    int         test_exit;     /**< Exit accessibility status */
    int         count_moves;   /**< Counter for total player movements */
    t_map_img   *map_img;      /**< Pointer to image assets */
    t_player    *player;       /**< Pointer to player state */
}               t_vars;

/* -------------------------------------------------------------------------- */
/* Function Prototypes                                                        */
/* -------------------------------------------------------------------------- */

void    check_name(char *map_name, int argc);
int     print_error(char *msg, t_vars *game);
void    init_game_vars(t_vars *game_vars);
void    open_map(char **argv, t_vars *game);
int     set_player(t_vars *game, int x, int y);
int     check_map(t_vars *game);
void    start_game(t_vars *game);
int     key_control(int key, t_vars *game);
void    put_image(t_vars *game, t_img *img, int x, int y);
void    update_player_direction(t_vars *game, int key);
void    free_map(char **map, int map_height);
void    free_vars(t_vars *game);
int     close_game(t_vars *game);

#endif