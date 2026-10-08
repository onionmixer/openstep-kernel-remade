# x86 `src/bsd/kern/kern_clock.c` (plan 233 (S5-P218), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 233 (S5-P218). Final run `s5p218-it1`; 07 file SHA-256 `f6ef3d6034dd3ab5f694b1d13170b418b14aa65400d05995e22947c297280212`; diff `x86-kern_clock.diff`.

- Object [0x10349c, 0x103822) 902 B, 8 functions (_hardclock, _gatherstats, _timeout, _untimeout, _hzto, _ticks_to_timeval, _profil, _add_profil). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x103824.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p218-it1-l1-kern_clock-F-20261002.json`). Grade **A**.

Object extent [0x10349c, 0x103822) 902 B: hardclock, gatherstats, timeout, untimeout, hzto, ticks_to_timeval, profil, add_profil; after the confirmed kern_acct, 0x00 fill before core. add_profil follows profil with no fill at an aligned address, so its membership in the same original object is inferred (objects.tsv lists it as a name-based subr_prof.c candidate; NeXTMach keeps profil in kern_clock.c). Diagnosis s5p218-d1 (plan 233 applied, staging copy): 8 functions matched in size and shape. The codex review of plan 233 confirmed facts 0-8 and the inference wording. Build s5p218-it1: OBJECT_MATCH on the first build, relcheck 0.

## plan 401 고침(2026-10-08)
- plan 401: struct callout *callout made extern (defined in conf/param.c; NeXTMach sys/callout.h:48 extern)
- 공통 기호 요청만 바뀌어 `__text`·`__data` 바이트는 그대로입니다: plan 401 재빌드(s6l3-*, 402 객체)에서 이 객체의 L1 이 이전 결과와 같습니다. 이 고침으로 공통 기호 417 개의 배치가 원본과 같아졌고, 07 에서 다시 링크·strip 한 커널(run s6p402-ln1)이 원본과 바이트 단위로 같습니다. 07 파일 SHA-256 `a454d6af20b64f558646eea9aeb3c556e9e7e33d5e1f7ca3e5a6bc004faf9e2d`.
- diff `06_reconstruction/evidence/x86-kern_clock.diff` 를 다시 만들었습니다.
