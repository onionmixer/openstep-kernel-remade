# x86 `src/machdep/i386/pc_support/PCexception.c` (plan 252 (S5-P237), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 252 (S5-P237). Final run `s5p237-it1`; 07 file SHA-256 `17b30f8879c3d54af39ed3b99e8bc481e3dde51e4370b7ad7d1c4cc8f0d35019`; diff `x86-PCexception.diff`.

- Object [0x1a13a0, 0x1a15c3) 547 B, 2 functions (_PCexception, (static PCfaultContinue)). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x1a15c4.
- Final L1 `09_validation/reconstruction/s5p237-it1-l1-PCexception-F-20261002.json`: __text 0 byte differences; __TEXT,__const 4 B 18 00 20 00 unreferenced (TSS_SEL/LDT_SEL operands of the unused inline ltr()/lldt() in cpu_inline.h, as for intr.c and PCresume) -> unplaced; no __bss. Grade **P**.

Object extent [0x1a13a0, 0x1a15c4) 548 B (547 B text + 00; front 0x1a139d-9f 00 x3 after PCinit; back before PCresume at 0x1a15c4): PCexception 372 B and an unnamed static continuation 0x1a1514 175 B. No data sections. Earlier deferral (plan 71 range: the byte field +0x68 of the structure at 0x1e875c) resolved: it is u.u_error (SDK sys/user.h; the same bytes as kern_prot.c suser, plan 212). The codex review of plan 252 found no wrong claim and noted the missing null checks after the context lookups (as in the original), verified. it1 (s5p237-it1): __text 0 byte differences, relcheck 0; __TEXT,__const unplaced as for PCresume.
