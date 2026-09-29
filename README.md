# 🎮 C++ Persistent Game Loadout Engine

## 📖 About the Project
This capstone project combines advanced Object-Oriented Programming principles with persistent memory management. It simulates a game engine's backend where a user can dynamically generate player profiles and equipment loadouts, execute polymorphic behaviors, and permanently save their state to the hard drive. 

## ✨ Features
*   **Abstract Base Contracts:** Utilizes a `GameEntity` abstract base class with pure virtual functions to enforce strict structural rules on all derived player and equipment classes.
*   **Run-Time Polymorphism:** Dynamically routes method calls through an array of base pointers to execute unique derived behaviors at runtime.
*   **State Persistence (File I/O):** Leverages `ofstream` and `ifstream` to seamlessly serialize the active game state to a physical text file and deserialize it back into the terminal session.
*   **Interactive Menu System:** Implements a continuous `do-while` control loop with robust input buffer clearing (`cin.ignore()`) to handle dynamic user commands.

## 💻 Tech Stack
*   **Language:** C++
*   **Core Concepts:** Run-Time Polymorphism, Abstract Base Classes, File Streams (`fstream`), Memory Scope Management.
