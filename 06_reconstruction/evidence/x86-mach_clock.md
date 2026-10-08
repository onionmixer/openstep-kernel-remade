# x86 `src/kern/mach_clock.c` (plan 235 (S5-P220), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 235 (S5-P220). Final run `s5p220-it1`; 07 file SHA-256 `73813a52df12168e22b9405201d7afbba7ae7c3313dda32b3a99ed55e31f5a4c`; diff `x86-mach_clock.diff`.

- Object [0x15bc30, 0x15c0ff) 1231 B, 10 functions (_clock_interrupt, _init_timeout_element, _set_timeout, _reset_timeout, _init_timeout, _host_get_time, _host_set_time, _host_adjust_time, _mach_clock_bootstrap, (static service_timer)). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x15c100.
- Final L1 `09_validation/reconstruction/s5p220-it1-l1-mach_clock-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x15bc30, 0x15c100) 1232 B: clock_interrupt, init_timeout_element, set_timeout, reset_timeout, init_timeout, host_get_time, host_set_time, host_adjust_time, mach_clock_bootstrap and an unnamed callback at 0x15c0ac; after the confirmed lock object, 0x00 fill before compute_mach_factor. __DATA,__data [0x1dee30, 0x1dee68): hz, tick, time, timedelta, tickdelta, tickadj, bigadj, mtime and the string mappable_time_init (verified by L1). Diagnosis s5p220-d1 (Mach4 text) failed on the timer element layout. The codex review of plan 235 confirmed facts 0-7 and corrected the panic string spelling (mappable), adopted after reading the bytes. Build s5p220-it1: __text and __data match on the first build, relcheck 0; __bss (timer_lock) reference-inferred.
