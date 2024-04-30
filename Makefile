NAME = so_long
NAME_BONUS = so_long_bonus
MLX =  -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

CC = cc 

SRC = so_long.c print_errors.c libft/ft_itoa.c libft/ft_putstr.c libft/ft_split.c libft/ft_strlen.c \
	Rendering_map/check_map.c  Rendering_map/check_path.c Rendering_map/check_shape.c Rendering_map/find_position.c \
	Rendering_map/map_rendering.c Rendering_map/map_validation.c Rendering_game/setting_game.c  Rendering_game/display_game.c \
	Rendering_game/free_memory.c Rendering_game/moves.c Rendering_game/moves_.c

SRC_BONUS = src_bonus/so_long_bonus.c src_bonus/map_rendering_bonus.c print_errors.c libft/ft_itoa.c libft/ft_putstr.c libft/ft_split.c libft/ft_strlen.c  libft/ft_lstadd_back.c \
	Rendering_map/check_map.c  Rendering_map/check_path.c Rendering_map/check_shape.c Rendering_map/find_position.c \
	Rendering_map/map_rendering.c Rendering_map/map_validation.c src_bonus/display_game_bonus.c \
	Rendering_game/free_memory.c src_bonus/setting_game_bonus.c src_bonus/moves_bonus.c  src_bonus/Rendering_enemy.c\
	src_bonus/moves2_bonus.c src_bonus/enemy_move.c
OBG = $(SRC:.c=.o)

OBG_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
    
$(NAME) : $(OBG)
	@$(CC) $(CFLAGS) $(OBG) $(MLX) -o $(NAME)
	@echo "\033[1;34mLaunching build... 🚀\033[0m"
	@echo "\033[0;32mmake mandatory completed successfully! ✅\033[0m"

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBG_BONUS)
	@$(CC) $(CFLAGS) $(OBG_BONUS) $(MLX) -o $(NAME_BONUS)
	@echo "\033[1;34mLaunching build... 🚀\033[0m"
	@echo "\033[0;32mmake bonus completed successfully! ✅\033[0m"

clean:
	@rm -rf $(OBG) $(OBG_BONUS)
	@echo "\033[1;33mCleaning up... 🧹\033[0m"
	@echo "\033[0;32mclean completed successfully! ✅\033[0m"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "\033[1;31mFull clean initiated... 🔥\033[0m"
	@echo "\033[0;32mfclean completed successfully! ✅\033[0m"

re: fclean all bonus
	@echo "\033[1;35mRebuilding everything... 🔄\033[0m"
	@echo "\033[0;32mre completed successfully! ✅\033[0m"

.PHONY: all clean fclean re bonus

.SILENT:
