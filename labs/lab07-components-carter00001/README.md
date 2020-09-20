# cs4850-lab-components

## Instructions

In this lab you'll implement some basic game objects using the component pattern.

You are provided with a basic framework for making games using levels, game objects, and components, along with two simple games.  In both games the player navigates a level of blocks to collect a goal.

We'd like to add a little bit more functionality to the games using the existing framework.



### Part 1 - Reading and Update Documentation

Make the documentation and look over it to familiarize yourself with the various classes and their relationships. Add some documentation to each of the game-specific classes in `src/adventure/main-adventure.cpp` and `src/jump/main-jump.cpp` so that all of the classes have a brief description in the generated documentation.



### Part 2 - Adding Enemies

In each game (`src/adventure/main-adventure.cpp` and `src/jump/main-jump.cpp`), add a new class derived from `GameObject` for enemies.  An enemy should be rendered as a red square and should remove the player on a collision.  For this part the enemy should not move.



### Part 3 - Patrolling Enemies and Goals

Let's make things a little more challenging by making things move around.  Update the `src/base/PatrolComponent.*` so that it will cause its game object to move back and forth between the starting location and the provided location.

Make the enemies and goals in both games move around just by adding a `PatrolComponent` to them.



### Part 4 - Extensions (CS5850 only)

Choose and implement **at least one** of the following extensions (you can do more if you like):
- Update `PatrolComponent` to take a vector of locations to move along rather than a single location.
- Make both games greatly improved and more challenging by improving the level layout and adding multiple types of enemies.
- Add support for keys and doors and use them in both games.
- Make a new game with a different control scheme.
- Add some kind of game object and a number display component and use it to count the number of goals the player has collected.
- (If you have an idea for another extension check with me before implementing it.)



### Part 5 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Rubric

1 pt: Part 1 documentation added

3/2 pt: Part 2 all / some enemies added

4/3 pt: Part 3 all / some patrolling added

1 pt: Part 4 extension complete **(CS5850 only)**

2 pt: Part 5 meta answers complete

+0.5 pt: implementing one additional extension beyond requirements

~~-X: general assignment guidelines~~
