F007BEE8: 9de3bf98                 save    %sp, -0x68, %sp
F007BEEC: d2062004                 ld      [%i0+4], %o1
F007BEF0: 80a26040                 cmp     %o1, 0x40 ! '@'
F007BEF4: 12800005                 bne     loc_F007BF08
F007BEF8: d00e2003                 ldub    [%i0+3], %o0
F007BEFC: 80a22000                 cmp     %o0, 0
F007BF00: 22800005                 be,a    loc_F007BF14
F007BF04: d0062018                 ld      [%i0+0x18], %o0
F007BF08: 90103ed0                 mov     -0x130, %o0
F007BF0C: 1080002e                 ba      locret_F007BFC4
F007BF10: d026601c                 st      %o0, [%i1+0x1C]
F007BF14: 133c03d3                 sethi   %hi(dword_F00F4E4C), %o1
F007BF18: d202624c                 ld      [%o1+%lo(dword_F00F4E4C)], %o1
F007BF1C: 80a20009                 cmp     %o0, %o1
F007BF20: 12800021                 bne     loc_F007BFA4
F007BF24: 90103ed0                 mov     -0x130, %o0
F007BF28: d0062020                 ld      [%i0+0x20], %o0
F007BF2C: 133c03d3                 sethi   %hi(dword_F00F4E50), %o1
F007BF30: d2026250                 ld      [%o1+%lo(dword_F00F4E50)], %o1
F007BF34: 80a20009                 cmp     %o0, %o1
F007BF38: 1280001b                 bne     loc_F007BFA4
F007BF3C: 90103ed0                 mov     -0x130, %o0
F007BF40: d0062028                 ld      [%i0+0x28], %o0
F007BF44: 133c03d3                 sethi   %hi(dword_F00F4E54), %o1
F007BF48: d2026254                 ld      [%o1+%lo(dword_F00F4E54)], %o1
F007BF4C: 80a20009                 cmp     %o0, %o1
F007BF50: 12800015                 bne     loc_F007BFA4
F007BF54: 90103ed0                 mov     -0x130, %o0
F007BF58: d0062030                 ld      [%i0+0x30], %o0
F007BF5C: 133c03d3                 sethi   %hi(dword_F00F4E58), %o1
F007BF60: d2026258                 ld      [%o1+%lo(dword_F00F4E58)], %o1
F007BF64: 80a20009                 cmp     %o0, %o1
F007BF68: 1280000f                 bne     loc_F007BFA4
F007BF6C: 90103ed0                 mov     -0x130, %o0
F007BF70: d0062038                 ld      [%i0+0x38], %o0
F007BF74: 133c03d3                 sethi   %hi(dword_F00F4E5C), %o1
F007BF78: d202625c                 ld      [%o1+%lo(dword_F00F4E5C)], %o1
F007BF7C: 80a20009                 cmp     %o0, %o1
F007BF80: 12800009                 bne     loc_F007BFA4
F007BF84: 90103ed0                 mov     -0x130, %o0
F007BF88: d006200c                 ld      [%i0+0xC], %o0
F007BF8C: d206201c                 ld      [%i0+0x1C], %o1
F007BF90: d4062024                 ld      [%i0+0x24], %o2
F007BF94: d606202c                 ld      [%i0+0x2C], %o3
F007BF98: d8062034                 ld      [%i0+0x34], %o4
F007BF9C: 40001454                 call    _catch_exception_raise
F007BFA0: da06203c                 ld      [%i0+0x3C], %o5
F007BFA4: d026601c                 st      %o0, [%i1+0x1C]
F007BFA8: d006601c                 ld      [%i1+0x1C], %o0
F007BFAC: 80a22000                 cmp     %o0, 0
F007BFB0: 12800005                 bne     locret_F007BFC4
F007BFB4: 92102020                 mov     0x20, %o1 ! ' '
F007BFB8: 90102001                 mov     1, %o0
F007BFBC: d02e6003                 stb     %o0, [%i1+3]
F007BFC0: d2266004                 st      %o1, [%i1+4]
F007BFC4: 81c7e008                 ret
F007BFC8: 81e80000                 restore
