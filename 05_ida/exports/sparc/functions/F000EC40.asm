F000EC40: 9de3bf98                 save    %sp, -0x68, %sp
F000EC44: a0100018                 mov     %i0, %l0
F000EC48: 920c203f                 and     %l0, 0x3F, %o1
F000EC4C: 113c04d2901220b0         set     _posix_proc_hash, %o0
F000EC54: 932a6002                 sll     %o1, 2, %o1
F000EC58: f0024008                 ld      [%o1+%o0], %i0
F000EC5C: 80a62000                 cmp     %i0, 0
F000EC60: 0280000b                 be      loc_F000EC8C
F000EC64: 01000000                 nop
F000EC68: d0060000                 ld      [%i0], %o0
F000EC6C: 80a20010                 cmp     %o0, %l0
F000EC70: 32800004                 bne,a   loc_F000EC80
F000EC74: f006201c                 ld      [%i0+0x1C], %i0
F000EC78: 10800010                 ba      locret_F000ECB8
F000EC7C: b0102000                 mov     0, %i0
F000EC80: 80a62000                 cmp     %i0, 0
F000EC84: 32bffffa                 bne,a   loc_F000EC6C
F000EC88: d0060000                 ld      [%i0], %o0
F000EC8C: 400164f9                 call    _kalloc
F000EC90: 90102020                 mov     0x20, %o0 ! ' '
F000EC94: b0100008                 mov     %o0, %i0
F000EC98: e0260000                 st      %l0, [%i0]
F000EC9C: 900c203f                 and     %l0, 0x3F, %o0
F000ECA0: 133c04d2921260b0         set     _posix_proc_hash, %o1
F000ECA8: 912a2002                 sll     %o0, 2, %o0
F000ECAC: d4020009                 ld      [%o0+%o1], %o2
F000ECB0: d426201c                 st      %o2, [%i0+0x1C]
F000ECB4: f0220009                 st      %i0, [%o0+%o1]
F000ECB8: 81c7e008                 ret
F000ECBC: 81e80000                 restore
