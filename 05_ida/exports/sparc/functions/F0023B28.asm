F0023B28: 9de3bf58                 save    %sp, -0xA8, %sp! int
F0023B2C: a007bfb8                 add     %fp, var_48, %l0
F0023B30: 90100010                 mov     %l0, %o0! void *
F0023B34: 4001c4c9                 call    _bzero
F0023B38: 92102040                 mov     0x40, %o1 ! '@'
F0023B3C: d2062004                 ld      [%i0+4], %o1
F0023B40: d402600c                 ld      [%o1+0xC], %o2! int
F0023B44: 90100018                 mov     %i0, %o0
F0023B48: 9fc28000                 call    %o2
F0023B4C: 92100010                 mov     %l0, %o1
F0023B50: 313c04cf                 sethi   %hi(dword_F0133DDC), %i0
F0023B54: d20621dc                 ld      [%i0+%lo(dword_F0133DDC)], %o1
F0023B58: d02a6038                 stb     %o0, [%o1+0x38]
F0023B5C: d00621dc                 ld      [%i0+%lo(dword_F0133DDC)], %o0
F0023B60: d04a2038                 ldsb    [%o0+0x38], %o0
F0023B64: 80a22000                 cmp     %o0, 0
F0023B68: 12800007                 bne     locret_F0023B84
F0023B6C: 90100010                 mov     %l0, %o0! int
F0023B70: 92100019                 mov     %i1, %o1! int
F0023B74: 4001d156                 call    _copyout
F0023B78: 94102040                 mov     0x40, %o2 ! '@'
F0023B7C: d20621dc                 ld      [%i0+%lo(dword_F0133DDC)], %o1
F0023B80: d02a6038                 stb     %o0, [%o1+0x38]
F0023B84: 81c7e008                 ret
F0023B88: 81e80000                 restore
