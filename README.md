# 🎮 C++ Game State Engine & Deserializer

## 📖 About the Project
This capstone project combines advanced Object-Oriented Programming principles with a custom persistent storage parser. It simulates a game engine's backend where a user can dynamically generate player profiles, execute polymorphic behaviors, and permanently save their state to the hard drive. 

A core feature of this architecture is the custom **deserialization engine**, which reads raw text data from the save file, parses it using delimiter logic, and strictly casts the strings back into their native primitive types (`int`, `float`) to fully restore the application's global state variables.

## ✨ Core Concepts & Architecture
*   **Abstract Base Contracts:** Utilizes a `GameEntity` abstract base class with pure virtual functions to enforce strict structural rules on all derived player and equipment classes.
*   **Run-Time Polymorphism:** Dynamically routes method calls through an array of base pointers to execute unique derived behaviors at runtime.
*   **Data Serialization (Write):** Leverages `ofstream` to seamlessly serialize the active game state (e.g., Player Name, Power Level, Weapon Damage) into a formatted physical text file.
*   **Data Deserialization (Read & Parse):** Leverages `ifstream` combined with string manipulation (`find()`, `substr()`) to extract raw data. Utilizes `stoi()` and `stof()` to cast text fragments back into actionable numerical data types.
*   **Interactive Menu System:** Implements a continuous `do-while` control loop with robust input buffer clearing (`cin.ignore()`) to safely handle dynamic user commands.

## ⚡ Complexity Analysis

### Time Complexity
*   **Serialization / File Writing:** `O(1)` - The program writes a fixed number of pre-determined state variables to the disk regardless of the player's level or weapon choice.
*   **Deserialization / File Reading:** `O(1)` - The parsing algorithm processes exactly 6 lines of data per load cycle. The `string::find()` and `string::substr()` operations run on strictly bounded string lengths (short names and numbers), resulting in constant time execution.
*   **Polymorphic Execution:** `O(N)` where `N` is the number of equipped entities. Since the loadout array is fixed at `size 2` (Player + Weapon), the operational time complexity strictly reduces to `O(1)`.

### Space Complexity
*   **Memory Allocation:** `O(1)` Auxiliary Space. 
*   **Explanation:** The application uses a fixed number of state variables (`name`, `weapon`, `power`, `rank`, `health`, `damage`) and a fixed-size pointer array (`GameEntity *game[2]`). Memory usage does not scale up; old objects are simply overwritten or reassigned when new states are loaded or created. No dynamic memory (`new` keyword) is left unmanaged.

## 💻 Tech Stack
*   **Language:** C++
*   **Libraries:** ``, ``, ``
