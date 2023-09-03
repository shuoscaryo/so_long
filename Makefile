NAME := so_long

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
INCLUDE_DIR := include

LIBS := mlx\
	libft

FRAMEWORK := OpenGL\
	AppKit

SRC_FILES := ft_find_img.c\
	ft_game_display.c\
	ft_game_exit.c\
	ft_game_init.c\
	ft_game_load_map.c\
	ft_game_load_objs.c\
	ft_game_load_sprites.c\
	ft_game_move_player.c\
	ft_game_upd_exit.c\
	ft_game_upd_obj.c\
	ft_img_free.c\
	ft_img_get_pixel.c\
	ft_img_new.c\
	ft_img_new2.c\
	ft_img_pixel_put.c\
	ft_img_resize.c\
	ft_map_check.c\
	ft_map_check2.c\
	ft_map_get.c\
	ft_obj_add_pos.c\
	ft_obj_display.c\
	ft_obj_free.c\
	ft_obj_new.c\
	ft_obj_set_pos.c\
	ft_obj_set_sprite.c\
	get_next_line.c\
	get_next_line_utils.c\
	so_long.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
FRAMEWORK_FLAG := $(foreach item,$(FRAMEWORK),-framework $(item))
INCLUDE_PATH := -I$(INCLUDE_DIR) $(foreach item,$(LIBS),-I$(LIB_DIR)/$(item)/$(INCLUDE_DIR)) $(foreach item,$(LIBS),-I$(LIB_DIR)/$(item))
LIB_FILES := $(foreach item,$(LIBS),$(LIB_DIR)/$(item)/$(item).a)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIB_FILES) $(OBJ)
	@$(CC) $(CFLAGS) $(FRAMEWORK_FLAG) $(INCLUDE_PATH) -o $@ $(OBJ) lib/libft/libft.a lib/mlx/libmlx.a

$(LIB_FILES):
	@make -C $(@D)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB_FILES) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $< $(EXTERN_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@for lib in $(dir $(LIB_FILES)); do \
        make -C $$lib clean; \
    done

fclean: clean
	@$(RM) $(NAME) $(LIB_FILES)

re: clean all

.PHONY: clean fclean all re