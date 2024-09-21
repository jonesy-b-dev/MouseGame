# Technical Design Document (FDD)

## Technical information
* Language: C++
* Libraries: SFML
* Graphics API: OpenGl

## Engine
In the main.cpp we kickoff all the needed systems for the game, this includes:
* Engine class


## Notes
* Input class?
* Engine class
  * Manages all objects
  * Has start, update shutdown function where all the according functions are called from the objects. 
* Object class
    * Transform
    * HasCollision bool
    * Simple collision funciton 
    * Start()
    * Update()
    * ShutDown()
    * Player enemy and ui will inherit from object class
    * Objects are created and managed in the engine 
* Collision
* Player class : object
    * Hunger
    * Has collision
* Food class : object 
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