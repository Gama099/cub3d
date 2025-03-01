# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src_parsing
GNL_DIR = get_next_line

# Source files
SRC_FILES = $(SRC_DIR)/cub_parsing.c $(SRC_DIR)/parsing_map.c $(SRC_DIR)/parsing_texture.c \
            $(SRC_DIR)/errors.c $(SRC_DIR)/file_check.c $(SRC_DIR)/memmory.c \
            $(SRC_DIR)/parsing_color.c $(SRC_DIR)/parsing_map_ut.c $(SRC_DIR)/utilies2.c \
            $(SRC_DIR)/utilies1.c $(SRC_DIR)/utilies3.c
GNL_FILES = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(GNL_FILES:.c=.o)

# Output executable
TARGET = final_executable

# Rules
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
