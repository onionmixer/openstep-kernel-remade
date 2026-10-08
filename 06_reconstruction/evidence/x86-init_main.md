# x86 `src/bsd/kern/init_main.c` (plan 232 (S5-P216), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 232 (S5-P216). Final run `s5p216-it2`; 07 file SHA-256 `ed2b791ea468b652febfcded458d54de2a004a2495a9e4d0870ac7236bb2783c`; diff `x86-init_main.diff`.

- Object [0x102934, 0x103085) 1873 B, 8 functions (_task_name, _main, _init_task, _lightning_bolt, _bhinit, _binit, _cinit, (static classHandler)). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x103088.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p216-it2-l1-init_main-F-20261002.json`). Grade **A**.

Object extent [0x102934, 0x103088) 1876 B: task_name, main, init_task, lightning_bolt, bhinit, binit, cinit and an unnamed static function at 0x10307c (passed to objc_setClassHandler); 0x00 fill before and after. __DATA,__data [0x1da000, 0x1da034): dk_ndrive, cmask, vm_initial_limit_stack/data/core and the strings kernel idle and init. Diagnosis s5p216-d1 (NeXTMach text) failed on headers; s5p216-d3 (plan 232 applied, staging copy) matched every function size. The codex review of plan 232 was checked: its cinit size correction was right (plan fixed); its claim that u_cdir is cleared first was rejected (the first store at 0x102c23 is u+0x164 = uu_rdir, the offsets confirmed by the recorded kern_shutdown). Build s5p216-it1: OBJECT_MATCH including __data, relcheck 0; it2 (POSIX init under #if POSIX_KERN): OBJECT_MATCH, relcheck 0; compiles without POSIX_KERN (s5p216-noposix).

## plan 401 고침(2026-10-08)
- plan 401 (D060): struct timeval boottime made extern (defined in kern_time.c; the original init_main does not mention it)
- 공통 기호 요청만 바뀌어 `__text`·`__data` 바이트는 그대로입니다: plan 401 재빌드(s6l3-*, 402 객체)에서 이 객체의 L1 이 이전 결과와 같습니다. 이 고침으로 공통 기호 417 개의 배치가 원본과 같아졌고, 07 에서 다시 링크·strip 한 커널(run s6p402-ln1)이 원본과 바이트 단위로 같습니다. 07 파일 SHA-256 `5d36e3a265aaab037f081369adb1b65525a47984305fca59bc174e758dab9634`.
- diff `06_reconstruction/evidence/x86-init_main.diff` 를 다시 만들었습니다.
