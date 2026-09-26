F00E2EEC: 9de3bf98                 save    %sp, -0x68, %sp
F00E2EF0: d2062004                 ld      [%i0+4], %o1
F00E2EF4: 80a26030                 cmp     %o1, 0x30 ! '0'
F00E2EF8: 12800005                 bne     loc_F00E2F0C
F00E2EFC: d00e2003                 ldub    [%i0+3], %o0
F00E2F00: 80a22000                 cmp     %o0, 0
F00E2F04: 22800005                 be,a    loc_F00E2F18
F00E2F08: d0062018                 ld      [%i0+0x18], %o0
F00E2F0C: 90103ed0                 mov     -0x130, %o0
F00E2F10: 10800024                 ba      locret_F00E2FA0
F00E2F14: d026601c                 st      %o0, [%i1+0x1C]
F00E2F18: 133c03e6                 sethi   %hi(dword_F00F99CC), %o1
F00E2F1C: d20261cc                 ld      [%o1+%lo(dword_F00F99CC)], %o1
F00E2F20: 80a20009                 cmp     %o0, %o1
F00E2F24: 12800014                 bne     loc_F00E2F74
F00E2F28: 90103ed0                 mov     -0x130, %o0
F00E2F2C: d0062020                 ld      [%i0+0x20], %o0
F00E2F30: 133c03e6                 sethi   %hi(dword_F00F99D0), %o1
F00E2F34: d20261d0                 ld      [%o1+%lo(dword_F00F99D0)], %o1
F00E2F38: 80a20009                 cmp     %o0, %o1
F00E2F3C: 1280000e                 bne     loc_F00E2F74
F00E2F40: 90103ed0                 mov     -0x130, %o0
F00E2F44: d0062028                 ld      [%i0+0x28], %o0
F00E2F48: 133c03e6                 sethi   %hi(dword_F00F99D4), %o1
F00E2F4C: d20261d4                 ld      [%o1+%lo(dword_F00F99D4)], %o1
F00E2F50: 80a20009                 cmp     %o0, %o1
F00E2F54: 12800008                 bne     loc_F00E2F74
F00E2F58: 90103ed0                 mov     -0x130, %o0
F00E2F5C: d006200c                 ld      [%i0+0xC], %o0
F00E2F60: d206201c                 ld      [%i0+0x1C], %o1
F00E2F64: d4062024                 ld      [%i0+0x24], %o2
F00E2F68: d606202c                 ld      [%i0+0x2C], %o3
F00E2F6C: 7fffc989                 call    _EvMapEventShmem
F00E2F70: 98066024                 add     %i1, 0x24, %o4 ! '$'
F00E2F74: d026601c                 st      %o0, [%i1+0x1C]
F00E2F78: d006601c                 ld      [%i1+0x1C], %o0
F00E2F7C: 80a22000                 cmp     %o0, 0
F00E2F80: 12800008                 bne     locret_F00E2FA0
F00E2F84: 92102028                 mov     0x28, %o1 ! '('
F00E2F88: 90102001                 mov     1, %o0
F00E2F8C: d02e6003                 stb     %o0, [%i1+3]
F00E2F90: 113c03e6                 sethi   %hi(dword_F00F99D8), %o0
F00E2F94: d00221d8                 ld      [%o0+%lo(dword_F00F99D8)], %o0
F00E2F98: d2266004                 st      %o1, [%i1+4]
F00E2F9C: d0266020                 st      %o0, [%i1+0x20]
F00E2FA0: 81c7e008                 ret
F00E2FA4: 81e80000                 restore
