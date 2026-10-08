# x86 `src/kern/mach_loader.c` (plan 262 (S5-P248), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 262 (S5-P248). Final run `s5p248-it2`; 07 file SHA-256 `a44b9004769ef0691c373f94f3d3f8a7177239806a4b5f5491d4e3f3daec5fb0`; diff `x86-mach_loader.diff`.

- Object [0x15ca74, 0x15d6b5) 3137 B, 12 functions (_load_machfile, (static parse_machfile), (static load_segment), (static load_unixthread), (static load_thread), (static load_threadstate), (static load_threadstack), (static load_threadentry), (static load_fvmlib), (static load_idfvmlib), (static load_dylinker), (static get_macho_vnode)). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x15d8d0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p248-it2-l1-mach_loader-F-20261002.json`). Grade **A**.

Object extent [0x15ca74, 0x15d6b8) 3140 B (3137 B text + 00 x3; front after mach_fat; back before the mach_net object at 0x15d6b8): load_machfile and 11 statics; two jump tables inside __text; no data. The codex review of plan 262 corrected my claim that NeXTMach has no mach_loader.c (it has an older form, verified and recorded as not used) and confirmed the jump tables, argument values and error codes (verified). Scratch builds (07 untouched) s5p248-w1 (missing loader.h staging), w2 (get_macho_vnode 4 B short: local layout and branch order), w3 (is_fat form, fat_arch declared before the header) OBJECT_MATCH; it1/it2 (s5p248-it2) from 07 OBJECT_MATCH, relcheck 0.
