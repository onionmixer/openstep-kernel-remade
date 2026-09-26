F000E8C4: 9de3bf98                 save    %sp, -0x68, %sp
F000E8C8: 133c04d1                 sethi   %hi(_pgrphash), %o1
F000E8CC: d006200c                 ld      [%i0+0xC], %o0
F000E8D0: 921263b0                 bset    %lo(_pgrphash), %o1
F000E8D4: d4062008                 ld      [%i0+8], %o2
F000E8D8: 900a203f                 and     %o0, 0x3F, %o0
F000E8DC: 912a2002                 sll     %o0, 2, %o0
F000E8E0: d402a008                 ld      [%o2+8], %o2
F000E8E4: 80a2a000                 cmp     %o2, 0
F000E8E8: 02800013                 be      loc_F000E934
F000E8EC: a0020009                 add     %o0, %o1, %l0
F000E8F0: 400031fe                 call    _ttynty
F000E8F4: 9010000a                 mov     %o2, %o0
F000E8F8: 92100008                 mov     %o0, %o1
F000E8FC: d002600c                 ld      [%o1+0xC], %o0
F000E900: 80a20018                 cmp     %o0, %i0
F000E904: 3280000d                 bne,a   loc_F000E938
F000E908: d0040000                 ld      [%l0], %o0
F000E90C: d0024000                 ld      [%o1], %o0
F000E910: c022600c                 clr     [%o1+0xC]
F000E914: 10800008                 ba      loc_F000E934
F000E918: c0322044                 clrh    [%o0+0x44]
F000E91C: 80a20018                 cmp     %o0, %i0
F000E920: 32800005                 bne,a   loc_F000E934
F000E924: a0100008                 mov     %o0, %l0
F000E928: d0060000                 ld      [%i0], %o0
F000E92C: 10800009                 ba      loc_F000E950
F000E930: d0240000                 st      %o0, [%l0]
F000E934: d0040000                 ld      [%l0], %o0
F000E938: 80a22000                 cmp     %o0, 0
F000E93C: 32bffff8                 bne,a   loc_F000E91C
F000E940: d0040000                 ld      [%l0], %o0
F000E944: 113c042c                 sethi   %hi(aPgdeleteCanTFi), %o0! "pgdelete: can't find pgrp on hash chain"
F000E948: 40001a0a                 call    _panic
F000E94C: 90122130                 bset    %lo(aPgdeleteCanTFi), %o0! "pgdelete: can't find pgrp on hash chain"
F000E950: d2062008                 ld      [%i0+8], %o1
F000E954: d0024000                 ld      [%o1], %o0
F000E958: 90023fff                 inc     -1, %o0
F000E95C: 80a22000                 cmp     %o0, 0
F000E960: 1280000d                 bne     loc_F000E994
F000E964: d0224000                 st      %o0, [%o1]
F000E968: d0062008                 ld      [%i0+8], %o0
F000E96C: d0022008                 ld      [%o0+8], %o0
F000E970: 80a22000                 cmp     %o0, 0
F000E974: 22800006                 be,a    loc_F000E98C
F000E978: d0062008                 ld      [%i0+8], %o0
F000E97C: 400031db                 call    _ttynty
F000E980: 01000000                 nop
F000E984: c0222008                 clr     [%o0+8]
F000E988: d0062008                 ld      [%i0+8], %o0
F000E98C: 40016605                 call    _kfree
F000E990: 92102010                 mov     0x10, %o1
F000E994: 90100018                 mov     %i0, %o0
F000E998: 40016602                 call    _kfree
F000E99C: 92102014                 mov     0x14, %o1
F000E9A0: 81c7e008                 ret
F000E9A4: 81e80000                 restore
