# cs4850-project

Framerate + Main Loop => Jake Dec
* Set the loop similar to the lab.
* Declare & initialize a renderer gameobjects can access.
* Do the event stuff.
* Do the framerate.
* Make abstract gameobject class.
	
Brick 				  => Red Wyant
* Position the bricks & render them.
* Making the collider.
* Making the getPosition method. Deallocate them upon collision. Returns a boolean.
* Implement parent class.

Player/Paddle 		  => Carter Kleinberg

Balls + Death => Nicolas Karayakaylar
* Implements parent class.
* Bounce method. ~Vector Math.
* Render method.
* Update.
* Collider.

The abstract GameObject class contains...
* Update();
* Render();
* position();
* getPosition();

The Paddle/Player
* Render + Update + getPosition
* Move left + move right
* Also deal w/score
* The 3 lives.