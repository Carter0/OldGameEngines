#include "base/SDLGraphicsProgram.hpp"
#include "platformance/Platformance.hpp"
#include <memory>

int main(int argc, char *argv[]) {
	std::cout << "Welcome to Platformance! Move around using the arrow keys, dodge the bees, collect the coins, and touch the flag to move on.\n"
					"You can also press 'n' to skip to the next level and 'q' to quit.\n" << std::endl;
	std::shared_ptr<Platformance> level = std::make_shared<Platformance>(1280, 720);
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(level);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
