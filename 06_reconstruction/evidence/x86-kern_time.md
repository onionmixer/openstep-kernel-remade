# x86 `src/bsd/kern/kern_time.c` (plan 145, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 145. Final run `s5p119-it3`; 07 file SHA-256 `9411f0c1005b565e18bc71782a514c00222d0b4473bbf0f9c191ecc7ff398c25`; diff `x86-kern_time.diff`.

- Object [0x10abb0, 0x10b463) 2227 B, 14 functions (_gettimeofday, _settimeofday, _setthetime, _getthetime, _adjtime, _inittodr, _getitimer, _setitimer, _realitexpire, _itimerfix, _itimerdecr, _timevaladd, _timevalsub, _timevalfix). Front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x10b464.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p119-it3-l1-kern_time-F-20261002.json`). Grade **A**.

Iterations: it1 (setthetime/adjtime/inittodr sizes equal; getthetime 36/48), variants s5p119-v1/-v2 (getthetime: only `volatile mtime` + `time_value_t` local match), it2 (13 MATCH, `__data` differs: NeXTMach's bigadj definition), it3 OBJECT_MATCH 14/14. objects.tsv ends this object at 0x10b460; the object ends at 0x10b463.

## plan 401 고침(2026-10-08)
- plan 401 (D060; D024, place not evidenced): struct timeval boottime defined at file scope
- 공통 기호 요청만 바뀌어 `__text`·`__data` 바이트는 그대로입니다: plan 401 재빌드(s6l3-*, 402 객체)에서 이 객체의 L1 이 이전 결과와 같습니다. 이 고침으로 공통 기호 417 개의 배치가 원본과 같아졌고, 07 에서 다시 링크·strip 한 커널(run s6p402-ln1)이 원본과 바이트 단위로 같습니다. 07 파일 SHA-256 `a778faeabd52375580d1bb00ca04552f819d261919bbff576733d537839d1d51`.
- diff `06_reconstruction/evidence/x86-kern_time.diff` 를 다시 만들었습니다.
