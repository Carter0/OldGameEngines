#include "base/SDLGraphicsProgram.hpp"
#include "platformance/PlatformanceEditor.hpp"
#include <memory>
#include <dirent.h>

//! \brief The Main class for the game's level editor system.
int main(int argc, char *argv[]) {
	std::cout << "Welcome to the Platformance Level Editor!\n"
			"The controls are pretty simple. Press one of the number keys to switch placement modes!\n"
			"Press 5 to place coins. You can have as many of these as you want.\n"
			"Press 6 to place the player. Only one per level!\n"
			"Press 7 to place a block. You can have as many of these as you want, and this is the default placement mode!\n"
			"Press 8 to place the goal. Only one per level!\n"
			"Press 9 to place enemies! You can have as many of these as you want.\n"
			"Left click, hold, and drag to place objects.\n"
			"Right click to remove them!\n"
			"Finally, press 'n' to advance to the next level, press 's' to save the level, and 'r' to restart it!\n"
			"WARNING: Moving the player into the flag will crash the editor. Just use 'n' for level progression.\n\n"
			"These are the levels currently available." << std::endl;

	DIR *dir;
	struct dirent *ent;
	int begin = -1, end = -1;
	if ((dir = opendir("res/levels")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			if (((std::string)(ent->d_name)).rfind(".", 0) != 0) {
				printf("%s\n", ent->d_name);
				if (begin == -1) {
					begin = std::stoi(ent->d_name);
				}
				if (std::stoi(ent->d_name) > end) {
					end = std::stoi(ent->d_name);
				}
			}
		}
		closedir(dir);
	}
	int i = -2;
	std::cout << "Please type the number of one of them to begin editing it!" << std::endl;
	while (!(begin <= i && i <= end)) {
		std::cin >> i;
	}

	std::shared_ptr<PlatformanceEditor> level = std::make_shared< PlatformanceEditor > (1280, 720);
	level->setLevel(i);
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(std::dynamic_pointer_cast < Level > (level), i);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
