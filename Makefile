#* TARGET *#
TARGET = breakout

#*SOURCE FILES *#
FILES = main.cpp Game.cpp TextureManager.cpp
		
SRC = $(addprefix src/, $(FILES))

#* OBJECT FILES *#
OBJS = $(SRC:%.cpp=%.o)

#* FLAGS *#
FLAGS = #-Wall -Wextra -Werror
SDL = -lmingw32 -lSDL2main -lSDL2 
TTF = -lSDL2_ttf 
IMG = -lSDL2_image

#* HEADER FILES *#
SDL_INCLUDE = include/
INCLUDE = headers/
#* LIBRARY *#
LIB = lib/

#* DELETE *#
DEL = rm -f

all: $(TARGET)

%.o: %.cpp
	g++ $(FLAGS) -c -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(IMG) $(TTF) $(SDL) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	g++ $(FLAGS) -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(OBJS) $(IMG) $(TTF) $(SDL) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all