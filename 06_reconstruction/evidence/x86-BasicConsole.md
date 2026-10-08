# x86 `src/bsd/dev/i386/BasicConsole.c` (plan 337 (S5-P327), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 337 (S5-P327). Final run `s5p337-it3`; 07 file SHA-256 `e05569f6e1c855776ead6ed8a72c87763344ec50b7762c1089ef633c409a00f0`; diff `x86-BasicConsole.diff`.

- Object [0x1979e4, 0x197ca0) 700 B, 2 functions (_VGASetGraphicsMode, _BasicAllocateConsole). Front `89 ec 5d c3`, back `55 89 e5 83`, next symbol 0x19b54c.
- Final L1 `09_validation/reconstruction/s5p337-it3-l1-BasicConsole-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred. Grade **P**.

Object extent [0x1979e4, 0x197ca0) 700 B (no fill before or after; next VGAConsole.c's static FlipCursor at 0x197ca0): VGASetGraphicsMode (628 B incl. a trailing 90) and BasicAllocateConsole (72 B); __TEXT,__const 0x1d54dc 110 B (miscOutData, sequencerData, crtData, attrData, gfxData, paletteVals) verified (L1d). Diagnostics s5p338-a1 .. e1. Codex review of plan 337 (gpt-6.1-sol) verified. 07 builds: s5p337-it1 failed (bsd/i386/param.h and VGAConsole.h not staged), s5p337-it2 had 4 unverified _DELAY references (param.h left out), s5p337-it3 with the SDK machparam.h: __text 0 differences (1 MATCH + 1 MATCH_UNVERIFIED for the __bss references), relcheck 0.
