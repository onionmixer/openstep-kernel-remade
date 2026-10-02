# x86 `src/bsd/kern/kern_time.c` (plan 145, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 145. Final run `s5p119-it3`; 07 file SHA-256 `9411f0c1005b565e18bc71782a514c00222d0b4473bbf0f9c191ecc7ff398c25`; diff `x86-kern_time.diff`.

- Object [0x10abb0, 0x10b463) 2227 B, 14 functions (_gettimeofday, _settimeofday, _setthetime, _getthetime, _adjtime, _inittodr, _getitimer, _setitimer, _realitexpire, _itimerfix, _itimerdecr, _timevaladd, _timevalsub, _timevalfix). Front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x10b464.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p119-it3-l1-kern_time-F-20261002.json`). Grade **A**.

Iterations: it1 (setthetime/adjtime/inittodr sizes equal; getthetime 36/48), variants s5p119-v1/-v2 (getthetime: only `volatile mtime` + `time_value_t` local match), it2 (13 MATCH, `__data` differs: NeXTMach's bigadj definition), it3 OBJECT_MATCH 14/14. objects.tsv ends this object at 0x10b460; the object ends at 0x10b463.
