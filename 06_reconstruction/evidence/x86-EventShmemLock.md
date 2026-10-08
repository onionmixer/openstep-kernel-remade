# x86 `src/bsd/dev/i386/EventShmemLock.s` (plan 363 (S5-P349), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "EventShmemLock.s" (objc.json module (none)). Final run `s5p363-r1evl`; 07 file SHA-256 `92d57404d4e2826d92f2950252e18ae2d1d5f42cbb623ecb53771e28bb71ef04`; diff `x86-EventShmemLock.diff`.

- `__text` [0x1a0d4c, 0x1a0d8d) 65 B, 4 functions (0 methods) (_ev_lock, _ev_unlock, _ev_try_lock). Front `45 08 0f be 80 30 01 00 00 89 ec 5d c3 00 00 00`, back `00 00 00 55`, next function 0x1a0d90.
- Sections: __TEXT,__text 65 B given by symbol.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p363-r1evl-l1-EventShmemLock-F-20261002.json`). Grade **A**.

Kernel event-system shared memory locks (Darwin files.i386:69 bsd/dev/i386/EventShmemLock.s, between PCPointer.m and kbd_entries.m). __text [0x1a0d4c, 0x1a0d8d) 65 B, fill 00 x 3 before and after. Code is in EventShmemLock.h (LEAF lines 55/76/93 in Darwin); local label _spin (17 B inside ev_lock) is compared by L1 but is not a function row. Diagnostic s5p363-devl2; codex review of plan 363 (gpt-6.1-sol) verified. Final s5p363-r1evl from 07: OBJECT_MATCH, relcheck 0.
