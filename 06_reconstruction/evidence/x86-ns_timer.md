# x86 `src/kern/ns_timer.c` (plan 234 (S5-P219), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 234 (S5-P219). Final run `s5p219-it3`; 07 file SHA-256 `3eaee9a59d88e53ea344bd08e9a26d1b1a1198b11ed40832b68c544d5c40891c`; diff `x86-ns_timer.diff`.

- Object [0x160478, 0x160ad9) 1633 B, 17 functions (_ns_hardclock_init, _ns_timeout, _ns_abstimeout, _ns_untimeout, _ns_sleep, _ns_time_to_timeval, _timeval_to_ns_time, _ns_time_to_tsval, _ticks_to_ns_time, _sched_usec_elapsed, _get_calendar_time_value, _set_calendar_time_value, _microtime, _microboot, _us_timeout, _us_abstimeout, _us_untimeout). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x160adc.
- Final L1 `09_validation/reconstruction/s5p219-it3-l1-ns_timer-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x160478, 0x160adc) 1636 B, 17 functions, 0x00 fill before and after, nop or no fill inside (five unpadded seams, so one object is inferred; inlined division and multiplication sequences support it). Data: ns_per_tick (common), microtime previous value in __DATA,__data 0x1df21c (verified by L1), sched_usec_elapsed previous value in __DATA,__bss 0x1e5e44. The codex review of plan 234 confirmed the facts; its correction (five unpadded seams, not three) was adopted. it1 (s5p219-it1): ns_timeout and sched_usec_elapsed differed; variants s5p219-v1 (time += clock_value(System) matches) and s5p219-v2 (a by-value division helper returning the low quotient matches). it2: get_calendar_time_value frame 4 bytes larger; variants s5p219-v3 g1 (a local now divided in place) matches. it3: text and data match, relcheck 0; __bss reference-inferred.

## Plan 469 (D088, 2026-10-16): forms of the m68k original in the shared lines

- microtime tests `now < last_time` first; microboot, us_timeout and us_abstimeout call clock_value / timeval_to_ns_time in a preceding assignment (`ns_time_t now;` / `ns_time_t time;`). These are the forms of the original m68k object [0x404e3a8, 0x404eaae) (precomputed inner call, arguments kept in d2-d4 across it); x86 (-O3) gives the same code for both forms.
- x86 check: variants compiled on s6l5 (`09_validation/reconstruction/m5-x86-ns_timer-tail-variants-20261016.json`, all equal in non-STABS), full rebuild s6l7 (row 338 same as baseline; `s6-l2-prefixdiff-s6l6-s6l7-20261016.json`: only x86-ns_timer differs beyond the run path, non-STABS equal), link `s6-l2-link-s6p469-ln1.json` identical to the original (SHA-256 33469393...).
- m68k: `09_validation/reconstruction/m5-m68k-ns_timer-tail-final-20261016.json` (L1 only __DATA,__bss unverified; bss [0x40b39ba, 0x40b39c2) reference-inferred). Diff `x86-ns_timer-plan469.diff`.
