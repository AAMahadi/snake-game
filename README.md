# 🐍 Snake Game

A classic Snake game built with **C** and **[Raylib](https://github.com/raysan5/raylib)**. Eat food, grow longer, avoid walls and yourself, and try to achieve the highest score! 🎮

## ✨ Features

- ✅ 🐍 Snake movement using keyboard controls
- ✅ 🎮 Directional movement with arrow keys and WASD
- ✅ 🍎 Food collection and snake growth
- ✅ 🏆 Score tracking
- ✅ 🧱 Wall collision detection
- ✅ 💥 Self-collision detection
- ✅ ☠️ Game-over screen
- ✅ 🔄 Restart functionality

## 🛠️ Technologies

- **C** — Game logic
- **Raylib** — Graphics, keyboard input, and window management
- **Make** — Build automation
- **Git & GitHub** — Version control

## 🎮 Controls

| Key | Action |
|---|---|
| ⬆️ / W | Move up |
| ⬇️ / S | Move down |
| ⬅️ / A | Move left |
| ➡️ / D | Move right |
| R | Restart after game over |
| ESC | Quit the game |

## 🚀 Getting Started

### 1. 📥 Clone the repository

Make sure Git is installed. Then run:

```bash
git clone --recurse-submodules https://github.com/AAMahadi/snake-game.git
cd snake-game
```

The `--recurse-submodules` option downloads the repository's configured Git submodules as well.

If you already cloned the repository without its submodules, run:

```bash
git submodule update --init --recursive
```

### 2. ⚙️ Install build dependencies

On Ubuntu or Debian-based Linux distributions, install the basic build tools and common Raylib dependencies:

```bash
sudo apt update
sudo apt install build-essential git libasound2-dev \
    libx11-dev libxrandr-dev libxi-dev libxinerama-dev \
    libxcursor-dev libgl1-mesa-dev
```

Depending on the Raylib version and build configuration, additional system dependencies may be required.

### 3. 🔨 Build and run

From the project root, run:

```bash
make
```

Then launch the generated executable using the name configured in your Makefile.

If your Makefile provides a `run` target, you can use:

```bash
make run
```

> 💡 **Note:** These commands assume your Makefile builds the game and links Raylib correctly. The Raylib submodule supplies source code; it does not automatically install system dependencies.

## 📁 Project Structure

```text
snake-game/
├── assets/       # Game assets
├── include/      # Header files
│   ├── food.h
│   └── snake.h
├── lib/          # Libraries
├── src/          # Source files
│   ├── food.c
│   ├── main.c
│   └── snake.c
├── .gitignore
├── .gitmodules   # Git submodule configuration
├── Makefile
└── README.md
```

## 👨‍💻 Author

**Abdullah Al Mahadi**

- 🐙 GitHub: [@AAMahadi](https://github.com/AAMahadi)
- 🎮 Project repository: [snake-game](https://github.com/AAMahadi/snake-game)

---

⭐ If you like the project, consider starring the repository!

*Built with C, Raylib, and a passion for learning by building.* 🐍
