# x86 `src/bsd/dev/i386/kbd_entries.m` (plan 363 (S5-P349), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "kbd_entries.m" (objc.json module (none)). Final run `s5p363-r1kbd`; 07 file SHA-256 `a99fdd40219b9d57006f4e23bfb06287e6ba4c0e5c8e2117ee8c00c52c667cd2`; diff `x86-kbd_entries.diff`.

- `__text` [0x1a0d90, 0x1a0e46) 182 B, 4 functions (0 methods) (_keyboard_reboot, _StealKeyEvent, _steal_keyboard_event, _register_keyboard_entries). Front `00 00 72 06 b8 01 00 00 00 c3 31 c0 c3 00 00 00`, back `00 00 55 89`, next function 0x1a0e48.
- Sections: __TEXT,__text 182 B given by symbol; __DATA,__data 8 B inferred, verified by L1d.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p363-r1kbd-l1-kbd_entries-F-20261002.json`). Grade **A**.

Keyboard entry registration (Darwin files.i386:70). __text [0x1a0d90, 0x1a0e46) 182 B, then 00 x 2 to _PCcreate 0x1a0e48; __DATA,__data 8 B at 0x1e4b78 (inferred from four text relocations, verified by L1d). Darwin PS2Keyboard.m:670 also defines StealKeyEvent (not in files.i386, no present collision). Diagnostic s5p363-dkbd4; codex review of plan 363 (gpt-6.1-sol) verified. Final s5p363-r1kbd from 07: OBJECT_MATCH, relcheck 0.
