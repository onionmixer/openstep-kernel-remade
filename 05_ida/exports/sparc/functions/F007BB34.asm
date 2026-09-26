F007BB34: 9de3bf78                 save    %sp, -0x88, %sp
F007BB38: 90102001                 mov     1, %o0
F007BB3C: d02fbfdb                 stb     %o0, [%fp+var_25]
F007BB40: 90102020                 mov     0x20, %o0 ! ' '
F007BB44: d027bfdc                 st      %o0, [%fp+var_24]
F007BB48: d0062008                 ld      [%i0+8], %o0
F007BB4C: d027bfe0                 st      %o0, [%fp+var_20]
F007BB50: c027bfe4                 clr     [%fp+var_1C]
F007BB54: d0062010                 ld      [%i0+0x10], %o0
F007BB58: d027bfe8                 st      %o0, [%fp+var_18]
F007BB5C: d0062014                 ld      [%i0+0x14], %o0
F007BB60: 133c03d3                 sethi   %hi(dword_F00F4DE4), %o1
F007BB64: d20261e4                 ld      [%o1+%lo(dword_F00F4DE4)], %o1
F007BB68: 90022064                 inc     0x64, %o0 ! 'd'
F007BB6C: d027bfec                 st      %o0, [%fp+var_14]
F007BB70: d227bff0                 st      %o1, [%fp+var_10]
F007BB74: 90103ed1                 mov     -0x12F, %o0
F007BB78: d027bff4                 st      %o0, [%fp+var_C]
F007BB7C: d2062014                 ld      [%i0+0x14], %o1
F007BB80: 90027f9c                 add     %o1, -0x64, %o0
F007BB84: 80a2200c                 cmp     %o0, 0xC
F007BB88: 18800009                 bgu     loc_F007BBAC
F007BB8C: a007bfd8                 add     %fp, var_28, %l0
F007BB90: 113c03d390122058         set     unk_F00F4C58, %o0
F007BB98: 932a6002                 sll     %o1, 2, %o1
F007BB9C: d6024008                 ld      [%o1+%o0], %o3
F007BBA0: 80a2e000                 cmp     %o3, 0
F007BBA4: 12800004                 bne     loc_F007BBB4
F007BBA8: 90100018                 mov     %i0, %o0
F007BBAC: 10800010                 ba      locret_F007BBEC
F007BBB0: b0103ed1                 mov     -0x12F, %i0
F007BBB4: 92100010                 mov     %l0, %o1
F007BBB8: 9fc2c000                 call    %o3
F007BBBC: 94100019                 mov     %i1, %o2
F007BBC0: d007bff4                 ld      [%fp+var_C], %o0
F007BBC4: 80a23ecf                 cmp     %o0, -0x131
F007BBC8: 02800008                 be      loc_F007BBE8
F007BBCC: 90100010                 mov     %l0, %o0
F007BBD0: d4066004                 ld      [%i1+4], %o2
F007BBD4: 9238000a                 xnor    %g0, %o2, %o1
F007BBD8: 7fffa83f                 call    _msg_send
F007BBDC: 9332601f                 srl     %o1, 31, %o1
F007BBE0: 10800003                 ba      locret_F007BBEC
F007BBE4: b0100008                 mov     %o0, %i0
F007BBE8: b0102000                 mov     0, %i0
F007BBEC: 81c7e008                 ret
F007BBF0: 81e80000                 restore
