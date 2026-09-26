F0075F88: 9de3bf98                 save    %sp, -0x68, %sp
F0075F8C: 133c0442                 sethi   %hi(_thread_collect_max_rate), %o1
F0075F90: d0026368                 ld      [%o1+%lo(_thread_collect_max_rate)], %o0
F0075F94: 80a22000                 cmp     %o0, 0
F0075F98: 12800006                 bne     loc_F0075FB0
F0075F9C: 113c0442                 sethi   -0xFEEF800, %o0
F0075FA0: 113c043e                 sethi   %hi(_hz), %o0
F0075FA4: d00223e0                 ld      [%o0+%lo(_hz)], %o0
F0075FA8: d0226368                 st      %o0, [%o1+%lo(_thread_collect_max_rate)]
F0075FAC: 113c0442                 sethi   -0xFEEF800, %o0
F0075FB0: d0022360                 ld      [%o0+0x360], %o0
F0075FB4: 80a22000                 cmp     %o0, 0
F0075FB8: 0280000c                 be      locret_F0075FE8
F0075FBC: d4026368                 ld      [%o1+0x368], %o2
F0075FC0: 173c0442                 sethi   %hi(_thread_collect_last_tick), %o3
F0075FC4: d002e364                 ld      [%o3+%lo(_thread_collect_last_tick)], %o0
F0075FC8: 133c04f0                 sethi   %hi(_sched_tick), %o1
F0075FCC: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F0075FD0: 9002000a                 add     %o0, %o2, %o0
F0075FD4: 80a24008                 cmp     %o1, %o0
F0075FD8: 08800004                 bleu    locret_F0075FE8
F0075FDC: 01000000                 nop
F0075FE0: 7fffffe7                 call    _thread_collect_scan
F0075FE4: d222e364                 st      %o1, [%o3+%lo(_thread_collect_last_tick)]
F0075FE8: 81c7e008                 ret
F0075FEC: 81e80000                 restore
