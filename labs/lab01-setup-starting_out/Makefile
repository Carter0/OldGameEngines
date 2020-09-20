CXXFLAGS=
LDFLAGS=

## various options for possible build configurations
## comment in one of the following sets or add your own

## for optimization
CXXFLAGS:=$(CXXFLAGS) -O2
LDFLAGS:=$(LDFLAGS)

## for gdb or valgrind
#CXXFLAGS:=$(CXXFLAGS) -Og -ggdb -fno-inline -fno-omit-frame-pointer
#LDFLAGS:=$(LDFLAGS)

## for gprof
#CXXFLAGS:=$(CXXFLAGS) -O2 -pg
#LDFLAGS:=$(LDFLAGS) -pg





## the following should not need to change

## generic options
CXXFLAGS:=$(CXXFLAGS) -std=c++11 -Wall -Werror -pedantic-errors -Iinclude
LDFLAGS:=$(LDFLAGS) -std=c++11

## platform-specific options
ifeq ($(OS),Windows_NT)
	CXXFLAGS:=$(CXXFLAGS) -I/usr/include/SDL2
	LDFLAGS:=$(LDFLAGS) -L/usr/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
else ifeq ($(shell sh -c 'uname'),Darwin)
	CXXFLAGS:=$(CXXFLAGS) -F/Library/Frameworks -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers
	LDFLAGS:=$(LDFLAGS) -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf
else
	CXXFLAGS:=$(CXXFLAGS) $(shell sh -c 'sdl2-config --cflags')
	LDFLAGS:=$(LDFLAGS) $(shell sh -c 'sdl2-config --libs') -lSDL2_image -lSDL2_mixer -lSDL2_ttf
endif

## files
SOURCE_FILES=$(shell sh -c '/usr/bin/find src -name "*.cpp"')
HEADER_FILES=$(shell sh -c '/usr/bin/find include -name "*.hpp"')
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)

## rules
all: bin/main

bin/main: $(OBJECT_FILES)
	mkdir -p bin
	g++  $^ $(LDFLAGS) -o $@

%.o: %.cpp $(HEADER_FILES) Makefile
	g++ -c $< $(CXXFLAGS) -o $@

clean:
	rm -rf bin/ $(OBJECT_FILES) *.gcda *.gcno *.gcov gmon.out
