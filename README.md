# 2D Sandbox Engine

A small 2D sandbox game engine written in **C++ and OpenGL**.

This project started as a way to learn and better understand low-level game development, graphics programming, and game architecture without relying on a high-level game engine.

The goal is not to build a production-ready engine from the beginning, but to gradually develop the project while learning what works, what doesn't, and why.

## Current Features

* OpenGL rendering
* GLFW window and input handling
* GLAD OpenGL loader
* Basic shader system
* Texture loading
* 2D rendering
* Basic game loop
* Modular project structure

## Planned Features

The engine is being developed incrementally. Planned systems include:

* [ ] Chunk-based world management
* [ ] Player movement and physics
* [ ] Collision system
* [ ] World generation
* [ ] Block interaction
* [ ] Entity system
* [ ] Lighting
* [ ] Save/load system
* [ ] Improved rendering and batching
* [ ] Audio
* [ ] Debug/development tools

The structure will evolve as the project grows. Some systems may be refactored or replaced when the current implementation becomes a limitation.

## Why?

I wanted a project where I could learn game development by actually building the underlying systems instead of immediately relying on an existing game engine.

This project is also an experiment in finding a reasonable balance between:

* object-oriented design
* low-level rendering
* performance
* modularity
* maintainability

Not every part of the code is expected to be optimal. Some systems are intentionally kept simple until the project reaches a point where their limitations become apparent.

## Development Philosophy

> Build it first. Understand it. Improve it when necessary.

Instead of trying to design the entire engine perfectly beforehand, the project is developed iteratively.

When a system eventually becomes a bottleneck or makes further development difficult, it will be redesigned based on what was learned from the existing implementation.

This means the codebase will probably change significantly over time.

## Technologies

* **C++**
* **OpenGL**
* **GLFW**
* **GLAD**
* **GLSL**

## Status

🚧 **In active development**

This is primarily a learning and portfolio project. The architecture, rendering systems, and APIs are expected to change as development progresses.
