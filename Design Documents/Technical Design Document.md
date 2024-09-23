# Technical Design Document (FDD)

## Technical information
* Language: C++
* Libraries: SFML
* Graphics API: OpenGl

## Engine
In the `main.cpp` we kickoff all the needed systems like the engine class.

Everything in this project will be based on objects. 
The engine will store a `std::vector` of all the object in the game. In the start update and shutdown functions we will loop over all the objects in the game and call the according function of the object.
The engine will also include the broiler plate SFML code, like the main while loop.

## Object class
An object in the engine will be the base of every other object in the game like audio player, enemies UI and audio. 
The object class is defined in `object.hpp` and implemented in `object.cpp`. 

The object class will have the following properties:
* Transform transform;
* sf::Sprite sprite;
* Start();
* Update();
* Shutdown();
* HasCollision bool (Would be false for ui/audio)
* Collision functionality

The Transform is a custom struct we implement with the following properties:
* Vector2 position;
* float rotation;
* Vector3 scale;

The Vector2 is also a custom struct we implement with the following properties:
* float x;
* float y;

## Player : object
The player is class inherited from the object class. The player class will have the following properties:
* Everything the object class has
* bool isSafe (will be true when player is inside the range of the house, enemies cant attack there)
* HasCollision set to true
* float hunger (stores the current hunger value, game over when it reaches 0)
* float speed;
* float health; (When player is hit by enemy this variable gets reduced)
* int foodInventory (stores the amount of food items in the inventory)
* TakeDamage(float damage)
* Death() (when this is called the game is over)
* HandleInput() (here all the input and movement is handelded)
* Eat() (when the keybind 'e' is pressed 1 food item wil be removed from the foodInverntory and hunger allue will be increased by 10 (max 100))

The input of the player is managed here too. For the movement the Transform.position vector is edited. 
When the player collides with a food item the hunger value goes up by 10 is is capped at 100. 
The hunger value goes down by 1 every 3 seconds(might change if too slow or too fast), the time we calculate with the deltaTime from the time class. 
The speed is also affected by this, we use this formula to calculate the speed: `speed = defaultSpeed * (reductionValue)^foodItemAmount` for example: `speed = 100 * (0.95)^4` for when the player has 4 food items in his inventory.
For every food you bring back the score varible in the ui score object will go up by 1.

When colliding with an enemy it will take damage.

## Time class
The time class will store simple timing functionality. The time class will look something like [this](https://github.com/OuterCelestics/StellarEngine/blob/master/StellarEngine/source/engine/components/time/Time.cpp) (something I made for another project) 

## Food : object
Food will spawn randomly throughout the map with the SpawnFood() function. We call this function every random few seconds using a counter using the deltaTime and a random number (seconds) to call the function. It will have an randomized position.

Properties:
* double deltaTime (interval in seconds from the last frame to the current frame)

## Enemy : object
Enemies will spawn in the same way as food but outside of the game view and move into the screen to a random position in the game view using the `FindNewPosition()` and `MoveToPostition`.
When the enemy gets within a certain range of the player it will move towards the player. When that happens it will simple take the players position for his next move. When the enemy touches the player it will call it's `TakeDamage(damage)` function.
When the enemy is clicked by the pointer device it will take damage and after 5 clicks the enemy will die. 

Properties:
* int health
* FindNewPosition()
* MoveToPosition
* TakeDamage(int damage)

## House : object 
The house is places on the left side of the screen and has a diffrent kind of collision and acts more as a trigger, when the player enters the house all food items will be removed and for every food item delivered the house hunger goes up by 5%. When the house hunger reaches 0 we call the Death funciton in the player(The same happens when the player days so we can use this funciton)
Properties:
* float hunger;

## UI : object
All ui is implemented as an object and is just a sprite rendered after everything of the game is rendered. Has no collision. The UI objects are stored in another vector of objects but works the same as the normal objects but is looped over after the normak game objects.

## Audio
Audio is implemented right in the object where it needs to be played. No special class needed for this.