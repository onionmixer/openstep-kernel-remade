F0020F6C: 9de3bf90                 save    %sp, -0x70, %sp
F0020F70: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0020F74: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0020F78: e0022024                 ld      [%o0+0x24], %l0
F0020F7C: 40000515                 call    _getsock
F0020F80: d0040000                 ld      [%l0], %o0
F0020F84: a4920000                 orcc    %o0, %g0, %l2
F0020F88: 02800014                 be      locret_F0020FD8
F0020F8C: 9007bff4                 add     %fp, var_C, %o0
F0020F90: d2042004                 ld      [%l0+4], %o1
F0020F94: d4042008                 ld      [%l0+8], %o2
F0020F98: 400004f4                 call    _sockargs
F0020F9C: 96102008                 mov     8, %o3
F0020FA0: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0020FA4: d02a6038                 stb     %o0, [%o1+0x38]
F0020FA8: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0020FAC: d04a2038                 ldsb    [%o0+0x38], %o0
F0020FB0: 80a22000                 cmp     %o0, 0
F0020FB4: 12800009                 bne     locret_F0020FD8
F0020FB8: 01000000                 nop
F0020FBC: d004a018                 ld      [%l2+0x18], %o0
F0020FC0: 7ffff5c6                 call    _sobind
F0020FC4: d207bff4                 ld      [%fp+var_C], %o1
F0020FC8: d20461dc                 ld      [%l1+0x1DC], %o1
F0020FCC: d02a6038                 stb     %o0, [%o1+0x38]
F0020FD0: 7ffff325                 call    _m_freem
F0020FD4: d007bff4                 ld      [%fp+var_C], %o0
F0020FD8: 81c7e008                 ret
F0020FDC: 81e80000                 restore
