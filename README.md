# GameEngine
My own game engine to make 2D games.
This engine made in C++ is using SDL2 for the window management and EnTT for the ECS part of the engine.

I created it to learn more about game engine and game development in general.
It has very likely many flaws in term of design or implementation, but it's a great way to learn !

# Build
To build this project, use the following commands :

```
mkdir build
cd build
cmake ..
sudo make install
```

# Structure
## Engine
Core engine, contains all the components needed to run the game.
## Editor
Editor used to create many things like:
- Animation Editor
- Map Editor
- And probably more to come...

# Usage
This engine is built as a shared library, you can use it by including "GEngine"

```
#include <GEngine>
```