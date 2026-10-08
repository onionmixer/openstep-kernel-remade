# x86 `src/bsd/kern/subr_log.c` (plan 181 (S5-P154), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 181 (S5-P154). Final run `s5p154-it3`; 07 file SHA-256 `7265ae5ad8d29f6920460e1bd1b5c0c190f6a0e8ffe61c69eb36b0ea2bfc3674`; diff `x86-subr_log.diff`.

- Object [0x10bd48, 0x10c0d7) 911 B, 7 functions (_logopen, _logclose, _logread, _logselect, _logwakeup, (static log_wakeup), _logioctl). Front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x10c0d8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p154-it3-l1-subr_log-F-20261002.json`). Grade **A**.

The callback at 0x10bf90 has no symbol (static assumed; referenced only as the calloutEntryAllocate argument at 0x10bd7c). Iterations: it1 thread_t undeclared (struct thread * used); it2 logwakeup loaded the callout into edx instead of eax; staged variants: void return / int casts (no), prototype of calloutEntryDispatch returning void (p1) or of the whole calloutEntry* interface (p3) -> 0 differences; it3 with p3 OBJECT_MATCH 7/7. pmsgbuf is __data (initialised 0) in the original image, log_open/logsoftc common - matched by L1.

## plan 397·398 고침(2026-10-08)
- `struct msgbuf *pmsgbuf;` 를 `= 0` 으로 초기화했습니다(원본 `_pmsgbuf` 는 `__data` 0x1dac14, 값 0).
- 진단(07 손대지 않음): s6p397-sl1. 최종: 07 에서 재빌드 s6l1-g1a(행 127, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-127.json` OBJECT_MATCH, `cc -M` 의존 모두 07. 07 파일 SHA-256 `65c98879cdf33bc33915c718fb228ad0047b4b3ed8436168dd5c87499897d0fc`.
- diff `06_reconstruction/evidence/x86-subr_log.diff` 를 다시 만들었습니다.
