# x86 `src/driverkit/audio_mulaw.c` (plan 287 (S5-P277), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 287 (S5-P277). Final run `s5p277-it1`; 07 file SHA-256 `468fcc998a0c320bce1bd45f8a4225e8db62fccfdcd566d90978baa31f87201d`; diff `x86-audio_mulaw.diff`.

- Object [0x1be9c0, 0x1beb56) 406 B, 5 functions (_audio_makeIMuLawTab, _audio_freeIMuLawTab, _audio_shortToMulaw, _audio_byteToMulaw, (static compar)). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x1beb58.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p277-it1-l1-audio_mulaw-F-20261002.json`). Grade **A**.

Object extent [0x1be9c0, 0x1beb56) 406 B + 00 00; front audio_peak.c, next strtol 0x1beb58 (confirmed). Four globals and the static comparison function 0x1beb1c (address passed to qsort at 0x1bea22, so emitted last). __TEXT,__const audio_muLaw[256] at 0x1d5ee4 (512 B, byte-identical), __DATA,__data static iMuLaw = 0 at 0x1e53cc. References by file name: Darwin 0.1 driverkit-1/libDriver/Kernel/audio_mulaw.c only. Built without -fwritable-strings (libDriver, plan 285). The codex review of plan 287 confirmed bytes and table and corrected the header range and stale wording (verified, fixed). it1 (s5p277-it1) from 07 OBJECT_MATCH, relcheck 0.
