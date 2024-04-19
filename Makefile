NAME = so_long

# NAME_BONUS = pipex_bonus

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc 

SRC = so_long.c print_errors.c libft/ft_itoa.c libft/ft_putstr.c libft/ft_split.c libft/ft_strlen.c \
	Rendering_map/check_map.c  Rendering_map/check_path.c Rendering_map/check_shape.c Rendering_map/find_position.c \
	Rendering_map/map_rendering.c Rendering_map/map_validation.c

SRC_BONUS = pipex_bonus.c utils_bonus.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strjoin.c \
	libft/ft_split.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c utils_1_bonus.c libft/ft_strchr.c \
	   here_doc.c utils_1.c libft/ft_strcmp.c
OBG = $(SRC:.c=.o)

OBG_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
    
$(NAME) : $(OBG)
	@$(CC) $(CFLAGS) $(OBG) -o $(NAME)
	@echo "\033[1;34mLaunching build... 🚀\033[0m"
	@echo "\033[0;32mmake mandatory completed successfully! ✅\033[0m"

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBG_BONUS)
	@$(CC) $(CFLAGS) $(OBG_BONUS) -o pipex
#@echo "\033[1;34mLaunching build... 🚀\033[0m"
#@echo "\033[0;32mmake bonus completed successfully! ✅\033[0m"

clean:
	@rm -rf $(OBG) $(OBG_BONUS)
	@echo "\033[1;33mCleaning up... 🧹\033[0m"
	@echo "\033[0;32mclean completed successfully! ✅\033[0m"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "\033[1;31mFull clean initiated... 🔥\033[0m"
	@echo "\033[0;32mfclean completed successfully! ✅\033[0m"

re: fclean all
	@echo "\033[1;35mRebuilding everything... 🔄\033[0m"
	@echo "\033[0;32mre completed successfully! ✅\033[0m"

.SILENT: