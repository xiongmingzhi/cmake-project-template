# CMake C++ Project Template

Thank you for your interest in this project!

Are you just starting with `CMake` or C++?

Do you need some easy-to-use starting point, but one that has the basic moving parts you are likely going to need on any medium sized project?


It is a minimal project that's kept deliberately very small. When you build it using CMake/make (see below) it generates:

 1. A tiny**cmake demo**
 2. using QT example
 3. using VTK example
 4. using spdlog
 5. using openGL
 
### Prerequisites

You will need:

 * A modern C/C++ compiler
 * CMake 2.8-3.8 installed (on a Mac, run `brew install cmake`)
 * If you prefer to code in a great IDE, I highly recommend [Jetbrains CLion](https://www.jetbrains.com/clion/). It is fully compatible with this project.


### Building in CLion

> **NOTE**: Since JetBrains software [does not officially support git submodules](https://youtrack.jetbrains.com/issue/IDEA-64024), you must run `git submodule init && git submodule update` before starting CLion on a freshly checked-out repo.

> **NOTE**: We recommend that you copy file `.idea/workspace.xml.example` into `.idea/workspace.xml` **before starting CLion**. It will provide a good starting point for your project's workspace.

Assuming you've done the above two steps, you can start CLion, and open the project's top level folder. CLion should automatically detect the top level `CMakeLists.txt` file and provide you with the full set of build targets.


### License

&copy; 2022-2029 xzy.

Open sourced under MIT license, the terms of which can be read here — [MIT License](http://opensource.org/licenses/MIT).

### Acknowledgements

This project is a derivative of the [CMake Tutorial](https://cmake.org/cmake-tutorial/), and is aimed at saving time for starting new projects in C++ that use CMake and GoogleTest.
