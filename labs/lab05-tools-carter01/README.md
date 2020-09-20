# cs4850-lab-tools

## Instructions

In this lab you'll get some experience using memory debugging and performance profiling tools.

The code for this lab is an implementation of the [A* search
algorithm](https://www.redblobgames.com/pathfinding/a-star/introduction.html) from
http://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm/. Since
this is code that came from online, we may want to check how well it
is working and if there are any bugs.

Note that for some of the tools the Makefile will need to be udpated.



### Part 1 - Memory Debugging

Use one of the memory debugging tools from the course development page
to analyze the memory usage of the program. Put your answers in `questions.txt`.



### Part 2 - Performance Profiling

Use one of the performance profiling tools from the course development
page to get timing informaton about the program. Put your answers in
`questions.txt`.

Since the program runs so quickly, it may help to put a loop around
most of the functionality in the `main` function so that it takes more
time and you can get timing information from a longer run.  You may
also want to comment out the output so that doesn't impact the profile
as much!



### Part 3 - Extensions (CS5850 only)

Choose and implement **at least one** of the following extensions (you can do more if you like):
* Fix the memory errors you found in Part 1. (Hint: there is some discussion on the webpage the code came from.)
* Use a second memory debugger and compare the output. Which do you think is more useful?
* Use a second timing profiler and compare the output. Do you find similar things?
* Use a library like [easy_profiler](https://github.com/yse/easy_profiler) to get a more detailed report of timing.
* Use [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) or a similar tool to get code coverage information.
* (If you have an idea for another extension check with me before implementing it.)



### Part 4 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Rubric

4/3 pt: Part 1 all/some information from memory debugging tool

4/3 pt: Part 2 all/some information from performance profiling tool

1 pt: Part 3 extension complete **(CS5850 only)**

2 pt: Part 4 meta answers complete

+0.5 pt: implementing one additional extension beyond requirements

~~-X: general assignment guidelines~~
