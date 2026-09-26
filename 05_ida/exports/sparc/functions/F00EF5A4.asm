F00EF5A4: 9de3bf98                 save    %sp, -0x68, %sp
F00EF5A8: d006201c                 ld      [%i0+0x1C], %o0
F00EF5AC: 80a20019                 cmp     %o0, %i1
F00EF5B0: 32800005                 bne,a   loc_F00EF5C4
F00EF5B4: d206201c                 ld      [%i0+0x1C], %o1
F00EF5B8: d0064000                 ld      [%i1], %o0
F00EF5BC: 1080000e                 ba      loc_F00EF5F4
F00EF5C0: d026201c                 st      %o0, [%i0+0x1C]
F00EF5C4: d0024000                 ld      [%o1], %o0
F00EF5C8: 80a22000                 cmp     %o0, 0
F00EF5CC: 0280000a                 be      loc_F00EF5F4
F00EF5D0: 80a20019                 cmp     %o0, %i1
F00EF5D4: 32800006                 bne,a   loc_F00EF5EC
F00EF5D8: 92100008                 mov     %o0, %o1
F00EF5DC: d0020000                 ld      [%o0], %o0
F00EF5E0: d0224000                 st      %o0, [%o1]
F00EF5E4: 10bffff9                 ba      loc_F00EF5C8
F00EF5E8: 90102000                 mov     0, %o0
F00EF5EC: 10bffff7                 ba      loc_F00EF5C8
F00EF5F0: d0020000                 ld      [%o0], %o0
F00EF5F4: 90100018                 mov     %i0, %o0
F00EF5F8: 7fffff9c                 call    sub_F00EF468
F00EF5FC: 92102000                 mov     0, %o1
F00EF600: 81c7e008                 ret
F00EF604: 81e80000                 restore
