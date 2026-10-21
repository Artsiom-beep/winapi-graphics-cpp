# 🙂 WinAPI Smiley Animation (C++)

Small experiments with raw Win32 GDI graphics — no frameworks, just `WndProc`, `WM_PAINT` and timers.

## Simple2DAnimation
A smiley face that grows in the centre of the window until it reaches its maximum size.
It is redrawn every 50 ms via `SetTimer` / `WM_TIMER` and drawn with GDI primitives (`Ellipse`, `Arc`).

## Build & run
Open `Simple2DAnimation/Simple2DAnimation.sln` in Visual Studio 2022 (Desktop development with C++) and press **F5**.
