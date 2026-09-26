F0025C28: 9de3bf98                 save    %sp, -0x68, %sp
F0025C2C: 7fff8603                 call    _strlen
F0025C30: 90100019                 mov     %i1, %o0
F0025C34: a0100008                 mov     %o0, %l0
F0025C38: 80a42020                 cmp     %l0, 0x20 ! ' '
F0025C3C: 14800015                 bg      locret_F0025C90
F0025C40: 92040019                 add     %l0, %i1, %o1
F0025C44: d04e4000                 ldsb    [%i1], %o0
F0025C48: d24a7fff                 ldsb    [%o1-1], %o1
F0025C4C: 90020009                 add     %o0, %o1, %o0
F0025C50: 90020010                 add     %o0, %l0, %o0
F0025C54: 90020018                 add     %o0, %i0, %o0
F0025C58: a20a203f                 and     %o0, 0x3F, %l1
F0025C5C: 90100018                 mov     %i0, %o0
F0025C60: 92100019                 mov     %i1, %o1
F0025C64: 94100010                 mov     %l0, %o2
F0025C68: 96100011                 mov     %l1, %o3
F0025C6C: 40000095                 call    sub_F0025EC0
F0025C70: 98103fff                 mov     -1, %o4
F0025C74: 80a22000                 cmp     %o0, 0
F0025C78: 02800006                 be      locret_F0025C90
F0025C7C: 01000000                 nop
F0025C80: 4000005e                 call    sub_F0025DF8
F0025C84: 01000000                 nop
F0025C88: 10bffff6                 ba      loc_F0025C60
F0025C8C: 90100018                 mov     %i0, %o0
F0025C90: 81c7e008                 ret
F0025C94: 81e80000                 restore
