
# Table of contents
1. [Introduction](#introduction)
2. [Building SDL Game Engine](#setup)
3. [Setting up the engine](#setup-engine)
4. [Scene management](#scene-management)
5. [Creating entities](#creating-entities)
6. [Loading resources](#loading-resources)
7. [Working with components](#components)
8. [List of components](#components-list)
    - [Transform](#transform)
    - [SpriteRenderer](#spriterenderer)
    - [AudioSource](#audiosource)
9. [Logging](#logging)
10. [Contributing](#contributing)

## Introduction <a name="introduction"></a>
In this file you will find information about how you can build SDL Game Engine and how to use it. Everything will be demonstrated with a code example and you can always take a look at the [example game](https://github.com/JelleVos1/sdl-game-engine/tree/master/example-game)

## Building SDL Game Engine <a name="setup"></a>
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

## Setting up the engine <a name="setup-engine"></a>
To run the engine you can simply call the run method on the Engine instance in the main function.<br>
`Engine::getInstance()->run("example");`

The run method takes 1 parameter, this is the name of the scene that will be used as start scene. For an explanation on how to add scenes you can go to the next [part](#scene-management) 

## Scene management <a name="scene-management"></a>
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

int main(int argc, char* argv[])
{
    // Initialize SDL
    Engine::getInstance()->init();

    // Load scenes
    SceneManager::addScene("example", std::make_shared<ExampleScene>());
    
    // Run the game
    Engine::getInstance()->run("example");

    return 0;
}
```
Now your engine is set up and your game is ready to be run.

## Creating entities <a name="creating-entities"></a>
To create an entity in your scene you can use the entity manager that is part of the Scene class.
```c++
#include "entity.h"
#include "entity_manager.h"

void ExampleScene::start()
{
    Entity* exampleEntity = entityManager.addEntity("exampleEntity");
}
```
Every entity has a transform component by default.

## Loading resources <a name="loading-resources"></a>
The ResourceManager keeps track of all the resources. Before you can use a resource you'll first have to load it in. This can be done with the following code:
```c++
#include "engine.h"

#include "scene_manager.h"
#include "resource_manager.h"
#include "example_scene.h"

#include <memory>

int main(int argc, char* argv[])
{
    // Initialize SDL
    Engine::getInstance()->init();

    // Load resources
    ResourceManager::loadTexture("cube", "cube.png");
    ResourceManager::loadAudio("hop", "hop.wav");

    // Load scenes
    SceneManager::addScene("example", std::make_shared<ExampleScene>());

    // Run the game
    Engine::getInstance()->run("example");

    return 0;
}
```

Now that you have loaded in some resources you can access them from everywhere with the get methods.

|Methods| returns | description |
|--|--|--|
| getTexture(string name) | SDL_Texture* | Get a texture by name |
| getAudio(string name)   | Mix_Chunk* | Get an audio by name |
| loadTexture(string name, char* path) | void | Load in a texture from a file (png, jpg, etc.) |
| loadAudio(string name, char* path)   | void | Load in an audio from a file (mp4, wav, etc.) |

## Working with components <a name="components"></a>
You can add and get components from entities. First you will have to [create an entity](#creating-entities) to work with. Every entity has a transform component by default. You can get components with the getComponent method.
```c++
exampleEntity->getComponent<ComponentName>()
```
To add other components you can use the addComponent method.
```c++
exampleEntity->addComponent<ComponentName>(componentArguments);
```
You can change the state on a component using the setActive method.
```c++
exampleEntity->getComponent<ComponentName>().setActive(false);
```

[Here](#components-list) you can find a list of all the available components.

## List of components <a name="components-list"></a>
- [Transform](#transform)
- [SpriteRenderer](#spriterenderer)
- [AudioSource](#audiosource)
- [BoxCollider2D](#boxcollider2d)

### Transform <a name="transform"></a>
The Transform handles the position of an entity.

| Constructor argument | default | description |
|--|--|--|
| x | 0 | The x position |
| y | 0 | The y position |
| scaleX | 1 | The x scale |
| scaleY | 1 | The y scale |
| depth | 0 | The depth of the entity. This can be used to decide the render order of the SpriteRenderer. |
<br>

|Properties||
|--|--|
| x | The x position |
| y | The y position |
| scaleX | The x scale |
| scaleY | The y scale |
| depth | The depth of the entity. This can be used to decide the render order of the SpriteRenderer. |
<br>

### SpriteRenderer <a name="spriterenderer"></a>
The SpriteRenderer handles the rendering of an entity. You can assign a sprite to the SpriteRenderer and then it will be drawn on the screen at the [Transform](#transform) position.

| Constructor argument | default | description |
|--|--|--|
| name |  | The name of the texture resource in the ResourceManager |
| sizeX |  | The x scale of the texture |
| sizeY |  | The y scale of the texture |
<br>

### AudioSource <a name="audiosource"></a>
The AudioSource handles the audio of an entity. You can assign an audioclip to the AudioSource and then this can be played.

| Constructor argument | default | description |
|--|--|--|
| name |  | The name of the audio resource in the ResourceManager |
| volume | 100 | The volume in a range from 0 to 100  |
| loop | false | A boolean value if the clip must loop or not |
| playOnAwake | false | a boolean value if the clip must play on awake or not |
<br>

| Properties | description |
|--|--|
| playing | A boolean value to pause or unpause the audioclip |
| loop | A boolean value if the clip must loop or not |
<br>

|Methods| returns | description |
|--|--|--|
| play() | void | Play the audioclip |
| setVolume(float volume) | void | Adjust the volume in a range from 0 to 100 |
<br>

### BoxCollider2D <a name="boxcollider2d"></a>
Registers a collision area as a rectangle.

| Constructor argument | default | description |
|--|--|--|
| width|  | The width of the collision rectangle |
| height | | The height of the collision rectangle  |
<br>

| Properties | description |
|--|--|
| width | The width of the collision rectangle |
| height | The height of the collision rectangle |
| offsetX | The x position offset of the collision area |
| offsetY | The y position offset of the collision area |
| showCollider | If true it shows a green rectangle outline representing the BoxCollider2d |
<br>

## Logging <a name="logging"></a>
To print messages to the console you can make use of the log utils.
There are 3 different kind of log types:
- info
- success
- error

You can use these by importing the log_utils header.
```c++
log_utils::info("This is an example.");
```

## Contributing <a name="contributing"></a>
If you would like to help us improve this file you can head over to [this](https://github.com/JelleVos1/sdl-game-engine/blob/master/CONTRIBUTING.md) page. 
