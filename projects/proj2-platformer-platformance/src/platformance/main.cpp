#include "base/SDLGraphicsProgram.hpp"
#include "platformance/Platformance.hpp"
#include <memory>

int main(int argc, char* argv[]){
  std::shared_ptr<Platformance> level = std::make_shared<Platformance>(1280, 720);
  // Create an instance of an object for a SDLGraphicsProgram
  SDLGraphicsProgram mySDLGraphicsProgram( std::dynamic_pointer_cast<Level>(level));
  // Run our program forever
  mySDLGraphicsProgram.loop();
  // When our program ends, it will exit scope, the
  // destructor will then be called and clean up the program.
  return 0;
}
