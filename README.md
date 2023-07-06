# Table of Contents
* [General Information](#general-information)
* [Assets and the Font](#assets-and-the-font)
* [Technologies](#technologies)
* [Windows Installation](#windows)
* [Linux Installation](#linux)
* [Features](#features)
* [Inspiration and Help](#inspiration-and-help)

## General Information
This application is a simple clone of the popular Snake game written in C++ with the SFML 2.5.1 library, distributed under the [zlib/libpng License](https://opensource.org/licenses/zlib-license-php/). I made it in order to learn C++ and grasp some OOP concepts. One of my goals was to make this program as portable as possible and standalone.

## Assets and the Font
The application uses a tileset made of assets created by [Clear Code](https://www.youtube.com/@ClearCode) and distributed under the [Public Domain](https://creativecommons.org/publicdomain/zero/1.0/). It also uses the Alice font created by Ksenia Erulevich and distributed under the [SIL Open Font License, Version 1.1](http://scripts.sil.org/OFL).

The files of the assets are in the resources directory; however, they are not required to compile the program since they are already included in the source files as byte arrays. The program does not require any external files to run. It is fully standalone.

## Technologies
- Microsoft Visual Studio Community 2022 17.3.3 with Microsoft Visual C++ 2022 compiler for Windows 10 Professional
- g++ (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4) compiler for Fedora release 36
- SFML 2.5.1 library

## Installation
### Windows
1. Download the [SFML library](https://www.sfml-dev.org/download/sfml/2.6.0/).
2. Unzip the archive to a directory (e.g., C:\libs\SFML-2.5.1).
3. Create a new empty project in VS Community.
4. Press Alt+F7 and go to Configuration Properties -> C/C++ -> General and provide the path to your include directory.

![image](https://github.com/WikSta/Snake/assets/138527487/b9cb252c-8639-4e14-a849-0b6bafce4afb)

5. Go to Configuration Properties -> Linker -> General and provide the path to your lib directory.

![image](https://github.com/WikSta/Snake/assets/138527487/ffd82a27-1095-4b4e-b4b7-272ea848efa9)

6. Go to Configuration Properties -> Linker -> Input and add additional dependencies. These are required in order to create the standalone executable file. Dependencies to copy: `opengl32.lib
freetype.lib
winmm.lib
gdi32.lib
sfml-graphics-s.lib
sfml-window-s.lib
sfml-system-s.lib
sfml-main.lib`


![image](https://github.com/WikSta/Snake/assets/138527487/94df22dc-ac21-4ff8-94df-450d3036329a)

7. Go to Configuration Properties -> C/C++ -> Preprocessor and add `SFML-STATIC` to its definitions.
  
![image](https://github.com/WikSta/Snake/assets/138527487/2c89a492-1b69-4069-91bd-2ad12190d01f)

8. Make sure that you have selected the matching configuration in the IDE.

![image](https://github.com/WikSta/Snake/assets/138527487/c9d5e240-0b89-4e29-a348-a9420dcc1db8)

9. Now go to your project's directory and paste all the headers from the include directory and all the source files from the src directory. They must share the same directory.

![image](https://github.com/WikSta/Snake/assets/138527487/e2537340-b17c-4708-b9dc-9fdb443262db)

10. Go back to VS and press Ctrl+Alt+F7 to compile it. Then press Ctrl+F5 to run the executable.

A more detailed tutorial can be found [here](https://www.sfml-dev.org/tutorials/2.6/start-vc.php).

### Linux
`<username>` is your user name
1. Download the [SFML library](https://www.sfml-dev.org/download/sfml/2.6.0/).
2. Extract the arcive to the directory where you want to store SFML libraries (e.g., `/home/<username>/Documents/Source/libs`)
`sudo tar -xvzf /home/<username>/Downloads/SFML-2.6.0-linux-gcc-64-bit.tar.gz -C /home/<username>/Documents/Source/libs`
3. Go to the directory where you want to store your source files. Paste all the headers from the include directory and all the source files from the src directory into this directory. They must share the same directory (e.g., `/home/<username>/Documents/Source/Snake-SFML`).
4. Download and install the G++ compiler from the repository. If you already have the compiler installed, you can skip this step. Use the following command for Fedora:
`sudo dnf install g++`
5. Go to the directory where you pasted the source files. In our example, use the following command:
`/home/<username>/Documents/Source/Snake-SFML`
6. Compile the files using the following command. Specify the path to the include and lib directories and link the necessary libraries:
`g++ *.cpp -I/home/<username>/Documents/Source/libs/SFML-2.6.0/include -L/home/<username>/Documents/Source/libs/SFML-2.6.0/lib -lsfml-window -lsfml-graphics -lsfml-system`
7. Since we did not install the library in the standard path, we need to set the dynamic linker path to the SFML libraries. In our case, use the following command:
`export LD_LIBRARY_PATH=/home/<username>/Documents/Source/libs/SFML-2.6.0/lib && ./a.out`


## Features
The game is simple. After running the file, you will see instructions.

![image](https://github.com/WikSta/Snake/assets/138527487/82c62bfe-6a3e-4c3a-955a-519e968846c8)

After pressing any button, you can start playing. You control the snake with arrow keys. Space is used to pause the game. The goal is to eat as many fruits as possible. You lose if the head hits the snake's body or any edge of the map. The score in the upper left corner shows how many fruits you ate during the game.

![image](https://github.com/WikSta/Snake/assets/138527487/1ecfb2f9-d125-418c-996b-5ce0f4e0cf01)

You can always use the spacebar to pause the game.

![image](https://github.com/WikSta/Snake/assets/138527487/4026fd3e-ca11-44a4-9aba-f9bbd58fc1c2)

After collecting all possible fruits or losing, you will see this information. Press any button to terminate the program. If you want to play again, you have to run the executable again.

![image](https://github.com/WikSta/Snake/assets/138527487/1d220b6a-ff0c-4f6d-bc6c-abaae4bd96a5)

## Inspiration and Help
- "C++ Primer Plus" - Prata Stephen. It helped a lot with learning C++.
- [SFML Tutorials](https://www.sfml-dev.org/tutorials/2.6/). The official tutorials helped me with the tile map.
- [GeeksforGeeks](https://www.geeksforgeeks.org/design-snake-game/). This article helped me with class design.
