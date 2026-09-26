F0070E30: 9de3bf98                 save    %sp, -0x68, %sp
F0070E34: 40009755                 call    _splusclock
F0070E38: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0070E3C: a4100008                 mov     %o0, %l2
F0070E40: d0040000                 ld      [%l0], %o0
F0070E44: 80a22000                 cmp     %o0, 0
F0070E48: 12bffffe                 bne     loc_F0070E40
F0070E4C: 01000000                 nop
F0070E50: 40009816                 call    _simple_lock_try
F0070E54: 90100010                 mov     %l0, %o0
F0070E58: 80a22000                 cmp     %o0, 0
F0070E5C: 02bffff9                 be      loc_F0070E40
F0070E60: 80a6a000                 cmp     %i2, 0
F0070E64: 22800007                 be,a    loc_F0070E80
F0070E68: e206203c                 ld      [%i0+0x3C], %l1
F0070E6C: d006204c                 ld      [%i0+0x4C], %o0
F0070E70: 808a2008                 btst    8, %o0
F0070E74: 1280005d                 bne     def_F0070F78! jumptable F0070F78 default case, cases 1,3,5,7,9,11,13
F0070E78: 01000000                 nop
F0070E7C: e206203c                 ld      [%i0+0x3C], %l1
F0070E80: 80a46000                 cmp     %l1, 0
F0070E84: 0280002d                 be      loc_F0070F38
F0070E88: 01000000                 nop
F0070E8C: c0262020                 clr     [%i0+0x20]
F0070E90: 80a46000                 cmp     %l1, 0
F0070E94: 16800003                 bge     loc_F0070EA0
F0070E98: 90100011                 mov     %l1, %o0
F0070E9C: 90380011                 xnor    %g0, %l1, %o0
F0070EA0: 7ffe5682                 call    _rem
F0070EA4: 9210203b                 mov     0x3B, %o1 ! ';'
F0070EA8: 932a2002                 sll     %o0, 2, %o1
F0070EAC: 113c04f190122290         set     _wait_lock, %o0
F0070EB4: b4024008                 add     %o1, %o0, %i2
F0070EB8: d0068000                 ld      [%i2], %o0
F0070EBC: 80a22000                 cmp     %o0, 0
F0070EC0: 12bffffe                 bne     loc_F0070EB8
F0070EC4: 01000000                 nop
F0070EC8: 400097f8                 call    _simple_lock_try
F0070ECC: 9010001a                 mov     %i2, %o0
F0070ED0: 80a22000                 cmp     %o0, 0
F0070ED4: 02bffff9                 be      loc_F0070EB8
F0070ED8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0070EDC: d0040000                 ld      [%l0], %o0
F0070EE0: 80a22000                 cmp     %o0, 0
F0070EE4: 12bffffe                 bne     loc_F0070EDC
F0070EE8: 01000000                 nop
F0070EEC: 400097ef                 call    _simple_lock_try
F0070EF0: 90100010                 mov     %l0, %o0
F0070EF4: 80a22000                 cmp     %o0, 0
F0070EF8: 02bffff9                 be      loc_F0070EDC
F0070EFC: 01000000                 nop
F0070F00: d006203c                 ld      [%i0+0x3C], %o0
F0070F04: 80a20011                 cmp     %o0, %l1
F0070F08: 1280000a                 bne     loc_F0070F30
F0070F0C: 01000000                 nop
F0070F10: d2060000                 ld      [%i0], %o1
F0070F14: d0062004                 ld      [%i0+4], %o0
F0070F18: d0226004                 st      %o0, [%o1+4]
F0070F1C: d2062004                 ld      [%i0+4], %o1
F0070F20: d0060000                 ld      [%i0], %o0
F0070F24: a2102000                 mov     0, %l1
F0070F28: d0224000                 st      %o0, [%o1]
F0070F2C: c026203c                 clr     [%i0+0x3C]
F0070F30: c0268000                 clr     [%i2]
F0070F34: 80a46000                 cmp     %l1, 0
F0070F38: 1280002c                 bne     def_F0070F78! jumptable F0070F78 default case, cases 1,3,5,7,9,11,13
F0070F3C: 01000000                 nop
F0070F40: d006214c                 ld      [%i0+0x14C], %o0
F0070F44: 80a22000                 cmp     %o0, 0
F0070F48: 02800004                 be      loc_F0070F58
F0070F4C: e006204c                 ld      [%i0+0x4C], %l0
F0070F50: 7fffe2c1                 call    _reset_timeout
F0070F54: 90062118                 add     %i0, 0x118, %o0
F0070F58: 900c200f                 and     %l0, 0xF, %o0
F0070F5C: 92023fff                 add     %o0, -1, %o1
F0070F60: 80a2600e                 cmp     %o1, 0xE! switch 15 cases
F0070F64: 18800021                 bgu     def_F0070F78! jumptable F0070F78 default case, cases 1,3,5,7,9,11,13
F0070F68: 113c01c3                 sethi   %hi(jpt_F0070F78), %o0
F0070F6C: 90122380                 bset    %lo(jpt_F0070F78), %o0
F0070F70: 932a6002                 sll     %o1, 2, %o1
F0070F74: d0024008                 ld      [%o1+%o0], %o0
F0070F78: 81c20000                 jmp     %o0! switch jump
F0070F7C: 01000000                 nop
F0070FBC: 900c3ffe                 and     %l0, -2, %o0! jumptable F0070F78 cases 0,8,10
F0070FC0: 90122004                 bset    4, %o0
F0070FC4: d026204c                 st      %o0, [%i0+0x4C]
F0070FC8: f2262044                 st      %i1, [%i0+0x44]
F0070FCC: 90100018                 mov     %i0, %o0
F0070FD0: 40000334                 call    _thread_setrun
F0070FD4: 92102001                 mov     1, %o1
F0070FD8: 30800004                 ba,a    def_F0070F78! jumptable F0070F78 default case, cases 1,3,5,7,9,11,13
F0070FDC: 900c3ffe                 and     %l0, -2, %o0! jumptable F0070F78 cases 2,4,6,12,14
F0070FE0: d026204c                 st      %o0, [%i0+0x4C]
F0070FE4: f2262044                 st      %i1, [%i0+0x44]
F0070FE8: c0262020                 clr     [%i0+0x20]! jumptable F0070F78 default case, cases 1,3,5,7,9,11,13
F0070FEC: 4000974e                 call    _splx
F0070FF0: 90100012                 mov     %l2, %o0
F0070FF4: 81c7e008                 ret
F0070FF8: 81e80000                 restore
