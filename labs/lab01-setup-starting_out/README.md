# cs4850-setup

## Instructions

In this lab you'll set up the course development environment
and make a very basic SDL2 application.

You can find reference implementations of the completed lab in `ref/`.

Don't forget to put your name(s) in the `meta.txt` file!



### Part 0

Follow the instructions on the course website to set up your development environment.

Follow the instructions on the course website to accept the assignment and check out your code in Eclipse.



### Part 1

**Read all instructions before starting!**

In this part of the lab you'll follow the TwinklebearDev SDL 2.0 Tutorial here: https://www.willusher.io/pages/sdl2/.

The starter code for the assignment has done lesson 0. Read over the modifications and notes below and then follow **lessons 1 (and postscript 1), 2, 3, 4 and 6** (skip 5) from the tutorial to create a basic SDL application.

When following the tutorials, make these modifications:
* Don't add the `LessonX` subfolders (i.e. you can put the **source** for all the lessons in `src/main.cpp` and all the resources in `res/`).
* Use the header files from the tutorial, but use the extension `.hpp` for headers instead of `.h`.
* Keep the foreground, background, and text displaying as you go through the lessons.  When you are done, it should render the foreground, text, and tiled background all at once.
* When adding the loop in lesson 4, leave in the `SDL_Delay(1000);` after `SDL_RenderPresent` at the end of the loop so the window is responsive.
* Make a commit (with a *meaningful* commit message) when you are done with each lesson.

A few notes:
* For lessons 3 and 6 your system should already be set up with SDL2, and the Makefile is provided, so you shouldn't need to do that setup again.
* You don't need to use the `SDL2/` folder when including SDL2 headers (e.g. use `<SDL.h>` instead of `<SDL2/SDL.h>`)
* You can find the images and font from the linked GitHub repo from the tutorial page.
* If you are on macOS, the window may not show up until you have added the loop from lesson 4.



### Part 2

Choose and implement **at least one** of the following extensions (you can do more if you like):
* Use a program like GIMP or InkScape to make your own foreground (i.e. transparent) and background images.
* Animate the position and size of the foreground image while the window is open.
* Draw a pattern with the background tiles that is specified by a 2D array.
* Reorganize the code so that there are no functions implemented in header files.
* (If you have an idea for another extension check with me before implementing it.)



### Part 3

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented in part 2).



## Rubric

70/50/30: all/most/any of part 1 complete

20: Part 2 extension complete

10/8/3: all/most/any of part 3 answers complete

+5: for implementing a second extension in part 2

~~-X: general assignment guidelines~~
