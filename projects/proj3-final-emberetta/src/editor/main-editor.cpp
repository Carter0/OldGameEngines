#include "base/SDLGraphicsProgram.hpp"
#include "platformance/PlatformanceEditor.hpp"
#include "breakout/BreakoutEditor.hpp"
#include "emberetta/EmberettaEditor.hpp"
#include <memory>
#include <dirent.h>
#include "Util.hpp"

//! \brief The Main class for the game's level editor system.
int main(int argc, char *argv[]) {
	std::cout << "Welcome to the Level Editor!\n"
			"The controls are pretty simple. Press e to cycle through placement modes!\n"
			"Each placement mode will be described in the console. Make sure to keep an eye on it for details.\n"
			"Left click, hold, and drag to place objects. Right click to remove them!\n"
			"You may be able to pause some games for easier editing by pressing SPACE BAR, or 'p' if SPACE BAR is used in the game.\n"
			"Finally, press 'n' to advance to the next level, press 's' to save the level, and 'r' to restart it!\n"
			"WARNING: Moving the player into the flag in the Platform will crash the editor. Just use 'n' for level progression.\n\n"
			"Which type of game would you like to edit? Please type 'breakout,' 'platformance,' or 'emberetta.'\n" << std::endl;

	std::string gametype;
	while (gametype != "breakout" && gametype != "platformance" && gametype != "emberetta") {
		std::cin >> gametype;
	}

	std::cout << "These are the levels currently available.\n" << std::endl;

	DIR *dir;
	struct dirent *ent;
	int begin = -1, end = -1;
	if ((dir = opendir(getResourcePath(gametype + "/levels").c_str())) != NULL) {
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

	std::shared_ptr<Level> level;
	if (gametype == "platformance") {
		level = std::make_shared< PlatformanceEditor > (1280, 720);
	} else if (gametype == "breakout") {
		level = std::make_shared< BreakoutEditor > (1280, 720);
	} else if (gametype == "emberetta") {
		level = std::make_shared< EmberettaEditor > (640, 800);
	}
	level->setLevel(i);
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(std::dynamic_pointer_cast < Level > (level), i);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
