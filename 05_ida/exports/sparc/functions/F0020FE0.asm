F0020FE0: 9de3bf98                 save    %sp, -0x68, %sp
F0020FE4: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0020FE8: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0020FEC: e0022024                 ld      [%o0+0x24], %l0
F0020FF0: 400004f8                 call    _getsock
F0020FF4: d0040000                 ld      [%l0], %o0
F0020FF8: 80a22000                 cmp     %o0, 0
F0020FFC: 02800007                 be      locret_F0021018
F0021000: 01000000                 nop
F0021004: d0022018                 ld      [%o0+0x18], %o0
F0021008: 7ffff5c5                 call    _solisten
F002100C: d2042004                 ld      [%l0+4], %o1
F0021010: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021014: d02a6038                 stb     %o0, [%o1+0x38]
F0021018: 81c7e008                 ret
F002101C: 81e80000                 restore
