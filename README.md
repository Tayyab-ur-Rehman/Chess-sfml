# Chess‑SFML 🏁

A fully functional **Graphical Chess Game** developed in **C++** using the **SFML** (Simple and Fast Multimedia Library) for rendering, toward building intuitive, real‑time 2D gameplay, sound effects, and classic movement rules.

---

## 🎯 Project Vision

- **Build and explore the complete chess logic**—including legal move generation, turn-based flow, and game-end conditions like check and checkmate—through an accessible C++ structure.
- Leverage **SFML** for rendering sprites and handling user input, enabling smooth, multimedia-integrated gameplay :contentReference[oaicite:1]{index=1}.
- Provide a clean architecture based on `Board`, `Piece`, and `Player` classes for maintainable expansion.

---

## 🧩 Key Features

| Feature | Description |
|--------|-------------|
| **Board Logic & Gameplay** | Guides all chess rules: moves for Pawn, Knight, Bishop, Rook, Queen, King; en passant, castling not yet implemented. |
| **Rendering & Input** | Uses piece sprites (`*.png`) to draw the board and interactive clicking logic to select and execute moves. |
| **Sound & Notifications** | Plays move, notification, and checkmate sounds (e.g. `move.ogg`, `notify.ogg`, `cap.ogg`) and displays `checkmate.png` on win. |
| **Asset-based UI overlays** | Visual feedback for legal moves, selected cells, and turn highlights. |
| **Cross‑platform build** | Includes both `.sln`/Visual C++ files and plain C++ sources to support Windows, Linux, and macOS builds. |

---
