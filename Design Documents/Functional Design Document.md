# Functional Design Document (FDD)

## General description
A simple 2D game about collecting food as a mouse. You slowly get hungry when not eating, you also need to bring food back to your family. There will be some enemies trying to attack you. you will lose the game when either you die or you or your family's hunger bar is completely drained. You can get score by collecting food. The more food you pickup the slower the player will move.

## Technical information
* Language: C++
* Libraries: SFML
* Graphics API: OpenGl

## Functional requirements

### MoSCoW explanation
* [Mo] = Must have
* [S] = Should have
* [Co] = Could have
* [W] = Will not have

### Player
* [Mo] Player can move around using keybinds "WASD" 
* [Mo] Player can collect food by touching it.
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