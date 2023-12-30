##
## EPITECH PROJECT, 2023
## cpp_sfml
## File description:
## Makefile
##

CC	=	g++

SRC		=	src/get_error.cpp	\
			src/main_game.cpp	\
			src/init/init.cpp	\
			src/destroy/destroy.cpp	\
			src/core/core.cpp	\
			src/draw/draw.cpp

MAIN	=	src/main.cpp

NAME	=	cppSfmlTemplate

INCLUDE_FOLDER	=	./includes
SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system
CFLAGS		=	-Wall -Wextra $(SFML_FLAGS)
CPPFLAGS	=	-iquote $(INCLUDE_FOLDER)

OBJ	=		$(SRC:.cpp=.o)

DEBUG_FLAGS	=	-g3
DEBUGER	=	valgrind
VALGRIND_FLAGS	=	--leak-check=full --show-leak-kinds=all -s\
					--track-origins=yes

all:	$(NAME)

$(NAME):	SRC += $(MAIN)
$(NAME):	$(OBJ) $(MAIN:.cpp=.o)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(SFML_FLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(MAIN:.cpp=.o)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:	CFLAGS += $(DEBUG_FLAGS)
debug:	fclean $(NAME)

run_debug:	debug
	$(DEBUGER) $(VALGRIND_FLAGS) ./$(NAME)

build_binary:	re
	$(MAKE) clean

.PHONY: all clean fclean re debug run_debug build_binary
