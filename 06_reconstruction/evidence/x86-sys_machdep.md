# x86 `src/machdep/i386/sys_machdep.c` (plan 272 (S5-P262), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 272 (S5-P262). Final run `s5p262-it1`; 07 file SHA-256 `d46a1a5c22dc0e46d2521c72483432b497d3aa8a25d58803bdc78778e43f0b7c`; diff `x86-sys_machdep.diff`.

- Object [0x191e48, 0x191e4f) 7 B, 1 functions (_resuba). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x191e50.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p262-it1-l1-sys_machdep-F-20261002.json`). Grade **A**.

Object extent [0x191e48, 0x191e50) 8 B (7 B text 55 89 e5 89 ec 5d c3 + 00): _resuba only; front: initrootnet ret 0x191e47, next _user_trap (trap). No allocated data; header tentative definitions give eleven common symbols (D021 header set), as in other objects. The object boundary is a reconstruction inference: resuba could also sit at the end of swapgeneric or the start of trap; Darwin 0.1 i386 sys_machdep.c holds an empty resuba and NeXTMach swapgeneric.c has none. References by file name: NeXTMach next/sys_machdep.c (base), Darwin 0.1 machdep/i386/sys_machdep.c (reference), no Mach4 file. Scratch s5p262-w1 OBJECT_MATCH. The codex review of plan 272 confirmed the bytes and the edits and asked for the boundary to be marked as inferred and the commons to be recorded (both verified). it1 (s5p262-it1) from 07 OBJECT_MATCH, relcheck 0 mismatches.
