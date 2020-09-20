#include "base/SDLGraphicsProgram.hpp"
#include "breakout/Breakout.hpp"
#include <memory>

int main(int argc, char *argv[]) {
	std::cout << "Welcome to Breakout! Move left and right using the arrow keys, and try to hit the ball into the blocks.\n"
					"The ball will bounce off the paddle on the side it hits the paddle, with flatter angles toward the sides.\n"
					"You can also press 'n' to skip to the next level and 'q' to quit.\n" << std::endl;
	std::shared_ptr<Breakout> level = std::make_shared<Breakout>(1280, 720);
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(level);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
