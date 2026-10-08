# x86 `src/machdep/i386/bios_asm.s` (plan 255 (S5-P240), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 255 (S5-P240). Final run `s5p240-it2`; 07 file SHA-256 `aad427512148738dd284ac7385764dc31ead5d07626eb9166c680deca7140cea`; diff `x86-bios_asm.diff`.

- Object [0x187108, 0x1871d1) 201 B, 1 functions (__bios32). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x1871d4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p240-it2-l1-bios_asm-F-20261002.json`). Grade **A**.

Object extent [0x187108, 0x1871d4) 204 B (201 B text + 3 x 00; front after catch, no padding; back before bios _bios32). __DATA,__data [0x1e17c0, 0x1e17d8) 24 B (six words, placement inferred, verified by L1d; 0x1e17be-bf are 00 padding after _idt_base). The codex review of plan 255 corrected the _idt_base extent and noted that the .s probe did not test preprocessing (both verified; the source was made preprocessor-independent). it1 (s5p240-it1) OBJECT_MATCH with the call labels emitted as symbols; it2 (s5p240-it2) with assembler-local labels (Lcall_off/Lcall_seg) OBJECT_MATCH, relcheck 0. This shows that the build command (cc -traditional-cpp ... -c x.s) assembles a .s file to the original bytes.
