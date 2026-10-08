# x86 `src/kern/power.c` (plan 238 (S5-P223), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 238 (S5-P223). Final run `s5p223-it1`; 07 file SHA-256 `1dfcce4c14aeda3e2bacedbc8b836fa516ea3a4c320d7c34310b85f07d942dff`; diff `x86-power.diff`.

- Object [0x160adc, 0x160e81) 933 B, 7 functions (_power_callout, _power_init, _kern_PMSetPowerState, _kern_PMGetPowerEvent, _kern_PMGetPowerStatus, _kern_PMSetPowerManagement, _kern_PMRestoreDefaults). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x160e84.
- Final L1 `09_validation/reconstruction/s5p223-it1-l1-power-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x160adc, 0x160e84) 936 B, 7 functions, 0x00 fill before and after. __DATA,__data: the zero-initialized power_init marker at 0x1df224 (verified by L1); __DATA,__bss: the system state at 0x1e5e4c. The event-to-action mapping comes from the three jump tables (0x160b10, 0x160c20, 0x160d70) and kern/power.h. The codex review of plan 238 confirmed facts 0-5. Build s5p223-it1: __text and __data match on the first build, relcheck 0; __bss reference-inferred.
