# x86 `src/bsd/kern/kern_fork.c` (plan 202 (S5-P175), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 202 (S5-P175). Final run `s5p175-it1`; 07 file SHA-256 `d1ade0150c61719da01f526fd557c9a59a461c08fb3ef65bd22ab7e8105e8ee5`; diff `x86-kern_fork.diff`.

- Object [0x106818, 0x106e2d) 1557 B, 12 functions (_fork, _vfork, _fork1, _newproc, _cloneproc, _uzone_init, _utask_free, _uthread_free, _uarea_init, _uarea_zero, _utask_zero, _switch_unix_context). Front `ec 5d c3 00`, back `00 00 00 55`, next symbol 0x106e30.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p175-it1-l1-kern_fork-F-20261002.json`). Grade **A**.

Object extent [0x106818, 0x106e30) (12 functions; 3 bytes padding). Diagnosis 13 failed on u_address; a diagnosis build with only that substitution (s5p175-d1, not 07) showed the POSIX and zone differences. The codex review of plan 202 confirmed the field order and added the kept kfree cleanup in utask_free. it1 OBJECT_MATCH 12/12 including __data (strings proc, no procs, utasks, uthreads). Diagnostic compile without POSIX_KERN exit 0.

## plan 400 고침(2026-10-08)
- plan 400: u_task_zone, u_thread_zone defined (were extern; u_thread_zone Darwin 0.1 kern_fork.c:346, u_task_zone D059) and struct _u_address active_u[NCPUS] (D059, place not evidenced)
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `f0d919f60ea834fc0dd48dae061bea44f3cd61080355ec04e33ab1205cddc06a`.
- diff `06_reconstruction/evidence/x86-kern_fork.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 400 (Darwin), u_thread_zone part: Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `f03f4b116fc7f8fb7c908b77e6df06e5cc2db59404c1a81cffd2b726ebc18a20`); diff 를 다시 만들었습니다.
