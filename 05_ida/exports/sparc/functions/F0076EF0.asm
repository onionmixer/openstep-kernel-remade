F0076EF0: 9de3bf98                 save    %sp, -0x68, %sp
F0076EF4: 40007f25                 call    _splusclock
F0076EF8: 01000000                 nop
F0076EFC: a2100008                 mov     %o0, %l1
F0076F00: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076F08: d0040000                 ld      [%l0], %o0
F0076F0C: 80a22000                 cmp     %o0, 0
F0076F10: 12bffffe                 bne     loc_F0076F08
F0076F14: 01000000                 nop
F0076F18: 40007fe4                 call    _simple_lock_try
F0076F1C: 90100010                 mov     %l0, %o0
F0076F20: 80a22000                 cmp     %o0, 0
F0076F24: 02bffff9                 be      loc_F0076F08
F0076F28: 01000000                 nop
F0076F2C: d0062020                 ld      [%i0+0x20], %o0
F0076F30: 80a22000                 cmp     %o0, 0
F0076F34: 12800016                 bne     loc_F0076F8C
F0076F38: 113c04c3                 sethi   -0xFECF400, %o0
F0076F3C: 98102000                 mov     0, %o4
F0076F40: 9a102000                 mov     0, %o5
F0076F44: d83e2018                 std     %o4, [%i0+0x18]
F0076F48: 133c04c39212632c         set     dword_F0130F2C, %o1
F0076F50: d2260000                 st      %o1, [%i0]
F0076F54: d4062010                 ld      [%i0+0x10], %o2
F0076F58: 173c04c3                 sethi   %hi(dword_F0130F3C), %o3
F0076F5C: d002e33c                 ld      [%o3+%lo(dword_F0130F3C)], %o0
F0076F60: d426200c                 st      %o2, [%i0+0xC]
F0076F64: 90022001                 inc     %o0
F0076F68: d022e33c                 st      %o0, [%o3+%lo(dword_F0130F3C)]
F0076F6C: d4026004                 ld      [%o1+4], %o2
F0076F70: 90102001                 mov     1, %o0
F0076F74: d4262004                 st      %o2, [%i0+4]
F0076F78: f0228000                 st      %i0, [%o2]
F0076F7C: f0226004                 st      %i0, [%o1+4]
F0076F80: 4000010a                 call    sub_F00773A8
F0076F84: d0262020                 st      %o0, [%i0+0x20]
F0076F88: 30800002                 ba,a    loc_F0076F90
F0076F8C: c0222320                 clr     [%o0+0x320]
F0076F90: 40007f65                 call    _splx
F0076F94: 90100011                 mov     %l1, %o0
F0076F98: 81c7e008                 ret
F0076F9C: 81e80000                 restore
