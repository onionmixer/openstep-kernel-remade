# x86 `src/driverkit/audio_mix.c` (plan 289 (S5-P279), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 289 (S5-P279). Final run `s5p279-it1`; 07 file SHA-256 `59308b22312a3d334c036a49d6184894a41312486e837d4a6f88bf68c02ae99c`; diff `x86-audio_mix.diff`.

- Object [0x1bdef0, 0x1be71c) 2092 B, 14 functions (_audio_swapSamples, _audio_twosComp8ToUnary, _audio_scaleSamples, _audio_resample22To44, _audio_resample44To22, _audio_convertMonoToStereo, _audio_convertStereoToMono, _audio_convertLinear8ToLinear16, _audio_convertLinear8ToMulaw8, _audio_convertLinear16ToLinear8, _audio_convertLinear16ToMulaw8, _audio_convertMulaw8ToLinear16, _audio_convertMulaw8ToLinear8, _audio_mix). Front `89 ec 5d c3`, back `55 89 e5 57`, next symbol 0x1be71c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p279-it1-l1-audio_mix-F-20261002.json`). Grade **A**.

Object extent [0x1bdef0, 0x1be71c) 2092 B (no boundary padding; nops between functions); front snd_reply.c (ends 0x1bdeef), next audio_peak (plan 288). Fourteen globals; four __TEXT,__cstring strings used by five IOLog calls (convMono shared). References by file name: Darwin 0.1 driverkit-1/libDriver/Kernel/audio_mix.c, audio_mix.h, audio_types.h, audioLog.h, kernel/bsd/dev/audioTypes.h; no NeXTMach or Mach4 file. Built without -fwritable-strings (libDriver, plan 285). Scratch s5p279-w3 2156 B (Darwin resample22To44), w4 matched. The codex review of plan 289 confirmed the bytes and narrowed the enum claim (verified, fixed). it1 (s5p279-it1) from 07 OBJECT_MATCH, relcheck 0.
