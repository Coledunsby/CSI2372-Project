CSI2372 Project (Fall 2014)
===============

Final Project for CSI2372 - Advanced Programming Concepts with C++

In this project, you are asked to program a game that is played on a game board (a grid of squares). The players take turns. At each turn, the players will have the opportunity to move their player on the board from the current square to adjacent squares. A square has a maximum of four neighbours (up, down, left, right). When a player arrives on a square, the player has the ability to perform an action. Different squares allow different actions involving trading goods. The goal of the game is to acquire rubies.

The game is inspired by Oliver Dorn’s Istanbul.


Instructions to compile and run:
--------------------------------
```
g++ main.cpp tile.cpp player.cpp tilefactory.cpp -o a.out
./a.out
```
