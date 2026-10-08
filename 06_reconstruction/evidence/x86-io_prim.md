# x86 `src/machdep/i386/io_prim.c` (plan 244 (S5-P229), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 244 (S5-P229). Final run `s5p229-it1`; 07 file SHA-256 `8cb905d451353d22093a3dfdd51fee9a996a19f957f32dff320b6bde85dcc9c1`; diff `x86-io_prim.diff`.

- Object [0x18c9dc, 0x18cac5) 233 B, 8 functions (_inb, _inw, _inl, _outb, _outw, _outl, _linw, _loutw). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x18cac8.
- Final L1 `09_validation/reconstruction/s5p229-it1-l1-io_prim-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x18c9dc, 0x18cac8) 236 B (front 0x18c9da-db 00 00 after the intr object, back 0x18cac5-c7 00 00 00 before kern_machdep): inb, inw, inl, outb, outw, outl, linw, loutw. inl masks its 32-bit read to 16 bits and outl writes eax after loading only ax, both as the io_inline.h prototypes (unsigned short) give. The codex review of plan 244 found no errors (outl write width noted). it1 (s5p229-it1): __text matches, relcheck 0; __bss reference-inferred.
