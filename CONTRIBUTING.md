# Contributing to Wase Engine
This document will contain all the information for you to get started on contributing to Wase Engine.

[documentation]: https://wase-engine.com/documentation
[repo]: https://github.com/Wase-Engine/wase-engine
[issues]: https://github.com/Wase-Engine/wase-engine/issues
[new_issue]: https://github.com/Wase-Engine/wase-engine/issues/new/choose
[email]: info@wase-engine.com

## Issues
If you want to do a feature request or report a bug you can [create a new issue](https://github.com/Wase-Engine/wase-engine/issues/new) by selecting a template and filling this in with as much information as possible.

## Documentation
The documentation for Wase Engine is written in Markdown in the [wase-engine-docs repository](https://github.com/Wase-Engine/wase-engine-docs). The README.md of this repository contains the information you will need to start writing documentation. This repository has a production branch that will automatically deploy to the [Wase Engine website](https://wase-engine.com/).

## C++ style
```c++
// Use #pragma once instead of #ifndef
#pragma once

// First STL
#include <iostream>
#include <string>

// Second external libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Third Wase-Engine source code
#include <core/engine.h> // Use angle brackets

// Namespaces should always start with wase
// Use nested namespaces
namespace wase::folder::folder
{ // Braces are always put on the next line
    class Example
    {
    // Order access specifiers like the following:
    public:
        // Use lowerCamelCase for method names
        int getPlayerScore() const; // If possible mark by const
        void setPlayerScore(const int score); // If possible mark parameters by const
    protected:
    private:
        // Prefix static variables with s_ and start the name with a capital letter
        static int m_CombinedScores = 0;
      
        // Prefix member variables with m_ and start the name with a capital letter
        int m_PlayerScore = 0;
    };
}

// Use typename when using templates
template<typename T>

// Use UPPERCASE for enums
enum Priority
{
    LOW,
    NORMAL,
    HIGH
};
```
