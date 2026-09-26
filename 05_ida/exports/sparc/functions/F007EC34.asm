F007EC34: 9de3bf98                 save    %sp, -0x68, %sp
F007EC38: d0062004                 ld      [%i0+4], %o0
F007EC3C: 80a22018                 cmp     %o0, 0x18
F007EC40: 12800007                 bne     loc_F007EC5C
F007EC44: 90103ed0                 mov     -0x130, %o0
F007EC48: d0060000                 ld      [%i0], %o0
F007EC4C: 80a22000                 cmp     %o0, 0
F007EC50: 36800005                 bge,a   loc_F007EC64
F007EC54: d0062008                 ld      [%i0+8], %o0
F007EC58: 90103ed0                 mov     -0x130, %o0
F007EC5C: 1080000c                 ba      locret_F007EC8C
F007EC60: d026601c                 st      %o0, [%i1+0x1C]
F007EC64: 7fffb485                 call    _xxx_host_info
F007EC68: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007EC6C: 80a22000                 cmp     %o0, 0
F007EC70: 12800007                 bne     locret_F007EC8C
F007EC74: d026601c                 st      %o0, [%i1+0x1C]
F007EC78: 90102038                 mov     0x38, %o0 ! '8'
F007EC7C: d0266004                 st      %o0, [%i1+4]
F007EC80: 113c0444                 sethi   %hi(dword_F01113A0), %o0
F007EC84: d00223a0                 ld      [%o0+%lo(dword_F01113A0)], %o0
F007EC88: d0266020                 st      %o0, [%i1+0x20]
F007EC8C: 81c7e008                 ret
F007EC90: 81e80000                 restore
