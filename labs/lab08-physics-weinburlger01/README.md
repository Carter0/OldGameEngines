# cs4850-lab-physics

## Instructions

In this lab you'll integrate a physics engine into an existing game framework.

You are provided with a basic framework for making games using levels, game objects, and components, along with two simple games.  In both games the player navigates a level of blocks to collect a goal.

We'll need to get a physics engine to use and fix up the physics in the games.



### Part 1 - Setup

First, look over some of the introductory documentation for [Box2D](https://box2d.org/), including the [Overview](https://box2d.org/documentation/index.html) and [Hello Box2D](https://box2d.org/documentation/md__d_1__git_hub_box2d_docs_hello.html).

Next, download [Box2D 3.2.1](https://github.com/erincatto/box2d) (from the GitHub Releases tab), and unpackage it into the `external` folder.  If it is in the right place there should be a file `extern/box2d-2.3.1/Box2D/Box2D/Box2D.h`.  This is where the Makefile will look for it. You do not need to run Box2D's build script. At this point it should be possible to build and run the games.  You should add the Box2D source to your repository.

Then, look over the code for the lab.  The most relevant classes for this lab are `PhysicsManager`, `PhysicsComponent`, and the `*InputComponent` for each game. The PhysicsManager handles the Box2D world.  The way it is set up, each PhysicsComponent creates a Box2D body for its GameObject.  It then stores a (raw) pointer to its GameObject in the body's user data.  This will allow other parts of the code to access the GameObject from a Box2D body.  Also, it's possible to call `shared_from_this()` using a raw GameObject pointer to get a shared GameObject pointer!



### Part 2 - Adding Fixtures

The games run, but there is no collision! The
PhysicsComponent makes a body but there is no fixture. Edit the
PhysicsComponent constructor to make an approriate FixtureDef (and
shape) and add it to the body.  Some of the properties of the fixture
will depend on the PhysicsComponent's type.

When this is working, it should be possible to move the players around
with the arrow keys and they collide with things.  No jumping in the jump game yet, though.



### Part 3 - Handling Collisions


Update `PhysicsManager::step()` so that after the physics step, the
collision handler is called on any pairs of objects that are
colliding.  Loop through all the collisions in the world and call
`collision` on the associated GameObjects.  Note that even if two
objects are in the collision list, you'll want to use `b2Collision::IsTouching`
to check they are touching.

When this is working, the goal should disappear when the player
collides with it (if the player can reach it).



### Part 4 - World Queries

At this point, the player in the jump game doesn't jump.  This is
because the player checks if it is on the ground before it can jump,
but the code to perform that check isn't implemented.  Update
`PhysicsManager::getCollisions(...)` to find objects in the given
rectangle.

To do this, you can use `b2World::QueryAABB`, for which you'll need to
implement a subclass of `b2QueryCallback` that can do something with
the fixtures that are found in its `ReportFixture` method.

This article on [Box2D World Querying](https://www.iforce2d.net/b2dtut/world-querying) is helpful.

When this is working the player in the jump game should be able to jump and collect the goal.



### Part 5 - Extensions (CS5850 only)

Choose and implement **at least one** of the following extensions (you can do more if you like):
- Add in enemies that remove the player on collision.
- Add in some other type of dynamic game object that the player can push around.
- Use constraints to make a more complex dynamic object.
- Use sensors to make some kind of event system (e.g. switches to open doors).
- Make a physics playground.
- (If you have an idea for another extension check with me before implementing it.)



### Part 6 - Meta

Fill out `meta.txt` with your answers to the questions about the assignment in the file (including the extension(s) you implemented).



## Rubric

1 pt: Part 1 Box2d added

2 pt: Part 2 Fixture added to body

2 pt: Part 3 Collision handling implemented

3 pt: Part 4 World query implemented

1 pt: Part 4 extension complete **(CS5850 only)**

2 pt: Part 5 meta answers complete

+0.5 pt: implementing one additional extension beyond requirements

~~-X: general assignment guidelines~~
