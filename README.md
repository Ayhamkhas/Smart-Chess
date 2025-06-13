# ⚔️ Bitboard Chess Engine

A high-performance chess engine written in C++, built from scratch using bitboards, magic bitboards, and advanced search techniques. This project is part of my graduation thesis and is integrated with a mechanical CNC-driven chessboard via Arduino.

## ♟️ Features

### ✅ Core Engine
- **Bitboard Representation**: Efficient low-level representation of the board state.
- **Move Generation**: 
  - Magic bitboards for sliding pieces (bishops, rooks, queens)
  - Fast bitwise generation for knights, kings, and pawns

### 🔍 Search Algorithms
- **Negamax** with **alpha-beta pruning**
- **Quiescence Search** to reduce horizon effect
- **Move Ordering** using:
  - MVV-LVA (Most Valuable Victim - Least Valuable Attacker)
  - History heuristic
  - Killer moves

### 📐 Evaluation Function
- Material balance
- Piece-square tables
- Mobility, king safety, and other heuristics
- **Tuned using a Genetic Algorithm** (based on Kendall & Whitwell's approach)

### ♻️ Genetic Tuning
- Evolutionary approach to optimize evaluation weights
- Mini-games between individuals with deterministic best-move selection
- Selection based on fitness from win rates and performance

### 🎮 UCI Protocol Support
- Fully compliant with [UCI (Universal Chess Interface)](https://en.wikipedia.org/wiki/Universal_Chess_Interface)
- Compatible with GUI frontends like **Arena**, **CuteChess**, or **ChessBase**

### 🧪 Testing & Validation
- **Perft Testing** for move generator accuracy
- **FEN Loader** for position testing
- **Performance Benchmarks** and position-specific tests

### ♟️ Hardware Integration
- Arduino-based communication with a **mechanical XY CNC chessboard**
- Sends and receives moves in real-time
- Designed for human-machine interactive play

---

## 🛠 Build Instructions

### Requirements
- C++17 or later
- CMake 3.15+
- A modern compiler (GCC / Clang / MSVC)
- [Arduino IDE](https://www.arduino.cc/en/software) (for hardware connection)

