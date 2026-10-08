# x86 `src/machdep/i386/start.s` (plan 292 (S5-P282), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 292 (S5-P282). Final run `s5p282-it1`; 07 file SHA-256 `291c8ef305ea23bdeb474d9f4f5860a2843d9c2116525294ff0585a69636b512`; diff `x86-start.diff`.

- Object [0x1860dc, 0x186135) 89 B, 1 functions (_start). Front `89 ec 5d c3`, back `00 00 00 6a`, next symbol 0x186138.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p282-it1-l1-start-F-20261002.json`). Grade **A**.

Object [0x1860dc, 0x186135) 89 B + 00 00 00; front miniMonMachdep (ret 0x1860db), next _trp_divr 0x186138. __data [0x1e17b0, 0x1e17be) 14 B: _gdt_limit/_gdt_base, _idt_limit/_idt_base (8-byte aligned). References by file name: Darwin 0.1 kernel/machdep/i386/start.s (base), ppc/start.s; Mach4 i386/kernel/i386at/boothdr.S has a different multiboot _start (no matching source), NeXTMach next/locore.s is m68k. Local labels start1/vstart stay local symbols in the object; no effect on bytes or relocations. The codex review of plan 292 confirmed bytes and data and narrowed the counterpart wording (verified, fixed). it1 (s5p282-it1) from 07 OBJECT_MATCH, relcheck 0.
