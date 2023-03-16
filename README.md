# Card-Game
Tugas Besar 1 IF2210 2023 Pemrograman Berorientasi Objek
<br>
Kompetisi Kartu ala Kerajaan Permen

## Table of Contents
* [General Info](#general-information)
* [How To Run](#how-to-run)
* [Tech Stack](#tech-stack)
* [Project Structure](#project-structure)
* [Credits](#credits)

## General Information
Dalam rangka merayakan pesta panen gula di kerajaan permen, akan diadakan kompetisi massal permainan kartu ala Kerajaan Permen. Ratu kerajaan permen ingin mencari pemain kartu terhebat di kerajaannya. Namun karena Ratu tidak bisa memantau permainan satu-persatu, kalian diminta untuk membuatkan sistem agar permainan dapat berjalan dengan adil. Bantulah ratu kerajaan permen untuk membuatkan permainan ala kerajaan permen.

## How To Run
1. Running Using Batch File (For Windows)
- Di terminal `cmd`
```shell
./run.bat
```
- Double klik pada file `run.bat`
2. Running Using Shell Script (For Linux)
- Di terminal `cmd`
```shell
./run.sh
```
- Double klik pada file `run.sh`

## Tech Stack
### Programming Language
* C++ 6.3.0

## Project Structure
```bash
.
│   README.md
│   run.bat
│   run.sh
│   .gitignore
│
├───bin
│
├───doc
│
├───src
│   │
│   │   Combination
│   │        │
│   │        │   Combination.cpp
│   │        └───Combination.hpp
│   │
│   │   Comparator
│   │        │
│   │        │   Handler.cpp
│   │        │   Handler.cpp
│   │        │   Comparator.cpp
│   │        └───Combination.hpp
│   │
│   │   Deck
│   │    │
│   │    │   Deck.cpp
│   │    └───Deck.hpp
│   │
│   │   Exception
│   │        │
│   │        └───Exception.hpp
│   │
│   │   Game
│   │    │
│   │    │   Game.cpp
│   │    └───Game.hpp
│   │
│   │   GameState
│   │        │
│   │        │   GameState.cpp
│   │        └───GameState.hpp
│   │
│   │   player
│   │     │
│   │     │   player.cpp
│   │     │   player.cpp
│   │     │   playerAction.cpp
│   │     └───playerAction.hpp
│   │
│   │
│   └───main.cpp
│
└───test
      │
      │   card1.txt
      └───card2.txt
```

## Credits
This project is implemented by:
1. Wilson Tansil (13521054)
2. Bill Clinton (13521064)
3. Husnia Munzayana (13521077)
4. Jimly Firdaus (13521102)
5. Asyifa Nurul Syafira (13521125)
