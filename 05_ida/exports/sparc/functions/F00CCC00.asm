F00CCC00: 9de3bf90                 save    %sp, -0x70, %sp
F00CCC04: d0062158                 ld      [%i0+0x158], %o0
F00CCC08: 80a22000                 cmp     %o0, 0
F00CCC0C: 12800006                 bne     loc_F00CCC24
F00CCC10: 113c0330                 sethi   -0xFF34000, %o0
F00CCC14: d006215c                 ld      [%i0+0x15C], %o0
F00CCC18: 80a22000                 cmp     %o0, 0
F00CCC1C: 02800008                 be      locret_F00CCC3C
F00CCC20: 113c0330                 sethi   -0xFF34000, %o0
F00CCC24: 9012228c                 bset    0x28C, %o0
F00CCC28: 7ffe8553                 call    _ns_untimeout
F00CCC2C: 92100018                 mov     %i0, %o1
F00CCC30: 94102000                 mov     0, %o2
F00CCC34: 96102000                 mov     0, %o3
F00CCC38: d43e2158                 std     %o2, [%i0+0x158]
F00CCC3C: 81c7e008                 ret
F00CCC40: 81e80000                 restore
