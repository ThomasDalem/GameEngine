# GameEngine
My own game engine to make 2D games
This engine made in C++ is using SDL2 for the window management and EnTT for the ECS part of the engine.

# Build
To build this project, use the following commands

```
mkdir build
cd build
cmake ..
sudo make install
```

# Usage
This engine is built as a shared library, you can use it by including "GEngine"

```
#include <GEngine>
```