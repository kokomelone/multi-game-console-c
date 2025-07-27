# Multi-Game Console: Snake and Ladder & Tic Tac Toe

This project merges two beloved games—**Tic Tac Toe** and **Snake and Ladder**—into a single C-based console application. It provides players with a nostalgic yet modern experience through interactive gameplay, AI logic, and game-saving capabilities.

## Objectives

- Develop a dual-game console application in C.
- Use structured programming, randomness, and file I/O.
- Provide a fun and challenging experience for all age groups.

## Features

### Snake and Ladder
- Dice-based movement with snakes and ladders.
- Up to 4 players.
- Game progress can be saved/loaded.
- Game winner and move counts are logged to file.

### Tic Tac Toe
- Player vs Player or Player vs Computer.
- AI component for basic computer moves.
- Auto-checks for win or draw.
- Coordinate-based interactive board.

## Technical Concepts

- **Structs**: Used for player data.
- **2D Arrays**: For Tic Tac Toe grid.
- **File Handling**: Save/load game and logs.
- **Recursion**: For re-prompting inputs.
- **Random Numbers**: Dice simulation.
- **Pointers**: File I/O.
- **Switch-Case**: Game selection.

## System Design

1. **Main Menu** – Select between games or exit.
2. **Game Logic** – Handled in individual modules.
3. **File Operations** – Save/load functions with log writing.

## Tools and Platform

- **Language**: C
- **Compiler**: GCC
- **Platform**: Console (Windows/Linux/Mac)

## Game Flow

- Select game from main menu
- Enter player details
- Play game with ongoing updates
- Save/load options
- Result logging and replay prompts
