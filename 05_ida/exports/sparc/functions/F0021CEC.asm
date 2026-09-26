F0021CEC: 9de3bf98                 save    %sp, -0x68, %sp
F0021CF0: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0021CF4: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0021CF8: e0022024                 ld      [%o0+0x24], %l0
F0021CFC: 400001b5                 call    _getsock
F0021D00: d0040000                 ld      [%l0], %o0
F0021D04: 80a22000                 cmp     %o0, 0
F0021D08: 02800007                 be      locret_F0021D24
F0021D0C: 01000000                 nop
F0021D10: d0022018                 ld      [%o0+0x18], %o0
F0021D14: 7ffff704                 call    _soshutdown
F0021D18: d2042004                 ld      [%l0+4], %o1
F0021D1C: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021D20: d02a6038                 stb     %o0, [%o1+0x38]
F0021D24: 81c7e008                 ret
F0021D28: 81e80000                 restore
