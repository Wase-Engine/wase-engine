## Table of contents
1. [Introduction](#introduction)
2. [Building SDL Game Engine](#setup)
3. [Setting up the engine](#setup-engine)
4. [Scene management](#scene-management)
5. [Creating entities](#creating-entities)
6. [Working with components](#components)
7. [List of components](#components-list)
    - [Transform](#transform)
    - [SpriteRenderer](#spriterenderer)
    - [AudioSource](#audiosource)
9. [Logging](#logging)
10. [Contributing](#contributing)

### Introduction <a name="introduction"></a>
In this file you will find information about how you can build SDL Game Engine and how to use it. Everything will be demonstrated with a code example and you can always take a look at the [example game](https://github.com/JelleVos1/sdl-game-engine/tree/master/example-game)

### Building SDL Game Engine <a name="setup"></a>
To set up SDL Game Engine you will need to install the following items:
- C++17 or higher
- CMake
- SDL2
- SDL2 image
- SDL2 mixer

When you have all of them installed you can choose to build using the commandline or with the CMake gui.
You will first need to clone this repository or your own fork, after this you can decide if you want to use the CMake gui or run the following commands:
```
mkdir build
cd build
cmake ..
cmake build .
```

### Setting up the engine <a name="setup-engine"></a>
To run the engine you can simply call the run method on the Engine instance in the main function.<br>
`Engine::getInstance()->run("example");`

The run method takes 1 parameter, this is the name of the scene that will be used as start scene. For an explanation on how to add scenes you can go to the next [part](#scene-management) 

### Scene management <a name="scene-management"></a>
To create a scene you will need to create a class that extends from the Scene class.
```c++
class ExampleScene : public Scene
{
private:
    void start(); // Not required
    void update(float dt); // Not required
    void render(); // Not required
};
```
You can use the start, update and render methods from the Scene class. The start method will be run when it becomes the active scene. The update method will run once every frame and in the render method you can handle custom rendering.

When you have created your custom scene you can add it in the main function before the run method.
```c++
#include "engine.h"
#include "scene_manager.h"
#include "example_scene.h"

#include <memory>

int main()
{
    SceneManager::addScene("example", std::make_shared<ExampleScene>());
    Engine::getInstance()->run("example");
}
```
Now your engine is set up and your game is ready to be run.

### Creating entities <a name="creating-entities"></a>
To create an entity in your scene you can use the entity manager that is part of the Scene class.
```c++
#include "entity.h"
#include "entity_manager.h"

#include <memory>

void ExampleScene::start()
{
    Entity* exampleEntity = entityManager.addEntity("exampleEntity");
}
```
Every entity has a transform component by default.

### Working with components <a name="components"></a>
You can add and get components from entities. First you will have to [create an entity](#creating-entities) to work with. Every entity has a transform component by default. You can get components with the getComponent method.
```c++
exampleEntity->getComponent<Transform>()
```
To add other components you can use the addComponent method.
```c++
exampleEntity->addComponent<ComponentName>(componentArguments);
```
You can change the state on a component using the setActive method.
```c++
exampleEntity->getComponent<AudioSource>().setActive(false);
```

[Here](#components-list) you can find a list of all the available components.

### List of components <a name="components-list"></a>
- [Transform](#transform)
- [SpriteRenderer](#spriterenderer)
- [AudioSource](#audiosource)

#### Transform <a name="transform"></a>
The Transform handles the position of an entity.
|Properties||
|--|--|
| x | The x position |
| y | The y position |
| scaleX | The x scale |
| scaleY | The y scale |

#### SpriteRenderer <a name="spriterenderer"></a>
The SpriteRenderer handles the rendering of an entity. You can assign a sprite to the SpriteRenderer and then it will be drawn on the screen at the [Transform](#transform) position.

#### AudioSource <a name="audiosource"></a>
The AudioSource handles the audio of an entity. You can assign an audioclip to the AudioSource and then this can be played.
|Properties||
|--|--|
| playing | A boolean value to pause or unpause the audioclip |
| loop | A boolean value if the clip must loop or not |
<br>

|Methods| |
|--|--|
| play() | Play the audioclip |
| setVolume(float volume) | Adjust the volume in a range from 0 to 100 |

### Logging <a name="logging"></a>
To print messages to the console you can make use of the log utils.
There are 3 different kind of log types:
- info
- success
- error

You can use these by importing the log_utils header.
```c++
log_utils::info("This is an example.");
```

### Contributing <a name="contributing"></a>
If you would like to help us improve this file you can head over to [this](https://github.com/JelleVos1/sdl-game-engine/blob/master/CONTRIBUTING.md) page. 
