#ifndef PAS
#define PAS

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 50;

typedef struct s_memoryblock
{
	void					*ptr;
	size_t					size;
	struct s_memoryblock	*next;
}	t_memoryblock;

typedef enum {
    // ✅ No error
    ERR_NONE,

    // 📂 File-related errors
    ERR_FILE_NOT_FOUND,      // File does not exist
    ERR_FILE_EXTENSION,      // Incorrect file extension (not .cub)
    ERR_EMPTY_FILE,          // The file is empty
    ERR_FILE_PERMISSION,     // Cannot read file due to permission issues

    // 🎨 Texture-related errors
    ERR_MISSING_TEXTURE,     // A required texture (NO, SO, WE, EA) is missing
    ERR_DUPLICATE_TEXTURE,   // A texture identifier appears more than once
    ERR_INVALID_TEXTURE_PATH,// Texture path is missing or invalid
    ERR_TEXTURE_FILE_MISSING,// Texture file does not exist

    // 🌈 Color-related errors
    ERR_MISSING_COLOR,       // A required color (F or C) is missing
    ERR_DUPLICATE_COLOR,     // A color definition appears more than once
    ERR_INVALID_COLOR_FORMAT,// Incorrect color format (should be R,G,B)
    ERR_COLOR_OUT_OF_RANGE,  // RGB values must be between 0 and 255

    // 🗺️ Map-related errors
    ERR_MAP_NOT_CLOSED,      // The map is not surrounded by walls
    ERR_INVALID_MAP_CHAR,    // The map contains invalid characters
    ERR_MULTIPLE_PLAYERS,    // More than one player (N, S, E, W) found
    ERR_MISSING_PLAYER,      // No player position found
    ERR_INVALID_MAP_START,
    ERR_INVALID_MAP_END,
	ERR_NEW_LINE_IN_MAP,

    // 🔄 General errors
    ERR_INVALID_LINE,        // A line does not match any expected format
    ERR_MEMORY_ALLOCATION,   // Memory allocation failure

	//skip functions
	ERR_NOT_TEXTURE,
	ERR_NOT_IMG,
	ERR_NOT_MAP,
} error_code;

extern t_memoryblock *ghead;

typedef struct s_map_data {
	// tmep tools
	char *buffer;
    // Texture paths
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;

    // Colors
    int floor_color[3];    // RGB values
    int ceiling_color[3];  // RGB values

    // Map data
    char **map;           // 2D array of map characters
    int map_height;
    int map_width;

    // Player info
    int player_x;         // Starting X position
    int player_y;         // Starting Y position
    char player_dir;      // N, S, E, or W
} t_map_data;


// enum values	check_file(char *file_name, int *fd);
char	*get_next_line(int fd);
void    check_after_parsing(t_map_data *data);
t_map_data    *parsing_file(char *file_name);
void    check_file(char *file_name, int *fd);
int     is_colors(char *buffer);
void    parse_colors(t_map_data *data);
void    resize(char ***array, int size);
void    check_position(char *iter, t_map_data *data, int w, int h);
void    parse_map(t_map_data *data, int fd);
char    *is_path(char *path);
int     identifier_found(char *buffer);
void    parse_texture(t_map_data *data);
void    on_off(char *change);
void    assign_struct(t_map_data *data);
void	handle_error(error_code err);
void    print_error_message(error_code code);
void    print_map_data(t_map_data *data);
int     open_file(char *file_name, int close_flag);
int     is_space(char c);
int     is_digit(char c);
int     ft_atoi(const char *str);
void    trim_buffer(char **buffer);
int     is_maap(char *buffer);
int     is_extension(char *file_name, char *extan);
int     is_allawed(char *iter);
void	check_last_close(char *iter);
void	assign_directions(int w, int h, t_map_data *data);
void	check_position(char *iter, t_map_data *data, int w, int h);
void	set_map_line(char *buffer, size_t *size, t_map_data *data);
void	cleanup(void);
void	*my_malloc(size_t size);

int     ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char    *ft_strchr(const char *s, int c);
int     ft_strcmp(const char *s1, const char *s2);

void    print_file_error(error_code code);
void    print_texture_error(error_code code);
void    print_color_error(error_code code);
void    print_map_error(error_code code);
void    print_general_error(error_code code);

#endif
