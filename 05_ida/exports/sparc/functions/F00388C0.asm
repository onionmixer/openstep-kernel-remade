F00388C0: 9de3bf98                 save    %sp, -0x68, %sp
F00388C4: d006201c                 ld      [%i0+0x1C], %o0
F00388C8: 7fff9ed1                 call    _sowakeup
F00388CC: 92022024                 add     %o0, 0x24, %o1 ! '$'
F00388D0: d006201c                 ld      [%i0+0x1C], %o0
F00388D4: 7fff9ece                 call    _sowakeup
F00388D8: 9202203c                 add     %o0, 0x3C, %o1 ! '<'
F00388DC: 81c7e008                 ret
F00388E0: 81e80000                 restore
