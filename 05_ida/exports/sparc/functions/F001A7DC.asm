F001A7DC: 9de3bf98                 save    %sp, -0x68, %sp
F001A7E0: 90100018                 mov     %i0, %o0
F001A7E4: d2022024                 ld      [%o0+0x24], %o1
F001A7E8: 80a26000                 cmp     %o1, 0
F001A7EC: 02800004                 be      locret_F001A7FC
F001A7F0: 01000000                 nop
F001A7F4: 9fc24000                 call    %o1
F001A7F8: 01000000                 nop
F001A7FC: 81c7e008                 ret
F001A800: 81e80000                 restore
