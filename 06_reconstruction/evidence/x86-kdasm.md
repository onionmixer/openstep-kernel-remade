# x86 `src/machdep/i386/kdasm.s` (plan 278 (S5-P268), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 278 (S5-P268). Final run `s5p268-it1`; 07 file SHA-256 `c1772b3d20306ac35b27d6a0dbbfbc08cbad47f47e23a42f9a873402b9d8a5fa`; diff `x86-kdasm.diff`.

- Object [0x194dfc, 0x194e41) 69 B, 3 functions (_kd_slmwd, _kd_slmscu, _kd_slmscd). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x194e44.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p268-it1-l1-kdasm-F-20261002.json`). Grade **A**.

Object extent [0x194dfc, 0x194e44) 72 B (69 B text, 00 at 0x194e27 between functions, 00 00 00 boundary padding at 0x194e41): kd_slmwd, kd_slmscu, kd_slmscd; front mem.c (confirmed, ends 0x194dfc), next rtcinit (rtc.c, plan 277). No data. The Mach4 #defines for start/count/value/from/to are kept: the build command (cc -traditional-cpp ... -c x.s) preprocesses .s files, shown by the match. References by file name: Mach4 i386/kernel/i386at/kdasm.S (base), Darwin 0.1 bsd/dev/i386/kdasm.s (code reference; it has the same cld removals), no NeXTMach file. Scratch s5p268-w2 OBJECT_MATCH. The codex review of plan 278 corrected the front neighbour (mem.c, not cons.c) and the reason for not using Mach4 asm.h (both verified and fixed). it1 (s5p268-it1) from 07 OBJECT_MATCH, relcheck 0 mismatches.
