# 📚 Library Management System

A desktop library management application built with C++, SDL2, and SQLite. Manage books, authors, and staff through a clean graphical interface.

## Features

- **Book Management** — Add, delete, search, and modify book records (title, author, page count, borrow status)
- **Author Management** — Track author profiles including age and published works
- **Staff Management** — Manage staff records with rank and salary information
- **Persistent Storage** — All data is stored in a local SQLite database
- **File Dialog Support** — Load an existing `.sqlite` database via a native file picker

## Tech Stack

| Component | Library |
|-----------|---------|
| GUI / Rendering | SDL2 |
| Font Rendering | SDL2_ttf |
| Database | SQLite3 |
| File Dialogs | tinyfiledialogs |
| Language | C++ |

## Dependencies

Make sure the following are installed on your system:

- [SDL2](https://www.libsdl.org/)
- [SDL2_ttf](https://wiki.libsdl.org/SDL2_ttf/FrontPage)
- [SQLite3](https://www.sqlite.org/)
- [tinyfiledialogs](https://sourceforge.net/projects/tinyfiledialogs/)

On Ubuntu/Debian:
```bash
sudo apt install libsdl2-dev libsdl2-ttf-dev libsqlite3-dev
```

## Building

```bash
g++ main.cpp -o library -lSDL2 -lSDL2_ttf -lsqlite3 -ltinyfiledialogs
```

Or with CMake if a `CMakeLists.txt` is present:
```bash
mkdir build && cd build
cmake ..
make
```

## Usage

Run the executable:
```bash
./library
```

On first launch, you'll be prompted to either create a new database (`books.sqlite`) or load an existing one via the file dialog.

### Navigation

The app is keyboard and mouse driven. Use the main menu to navigate between sections, and press **Escape** at any time to go back to the main menu.

| Mode | Section |
|------|---------|
| 0 | Main Menu |
| 10 | Add Book |
| 11 | Delete Book |
| 12 | Search Book |
| 13 | Modify Book |
| 20 | Add Author |
| 21 | Delete Author |
| 22 | Search Author |
| 23 | Modify Author |
| 30 | Add Staff |
| 31 | Delete Staff |
| 32 | Search Staff |
| 33 | Modify Staff |

## Project Structure

```
.
├── main.cpp        # Entry point, SDL event loop
├── headers.h       # All classes and logic (book, author, staff, database, UI)
└── books.sqlite    # Auto-generated database file (created on first run)
```

## Database Schema

**books** — `id, name, author, pages, borrowed`

**authors** — `id, name, age, skin, books`

**staff** — `id, name, age, salary, pos`

## License

This project is unlicensed — do whatever you want with it.
