##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

######### FLAGS #########
CFLAGS	=	-Wall -Wextra

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lcsfml-network

######### SOURCES #########
SRC =	src/main.c			\
	src/window.c			\
	src/background.c		\
	src/create_sprite.c		\
	src/shop_sprite.c		\
	src/sprite_mouse.c		\
	src/event_mouse.c		\
	src/place_sprite.c		\
	src/clock_towers.c		\
	src/create_mobs.c		\
	src/move_mob.c			\
	src/create_towers.c		\
	src/menu.c			\
	src/menu_buttons.c		\
	src/my_nodelen.c		\
	src/destroy_mobs.c		\
	src/display_gold.c		\
	src/my_getnbr.c			\
	src/my_itoa.c			\
	src/my_revstr.c			\
	src/option_ingame.c		\
	src/clock_wave.c		\
	src/error.c			\
	src/kill_mobs.c			\
	src/my_getenv.c			\
	src/begin_settings.c		\
	src/display_life.c		\
	src/attack_tower.c		\
	src/display_damage.c		\
	src/display_buttons.c		\
	src/upgrade_tower.c		\
	src/create_music.c		\
	src/kill_towers.c		\
	src/ingame.c			\
	src/end_game.c			\
	src/mute_music.c		\
	src/free_struct.c		\
	src/hi_score.c

OBJ = $(SRC:.c=.o)

NAME = my_defender

IDIR	=	./include

CC	=	clang

######### Rules ###########
all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	rm -f $(OBJ)

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re tests_run

tests_run:	LDFLAGS	+= -lcriterion --coverage
tests_run:
		gcc -o unit_tests  $(CPPFLAGS) $(LDFLAGS)
		./unit_tests
		gcovr -e tests/
