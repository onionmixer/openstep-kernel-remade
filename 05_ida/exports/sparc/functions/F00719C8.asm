F00719C8: 9de3bf98                 save    %sp, -0x68, %sp
F00719CC: 113c04f190122040         set     _recompute_priorities_timer, %o0
F00719D4: 173c04f0                 sethi   %hi(_sched_tick), %o3
F00719D8: d402e298                 ld      [%o3+%lo(_sched_tick)], %o2
F00719DC: 133c043e                 sethi   %hi(_hz), %o1
F00719E0: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F00719E4: 9402a001                 inc     %o2
F00719E8: 7fffdffa                 call    _set_timeout
F00719EC: d422e298                 st      %o2, [%o3+%lo(_sched_tick)]
F00719F0: 7ffff266                 call    _sched_usec_elapsed
F00719F4: 01000000                 nop
F00719F8: 173c04f1                 sethi   %hi(_sched_usec), %o3
F00719FC: d202e080                 ld      [%o3+%lo(_sched_usec)], %o1
F0071A00: 952a6002                 sll     %o1, 2, %o2
F0071A04: 94028009                 add     %o2, %o1, %o2
F0071A08: 932a2001                 sll     %o0, 1, %o1
F0071A0C: 92024008                 add     %o1, %o0, %o1
F0071A10: 92828009                 addcc   %o2, %o1, %o1
F0071A14: 2c800002                 bneg,a  loc_F0071A1C
F0071A18: 92026007                 inc     7, %o1
F0071A1C: 933a6003                 sra     %o1, 3, %o1
F0071A20: 113c04f1                 sethi   %hi(_sched_thread_id), %o0
F0071A24: d0022078                 ld      [%o0+%lo(_sched_thread_id)], %o0
F0071A28: 80a22000                 cmp     %o0, 0
F0071A2C: 02800005                 be      locret_F0071A40
F0071A30: d222e080                 st      %o1, [%o3+0x80]
F0071A34: 92102000                 mov     0, %o1
F0071A38: 7ffffcfe                 call    _clear_wait
F0071A3C: 94102000                 mov     0, %o2
F0071A40: 81c7e008                 ret
F0071A44: 81e80000                 restore
