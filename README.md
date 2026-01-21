# so_long

A small 2D game designed to help you work with textures, sprites, and basic gameplay elements using the MiniLibX graphical library.

---

### 💡 Key Features
* **Graphics Rendering:** Uses the MiniLibX library to manage windows, images, and real-time events.
* **Map Parsing:** Loads and validates `.ber` files, ensuring they are rectangular, enclosed by walls, and contain a valid path.
* **Event Handling:** Manages keyboard inputs (WASD/Arrows) and window events (X-button) to control the character and exit the game.
* **Gameplay Logic:** Tracks movement counts, collectible items, and ensures the player reaches the exit only after completing objectives.

---

### 🛠️ Compilation & Usage

The Makefile handles the compilation of the project along with the internal **Libft**. It also includes specific flags for OpenGL and AppKit (MacOS).

| Rule | Description |
| :--- | :--- |
| `make` | Compiles the `so_long` executable. |
| `make debug` | Compiles with AddressSanitizer and optimization disabled for debugging. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the `so_long` binary. |
| `make re` | Performs a clean re-compilation. |
| `make gotham` | Displays custom ASCII art in the terminal. |

**To run the game:**
Execute the program with a map file as an argument:
```bash
./so_long maps/map.ber
