# x86 `src/bsd/dev/i386/VGAConsole.c` (plan 338 (S5-P328), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 338 (S5-P328). Final run `s5p338-it1`; 07 file SHA-256 `a2e9da563683e633b01539845eca1f887406a89553bf624b3ce717870899e7cb`; diff `x86-VGAConsole.diff`.

- Object [0x197ca0, 0x19ba15) 15733 B, 16 functions ((static FlipCursor), (static BltChar), (static FBPutC), (static SetTitle), (static InitWindow), (static Init), (static Restore), (static vga_write_bpp2packd32_to_bpp4planar), (static DrawRect), __VGAAllocateConsole, _SVGAAllocateConsole, _VGAAllocateConsole, (static Free), (static EraseRect), (static PutC), (static GetSize)). Front `89 ec 5d c3`, back `00 00 00 55`, next object FBConsole 0x19ba18 after 00 x 3 (plan 379 correction; the next original symbol is 0x19ec24).
- Final L1 `09_validation/reconstruction/s5p338-it1-l1-VGAConsole-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred. Grade **P**.

Object extent [0x197ca0, 0x19ba15) 15733 B (no fill before, after BasicConsole; 00 x 3 after): 16 functions (statics FlipCursor .. DrawRect, _VGAAllocateConsole, SVGAAllocateConsole, VGAAllocateConsole, statics Free, EraseRect, PutC, GetSize); __data [0x1e41fc, 0x1e4703) 1287 B verified (begins with the 1152-byte ohlfs12 font). Diagnostics s5p339-a1 .. c1. Codex review of plan 338 (gpt-6.1-sol) verified (one statement corrected). s5p338-it1 from 07: __text 0 differences (6 MATCH + 10 MATCH_UNVERIFIED for the __bss references), relcheck 0.
