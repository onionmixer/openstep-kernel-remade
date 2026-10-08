# x86 `src/machdep/i386/in_cksum.c` (plan 247 (S5-P232), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 247 (S5-P232). Final run `s5p232-it1`; 07 file SHA-256 `8348507f7cf4a61f8d6902e4a1ddf8d2e24c38856908aacb2340e174c6700e53`; diff `x86-in_cksum.diff`.

- Object [0x18b2ac, 0x18b512) 614 B, 1 functions (_in_cksum). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x18b514.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p232-it1-l1-in_cksum-F-20261002.json`). Grade **A**.

Object extent [0x18b2ac, 0x18b514) 616 B (front 0x18b2ab 00 after the idt object; back 0x18b512-13 00 00 before the intr object): in_cksum with the checksum block inlined three times (0x18b2d7, 0x18b3ab, 0x18b48d, byte-identical). The codex review of plan 247 corrected my mtod wording (m + m_off) and added the odd-count condition of the slow path, adopted. it1 (s5p232-it1) OBJECT_MATCH, relcheck 0.
