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
* HasCollision set to true
* float hunger (stores the current hunger value, game over when it reaches 0)
* float speed;
* int foodInventory (stores the amount of food items in the inventory)
The input of the player is managed here too. For the movement the Transform.position vector is edited. 
When the player collides with a food item the hunger value goes up by 10 is is capped at 100. 
The hunger value goes down by 1 every 3 seconds(might change if too slow or too fast), the time we calculate with the deltaTime from the time class. 
The speed is also affected by this, we use this formula to calculate the speed: `speed = defaultSpeed * (reductionValue)^foodItemAmount` for example: `speed = 100 * (0.95)^4` for when the player has 4 food items in his inventory

## Time class
The time class will store simple timing functionality. The time class will look something like [this](https://github.com/OuterCelestics/StellarEngine/blob/master/StellarEngine/source/engine/components/time/Time.cpp) (something I made for another project) 

## Food : object
Food will spawn randomly throughout the map with the SpawnFood() function. We call this function every random few seconds using a counter using the deltaTime and a random number (seconds) to call the function.

* double deltaTime (interval in seconds from the last frame to the current frame)
## Notes
* Food class : object 
  * Spawns randomly through the map, function that creates the objects randomly with random positions.
  * Random position when spawning
  * When player collides with food it despawns and refills hunger of the player
* Enemy class : object
  * Will spawn in the same way as food but outside of the game view and move into the screen
  * Will choose a random position in the game view to move towards
### Player
* [Mo] Player can move around using keybinds "WASD" // Input class?
* [Mo] Player can collect food by touching it. // 
* [Mo] Food will spawn randomly in the game view.
* [Mo] Player can eat with keybind "e" to replenish his own hunger with 25%.
* [Mo] Player has a house on the left of the screen which is where his family lives. Here he can stay safe from danger.
* [Mo] Player will lose if his hunger or health is 0.
* [Mo] When player returns food to the house family hunger will go up by 10%.
* [S] Player has hunger displayed in a ui element.
* [S] Player slows down by 10% for every food item he will pick up.
* [W] Player can attack enemies by clicking on them when in close range.

### Enemies
* [Mo] Enemies will slowly spawn in from the right, and a new enemy will spawn in every 20 seconds.
* [Mo] Enemies will roam around the play field.
* [S] When player gets within a certain range of an enemy it will attack the player.

### Audio
* [M] Audio when picking up food
* [S] Audio when bring back food
* [S] Audio when eating food
* [S] Audio when taking damage
* [Co] Audio when clicking on UI elements
* [W] Walking audio 
* [W] Background music

### Other
* [Mo] Family has same hunger system as the player.
* [S] You gain score from collecting food items.
* [Co] Score will be stored in a .txt file and shown in a UI.

### Extra (in case of time left over)
* [W] Main menu system with a start, highscore and quit button.

---

## Game visualisation
![GameLayout](GameLayout.png)

## Non-functional requirements
* Needs to have complete game loop
* Should not have lag spikes and run above 60fps all the time. 