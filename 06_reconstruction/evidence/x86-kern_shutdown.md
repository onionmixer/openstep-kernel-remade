# x86 `src/bsd/kern/kern_shutdown.c` (plan 229 (S5-P212), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 229 (S5-P212). Final run `s5p212-it2`; 07 file SHA-256 `e5a288e6301d0ca236a16c809d67ff9579157a3b687dde411dd5d58280633d7d`; diff `x86-kern_shutdown.diff`.

- Object [0x108b84, 0x109127) 1443 B, 5 functions (_boot, _unmount_all, _kill_tasks, _proc_shutdown, _fd_shutdown). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x109128.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p212-it2-l1-kern_shutdown-F-20261002.json`). Grade **A**.

Object extent [0x108b84, 0x109128) 1444 B: boot, unmount_all, kill_tasks, proc_shutdown, fd_shutdown with nop fill between functions (one object) and 0x00 linker fill before and after; objects.tsv splits the range into two name-based candidates (seq 26 machdep.c, seq 27 kern_shutdown.c/shutdown.c). __DATA,__data holds _waittime (-1, 0x1da990) and the strings. Diagnosis s5p212-d3 (NeXTMach shutdown.c with the machdep.c functions, staging copy only): boot and unmount_all match; kill_tasks, proc_shutdown and fd_shutdown differ as listed in plan 229. The codex review of plan 229 confirmed facts 1-7 from the original bytes; its note that the plan mixed the order of original and diagnosis sizes was correct and the plan was fixed. it1 failed (reaper_queue undeclared); it2 (s5p212-it2): OBJECT_MATCH, relcheck 0.

## plan 401 고침(2026-10-08)
- plan 401: #import <ufs/inode.h> added (as Darwin 0.1 kern_shutdown.c:62); its tentative inode_list and iuniqtime make kern_shutdown their first mention, as in the original __common
- 공통 기호 요청만 바뀌어 `__text`·`__data` 바이트는 그대로입니다: plan 401 재빌드(s6l3-*, 402 객체)에서 이 객체의 L1 이 이전 결과와 같습니다. 이 고침으로 공통 기호 417 개의 배치가 원본과 같아졌고, 07 에서 다시 링크·strip 한 커널(run s6p402-ln1)이 원본과 바이트 단위로 같습니다. 07 파일 SHA-256 `c39e19c1a050b0441396e63688fef764b323bf93754ed9954bcc54b30123db0e`.
- diff `06_reconstruction/evidence/x86-kern_shutdown.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 401 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `5b5adf7cc9eed5c1e57a1b63cbb526e677fc9a2dc140ef0fc9fc03477aa38f64`); diff 를 다시 만들었습니다.
