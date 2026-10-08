# x86 `src/bsd/kern/kern_proc.c` (plan 211 (S5-P185), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 211 (S5-P185). Final run `s5p185-it5`; 07 file SHA-256 `a68ae556009dd6747a96114638359acc2214839cddcec3d9ab7f8167f70f254b`; diff `x86-kern_proc.diff`.

- Object [0x107304, 0x107a23) 1823 B, 19 functions (_spgrp, _inferior, _pfind, _pidhash_enter, _getproc, _proc_cache_clear, _pqinit, _pgfind, _enterpgrp, _leavepgrp, _pgdelete, _fixjobc, (static orphanpg), _get_posix_proc, _alloc_posix_proc, _free_posix_proc, _insert_posix_proc, _new_posix_proc, _delete_posix_proc). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x107a24.
- Final L1 `09_validation/reconstruction/s5p185-it5-l1-kern_proc-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x107304, 0x107a24): the padding byte before 0x107a24 is the linker's 0x00 (compiler padding inside the object is 0x90), so proc_from_thread, utask_from_thread and uthread_from_thread belong to the next object (kern_prot side). Diagnosis 13 failed on zone_t; a diagnosis build with kern/zalloc.h (s5p185-d1, not 07) matched the five NeXTMach functions. The codex review of plan 211 corrected the counts and the null guards. Iterations: it1 proc_from_thread branch layout (variants s5p185-v1, v2 chosen); it2 boundary corrected; free_posix_proc register choice fixed by the kalloc.h prototypes (variants s5p185-v2..v4 without effect); it4/it5 all functions match, only the unsymbolled __bss proc_count reference-inferred (__TEXT,__const posix_proc_zero verified by L1d). Diagnostic compile without POSIX_KERN exit 0 (s5p185-noposix2).

## plan 400 고침(2026-10-08)
- plan 400: struct pgrp *pgrphash[PIDHSZ] (Darwin 0.1 kern_proc.c:95) and struct posix_proc *posix_proc_hash[PIDHSZ] (D059, place not evidenced) defined
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `8c7ca7049602e23d5022d198d779a338e0ec28640feb9ebeea957a88d3f39396`.
- diff `06_reconstruction/evidence/x86-kern_proc.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- comment of the pgrphash line corrected (plan 400 cited Darwin 0.1 kern_proc.c:95, which is a different declaration, u_long pgrphash; the type comes from the SDK sys/proc.h:250 extern). 주석만 바뀌었습니다(07 파일 SHA-256 `9a492c83ae4b1f29108add017c980c1efc1acc73789d62f6f3026651009c2181`); diff 를 다시 만들었습니다.
