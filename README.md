# WinAPI Graphics (C++)

Small experiments with raw Win32 GDI graphics — no frameworks, just `WndProc`, `WM_PAINT` and timers.

## Simple2DAnimation
A smiley face that moves across the window, redrawn every 50 ms via `SetTimer` / `WM_TIMER`
and drawn with GDI primitives (`Rectangle`, `Ellipse`).

## Build & run
Open `Simple2DAnimation/Simple2DAnimation.sln` in Visual Studio 2022 (Desktop development with C++) and press **F5**.
