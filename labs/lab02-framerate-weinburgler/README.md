# cs4850-lab-framerate

## Instructions

In this lab you'll do some work on a main loop and the frame rate.

You can find reference implementations of the completed lab in `ref/`.

*This lab is adapted from one designed by [Michael D. Shah](http://www.mshah.io).*



### Part 1 - Implementation

Provided in the support code is a game loop with moving objects. The objects move at a fixed speed that the developers have thought to originally be good on their system.

There is one problem however. The game was developed on a very specific machine, that had a very specific clock rate. Depending on what hardware you are running on, the object will be moving at different speeds! This is an especially common problem for Desktop and mobile game development (It was less of a problem for old SNES games, where you knew the CPU frequency and that could be relied upon).

Your goal is to:
* Output the frames per second in a display on the screen. You should display an average framerate for the last 60 frames to three decimal places.
* Set the frames per second to a fixed rate rate of 60 FPS.  You can use any of the "styles" discussed in the reading for limiting frame rate.

Good luck!



### Part 2 - Extentions

Choose and implement **at least one** of the following extensions (you can do more if you like):
* Randomize the colors of the rectangles. Have different colors move at different speeds.
* Add a button the user can hold to speed up the rectangles, but not the framerate.
* Add a button the user can press to change the framerate, but have the rectangles keep moving at the same (real) speed.
* (If you have an idea for another extension check with me before implementing it.)



### Part 3 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Helpful Resources

You may find the following resources helpful:
* https://wiki.libsdl.org/SDL_GetTicks
* https://wiki.libsdl.org/SDL_Delay
* http://lazyfoo.net/tutorials/SDL/24_calculating_frame_rate/index.php
* http://lazyfoo.net/tutorials/SDL/25_capping_frame_rate/index.php



## Rubric

30: Part 1 frame rate display complete

40: Part 1 frame rate limit complete

20: Part 2 extension complete

10/8/3: all/most/any of part 3 answers complete

+5: for implementing a second extension

~~-X: general assignment guidelines~~
