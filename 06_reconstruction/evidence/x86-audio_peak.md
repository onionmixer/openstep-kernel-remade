# x86 `src/driverkit/audio_peak.c` (plan 288 (S5-P278), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 288 (S5-P278). Final run `s5p278-it1`; 07 file SHA-256 `e5bb7f7c8f97325b9c359cce9aafbf54502e34338fe8e1178a111933e1937600`; diff `x86-audio_peak.diff`.

- Object [0x1be71c, 0x1be9be) 674 B, 6 functions (_audio_mulaw8_peak, _audio_linear16_peak, _audio_linear8_peak, _audio_clear_peaks, _audio_max_peak, _audio_add_peak). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x1be9c0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p278-it1-l1-audio_peak-F-20261002.json`). Grade **A**.

Object extent [0x1be71c, 0x1be9be) 674 B + 00 00; front audio_mix.c, next audio_mulaw (plan 287) 0x1be9c0. Six globals; audio_mulaw8_peak reads audio_muLaw (0x1d5ee4) at 0x1be753, 0x1be78f, 0x1be7ab. References by file name: Darwin 0.1 driverkit-1/libDriver/Kernel/audio_peak.c and audio_peak.h only. Built without -fwritable-strings (libDriver, plan 285). The codex review of plan 288 found no mismatch (FIXME comments noted). it1 (s5p278-it1) from 07 OBJECT_MATCH, relcheck 0.
