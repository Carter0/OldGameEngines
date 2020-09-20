# cs4850-lab-math

## Instructions

In this lab you'll implement and test functionality for a small math library.

*This lab is adapted from one designed by [Michael D. Shah](http://www.mshah.io).*



### Part 1 - Code Questions

Look over the provided code in TinyMath.hpp.  Answer the related questions in questions.txt.



### Part 2 - Implementation

From the code repository, you will see the function prototypes for the library. Understanding the fundamentals of math is important for games, and the exercise of building a library will help you practice your C++. The good news is that one good math library really only needs to be written once (Unless math changes...in which case we have bigger problems!).
For this lab you have some flexibility if you want to add more functions or organize it in a different way. This is your personal math library.

Implement the functions in `TinyMath.hpp` (They should be marked "TODO"). If you would like, you may restructure the code.

The one requirement is that there are NO loops in your code.



### Part 3 - Testing

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working math library implementation.

We will use CxxTest for writing unit tests.  The Makefile is set up to use CxxTest but it is not in the repository yet.  If you try to build your project, you'll get a message that it can't find CxxTest.  Visit the [CxxTest website](http://cxxtest.com/), download CxxTest 4.4, and unpackage it into the extern/ folder.  If it's in the right place, building the project should make a `bin/test` executable (although running it will produce errors).  Add the cxxtest-4.4 folder to your repository.  Look over the CxxTest documentation.

Include at least 10 unit tests (i.e. member functions within `TinyMath.cxxtest.hpp`) to convince yourself the math works.



### Part 4 - Extensions

Choose and implement **at least one** of the following extensions (you can do more if you like):
* Implement at least four more functions you think may be of use!
* Implement and test Vector2D, Matrix4D, or Quaternion.
* Change all of your classes and structures into templates (e.g. instead of float). [C++ Templates Tutorial](http://www.cplusplus.com/doc/oldtutorial/templates/)
* Implement the functions with the AVX commands if you like. There are 5 heavily commented AVX samples to get you started, provided by [Michael D. Shah](http://www.mshah.io).
* (If you have an idea for another extension check with me before implementing it.)



### Part 5 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Helpful Resources

Some additional resources to help you through this lab assignment

- [Handy Course on Vector and Matrix Math](http://chortle.ccsu.edu/vectorlessons/vectorIndex.html#10)
- [Dot Product better explained](https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/)



## Rubric

15/12/7: Part 1 all/most/any questions answered

40/30/20: Part 2 all/most/any functions implemented

20/15/10: Part 3 all/most/any tests implemented

15: Part 4 extension complete

10/8/3: all/most/any of part 5 answers complete

+5: for implementing a second extension

~~-X: general assignment guidelines~~
