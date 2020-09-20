# cs4850-lab-resourcemanager

## Instructions

In this lab you'll implement a small resource manager.

*This lab is adapted from one designed by [Michael D. Shah](http://www.mshah.io).*

*The sprite sheet includes a character from the game [Braid](https://en.wikipedia.org/wiki/Braid_(video_game)).*



### Part 1 - Implementation

Your goal is to implement a resource manager in the code in `ResourceManager.hpp` and `ResourceManager.cpp`. Ideally, you will have a class that you can reuse. Your resource manager should also be a *singleton*, and it will handle *image/texture* resources loaded from SDL. The goal of the resource manager for this lab is to ensure that only one copy of a resource (in this case, image/texture) is loaded at any given time.

Note: Your singleton should support the ability to load *multiple* images, and not just the one provided.  Resources should use the `getResourcePath` functionality from previous labs.

The main function you need to fix is the `init` function for the Game Character. Think about how you might refactor your code to load resources using your resource manager. You may make any additional changes to the code. The key is to make sure exactly 1 copy of the image is loaded.



### Part 2 - Documentation

Good documentation can help others (and yourself) reuse your code!

We will use Doxygen for generating documentation.  Doxygen will generate documentation directly from comments in your source code.  You can download and install Doxygen for your system from the [Doxygen website](http://www.doxygen.nl/). You can look over the [overview of Doygen comments](http://www.doxygen.nl/manual/docblocks.html).

The Makefile and Doxyfile are set up to generate documentation if you have Doxygen installed. To build the documentation, right click on the project in Eclipse, choose "Build Targets..." -> "Create...", and in the dialog enter "doc" for target name, then click "OK".  You can then double click the "doc" build target in Eclipse project.  It will put the root of the documentation in the `doc/html/index.html` file.

Document the ResourceManager class (i.e. add Doxygen comments to `ResourceManager.hpp`), including all of its public member functions.

Notes:
* On macOS you may need to run `xattr -d com.apple.quarantine /Applications/Doxygen.app` to allow running Doxygen.



### Part 3 - Extensions

Choose and implement **at least one** of the following extensions (you can do more if you like):
* Fix the animation so it uses all the frames in the image file.
* Add another image file and use your resource manager to load it in (and show it on the screen).
* Try using smart pointers (e.g. shared_ptr). This could help keep track of the number of references to your resources.
* Add functionality to unload a resource.
* Add support for another type of resource (e.g. audio or font) and use it in your game.
* (If you have an idea for another extension check with me before implementing it.)



### Part 4 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Helpful Resources

* [Tutorial 15: ResourceManager, TextureCache!](https://www.youtube.com/watch?v=HBpmfrQINlo)
* [Somewhat trustworthy discussion on map vs unordered map on stack overflow](https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys)
* [std::map series of tutorials](https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/)
* [A Resource Manager for Game Assets](https://www.gamedev.net/articles/programming/general-and-gameplay-programming/a-resource-manager-for-game-assets-r3807/)
* [Adding a Resource Management Class](http://eangogamedevelopment.blogspot.com/2017/01/part-21-completing-game-menu.html)



## Rubric

60/50/30: Part 1 all/most/any resource manager functionality implemented and used

15: Part 2 resource manager functions documented

15: Part 3 extension complete

10/8/3: all/most/any of part 4 meta answers complete

+5: for implementing a second extension

~~-X: general assignment guidelines~~
