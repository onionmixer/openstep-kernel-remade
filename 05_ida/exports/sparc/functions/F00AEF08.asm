F00AEF08: 9de3bf98                 save    %sp, -0x68, %sp
F00AEF0C: 113c000c                 sethi   %hi(_romp), %o0
F00AEF10: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEF14: 7ffd5876                 call    _montrap
F00AEF18: d0022074                 ld      [%o0+0x74], %o0
F00AEF1C: 81c7e008                 ret
F00AEF20: 81e80000                 restore
