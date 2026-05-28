# MouseGame
SintLucas exam / BUAS intake assignment

A simple 2D game about collecting food as a mouse made in SFML 2.6.1. You slowly get hungry when not eating, you also need to bring food back to your family. There will be some enemies trying to attack you. you will lose the game when either you die or you or your family's hunger bar is completely drained. You can get score by collecting food. The more food you pickup the slower the player will move.

## About branches
main - most up do date default branch with all the work

exam - The state where the project was when finishing my exam

If any other branch exists its probably a developing branch testing some stuff


## How to run the project
### Winslop
* Clone repository
* Make sure to either have premake5 in your `$PATH` or have the `premake5.exe` executable in the root of the repository.
* Run premake5 for your desired editor e.g. `premake5 vs2022`
* Run like you are used to


### Linux
* Install build dependencies
```bash
sudo pacman -S base-devel cmake mesa libx11 libxrandr libxi libxcursor freetype2 libudev0 openal libflac libvorbis libogg
```
* Install premake

```bash
sudo pacman -S premake
```
* Run ./runGameGmake.sh

* On linux you can then run the `./runGameGmake.sh`. On windows just open in Visual Studio or your normal method.
Make sure to have OpenAL installed too.
