#include "base/SDLGraphicsProgram.hpp"
#include "emberetta/Emberetta.hpp"
#include <memory>

int main(int argc, char *argv[]) {
	std::cout << "Welcome to Emberetta! Move around using the arrow keys, shoot stuff with space, don't get shot, and have fun.\n"
			"You can also press 'n' to skip, 'r' to restart, and 'q' to quit." << std::endl <<
			"Blue is a machine gun, Purple is a spread, Green does more damage and destroys bullets" << std::endl;
	std::shared_ptr<Emberetta> level = std::make_shared<Emberetta>(640, 800);
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(level);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
