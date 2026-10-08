# x86 `src/driverkit/label_subr.c` (plan 285 (S5-P275), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 285 (S5-P275). Final run `s5p275-it1`; 07 file SHA-256 `15d6a5f5eb69632bc7a364687e8448a9953ba57d42528bf6853352f9f666a8c3`; diff `x86-label_subr.diff`.

- Object [0x1bda48, 0x1bdb8b) 323 B, 2 functions (_checksum16, _check_label). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1bdb8c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p275-it1-l1-label_subr-F-20261002.json`). Grade **A**.

Object extent [0x1bda48, 0x1bdb8b) 323 B + 00; front disk_label.c (plan 286), next audio_snd_reply_ret_device 0x1bdb8c. Strings in __TEXT,__cstring 0x1d8bfc/0x1d8c18/0x1d8c30, so this libDriver object is built without -fwritable-strings (strong inference: placement, Darwin libDriver Makefile:63/70, and the match; kernel objects keep strings in __data, e.g. 0x1e370d). -O2 (s5p275-o2) does not inline checksum16 into check_label (247 B), -O3 matches. References by file name: Darwin 0.1 driverkit-1/libDriver/label_subr.c and label_subr.h; no NeXTMach or Mach4 file. The codex review of plan 285 confirmed the bytes and asked for the flag wording, the -O2/-O3 fact and label_subr.h (verified, fixed). Text nearly Darwin's: decision D030. it1 (s5p275-it1) from 07 OBJECT_MATCH, relcheck 0.
