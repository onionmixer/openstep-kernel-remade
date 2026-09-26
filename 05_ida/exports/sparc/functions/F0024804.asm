F0024804: 9de3bf98                 save    %sp, -0x68, %sp
F0024808: d0060000                 ld      [%i0], %o0
F002480C: 808a2200                 btst    0x200, %o0
F0024810: 32800008                 bne,a   loc_F0024830
F0024814: d2060000                 ld      [%i0], %o1
F0024818: 113c04cf                 sethi   %hi(_active_u), %o0
F002481C: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0024820: d002619c                 ld      [%o1+0x19C], %o0
F0024824: 90022001                 inc     %o0
F0024828: d022619c                 st      %o0, [%o1+0x19C]
F002482C: d2060000                 ld      [%i0], %o1
F0024830: 90100018                 mov     %i0, %o0
F0024834: 92126202                 bset    0x202, %o1
F0024838: 4000000c                 call    _brelse
F002483C: d2220000                 st      %o1, [%o0]
F0024840: 81c7e008                 ret
F0024844: 81e80000                 restore
