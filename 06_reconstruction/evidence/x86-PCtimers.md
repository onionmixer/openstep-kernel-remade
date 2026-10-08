# x86 `src/machdep/i386/pc_support/PCtimers.c` (plan 249 (S5-P234), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 249 (S5-P234). Final run `s5p234-it2`; 07 file SHA-256 `0c263b8ea0a1c6aba201c184f4bd60faf594453464d862973420e905cd0a5f59`; diff `x86-PCtimers.diff`.

- Object [0x1a19c8, 0x1a1b5d) 405 B, 7 functions ((static PCtimeoutExpired), (static PCtickExpired), _PCscheduleTimers, _PCdeliverTimers, _PCtimersPending, _PCcancelTimers, _PCcancelAllTimers). Front `ec 5d c3 00`, back `00 00 00 55`, next symbol 0x1a25a4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p234-it2-l1-PCtimers-F-20261002.json`). Grade **A**.

Object extent [0x1a19c8, 0x1a1b60) 408 B (405 B text + 3 x 00; front 0x1a19c7 00 after PCresume; back before the PCemulateREAL object at 0x1a1b60): two unnamed statics 0x1a19c8 (timeout expiry) and 0x1a19e8 (tick expiry), PCscheduleTimers, PCdeliverTimers, PCtimersPending, PCcancelTimers, PCcancelAllTimers. No data sections. Earlier deferral (plan 42 range, callout API) resolved by authoring as for power.c and ns_timer.c. The codex review of plan 249 found no contradiction and added two details (the PCemulateREAL public symbol is at 0x1a25a4 inside that object; no null check of shared before the loop), both verified. it1 (s5p234-it1) matched every function but emitted the statics last (gcc defers a static whose address is not yet taken); it2 (s5p234-it2) with the inline schedulers before the statics OBJECT_MATCH, relcheck 0.
