# Masukkan semua file cpp Anda
OBJS = main.cpp oop.cpp Aquarium.cpp LinkedList.cpp Piranha.cpp Guppy.cpp Ikan.cpp Siput.cpp HewanAir.cpp Pellet.cpp Koin.cpp AquariumObject.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
