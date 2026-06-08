# The Library

A custom desktop library management system built with C++, SDL2, and SQLite. The project implements its own SDL-rendered interface for managing books, authors, and staff records in a local SQLite database.

## Features

- SDL2 desktop UI with custom buttons, text areas, and screen modes.
- SQLite-backed persistence.
- Book management: add, search, modify, and delete records.
- Author management: add, search, modify, and delete records.
- Staff management: add, search, modify, and delete records.
- Runtime database creation for `books.sqlite`.
- Existing database loading through a native file dialog.
- Separate C++ model classes for `book`, `author`, and `staff`.

## Data Model

The application creates and uses three SQLite tables:

| Table | Main fields |
| --- | --- |
| `books` | `id`, `name`, `author`, `pages`, `borrowed` |
| `authors` | `id`, `name`, `age`, `skin`, `books` |
| `staff` | `id`, `name`, `age`, `salary`, `pos` |

## Tech Stack

- C++
- SDL2
- SDL2_ttf
- SDL2_image
- SQLite3
- tinyfiledialogs

## Project Structure

```text
.
|-- main.cpp          # Application entry point and SDL event/render loop
|-- headers.h         # Models, database layer, SDL wrapper, and UI logic
|-- books.sqlite      # Local SQLite database used by the app
|-- books.sql         # SQL export / seed data for books
|-- authors.sql       # SQL export / seed data for authors
|-- staff.sql         # SQL export / seed data for staff
|-- font.ttf          # UI font
|-- output/           # Existing build artifacts
`-- .github/workflows # C/C++ workflow scaffold
```

## Build

Install dependencies on Ubuntu/Debian:

```bash
sudo apt install build-essential libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev \
  libsqlite3-dev
```

Compile from the repository root:

```bash
g++ main.cpp tinyfiledialogs.c -o library-manager \
  -lSDL2 -lSDL2_ttf -lSDL2_image -lsqlite3 -std=c++17
```

If your system provides tinyfiledialogs as a library instead of compiling `tinyfiledialogs.c` directly, adjust the command accordingly.

## Run

```bash
./library-manager
```

Run from the repository root so `font.ttf` and `books.sqlite` are found correctly.

## Application Modes

The main loop routes the UI through integer modes for each area of the system:

| Mode range | Purpose |
| --- | --- |
| `0` / main menu | Choose database or feature area. |
| `10-13` | Book add, delete, search, and modify screens. |
| `20-23` | Author add, delete, search, and modify screens. |
| `30-33` | Staff add, delete, search, and modify screens. |

## Implementation Notes

The project keeps most implementation in `headers.h`. That includes the model classes, SQLite helper methods, SDL initialization wrapper, and UI class. It is compact for experimentation and easy to inspect, but a future production version would benefit from splitting database, models, and UI into separate translation units.

## Known Limitations

- UI layout is fixed for a 1280x720 window.
- There is no authentication or role system.
- Input validation is basic.
- Database migrations are not versioned.
