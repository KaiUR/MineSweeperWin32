# MineSweeperWin32

A lightweight, high-performance Minesweeper game built using the **Native Win32 API** and **C**. 

## 🎯 Motivation & Project Goals

This project was created as a personal challenge to dive deep into the **Windows API (Win32)**. Unlike modern frameworks that abstract the OS away, this project interact directly with the Windows kernel and GDI (Graphics Device Interface) to understand:

*   **Manual Resource Management**: Handling `.rc` files, icons, and bitmaps without an engine.
*   **The Windows Message Loop**: Learning how `GetMessage`, `TranslateMessage`, and `DispatchMessage` power every desktop application.
*   **Dialog & Menu Construction**: Building UI from scratch using `DIALOGEX` and `MENU` resources.
*   **Pure C Development**: Keeping the codebase lean, fast, and free of heavy external dependencies.

Most importantly, this was built **for fun**—to see how much logic can be packed into a tiny, native Windows executable!

## 🎮 How to Play

The objective of the game is to reveal all the safe spaces without hitting a mine.

*   **Left Click**: Reveal a square. If it's a mine, the game ends! If it's a number, it tells you how many mines are in the 8 surrounding squares.
*   **Right Click**: Place or remove a **Flag** 🚩. Use flags to mark squares where you are certain a mine is hidden.
*   **Winning**: You win when all non-mine squares are revealed, or all mines are correctly flagged.
*   **Safe Start**: The first move is programmed to never be a mine (unless you are playing a "Replay").

## 🚀 Features

*   **Classic Difficulties**: Easy, Normal, and Hard presets.
*   **Custom Game Mode**: Set your own grid size and mine density via a specialized `DIALOGEX`.
*   **Native UI**: Hand-crafted resource scripts (`.rc`) for menus, icons, and dialogs.
*   **Dynamic Metadata**: Automated build numbering and build-date tracking embedded in the executable's properties.

## 🛠️ Built With

*   **Language**: C (C11)
*   **API**: Win32 API (User32, GDI32)
*   **Build System**: CMake (3.16+)
*   **Compiler**: MinGW-w64 / GCC

## 📦 Building from Source

1.  **Clone the repository**:
    ```bash
    git clone https://github.com
    cd MineSweeperWin32
    ```

2.  **Configure and Build**:
    ```bash
    mkdir build
    cd build
    cmake -G "Ninja" ..
    ninja
    ```

## 🔢 Versioning System

This project uses a custom CMake-driven versioning system:
*   **Auto-Increment**: Every time CMake is configured, the `build_number.txt` increments.
*   **Header Generation**: CMake generates `version.h` from `version.h.in`, injecting the current version, build number, and build date into the binary's `VERSIONINFO` resource.

## 📄 License

This project is licensed under the **MIT License**.

Copyright (c) 2024 Kai-Uwe Rathjen

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

---
**Author**: [Kai-Uwe Rathjen](https://github.com)
