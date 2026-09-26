F00F2058: 9de3bf98                 save    %sp, -0x68, %sp
F00F205C: 7fffff2a                 call    _objc_getClass
F00F2060: d0062004                 ld      [%i0+4], %o0
F00F2064: a0920000                 orcc    %o0, %g0, %l0
F00F2068: 22800018                 be,a    loc_F00F20C8
F00F206C: 113c03f4                 sethi   -0xFF03000, %o0! Class
F00F2070: d2062008                 ld      [%i0+8], %o1
F00F2074: 80a26000                 cmp     %o1, 0
F00F2078: 22800005                 be,a    loc_F00F208C
F00F207C: d206200c                 ld      [%i0+0xC], %o1! objc_method_list *
F00F2080: 7ffff549                 call    _class_removeMethods
F00F2084: 01000000                 nop
F00F2088: d206200c                 ld      [%i0+0xC], %o1! objc_method_list *
F00F208C: 80a26000                 cmp     %o1, 0
F00F2090: 02800005                 be      loc_F00F20A4
F00F2094: 80a66004                 cmp     %i1, 4
F00F2098: 7ffff543                 call    _class_removeMethods
F00F209C: d0040000                 ld      [%l0], %o0
F00F20A0: 80a66004                 cmp     %i1, 4
F00F20A4: 04800010                 ble     locret_F00F20E4
F00F20A8: 01000000                 nop
F00F20AC: d2062010                 ld      [%i0+0x10], %o1
F00F20B0: 80a26000                 cmp     %o1, 0
F00F20B4: 0280000c                 be      locret_F00F20E4
F00F20B8: 01000000                 nop
F00F20BC: 7ffff553                 call    __class_removeProtocols
F00F20C0: 90100010                 mov     %l0, %o0
F00F20C4: 30800008                 ba,a    locret_F00F20E4
F00F20C8: 901222e8                 bset    0x2E8, %o0
F00F20CC: 7ffffa59                 call    __objc_inform
F00F20D0: d2060000                 ld      [%i0], %o1
F00F20D4: 113c03f490122310         set     aClassSNotLinke_0, %o0! "class `%s' not linked into application"...
F00F20DC: 7ffffa55                 call    __objc_inform
F00F20E0: d2062004                 ld      [%i0+4], %o1
F00F20E4: 81c7e008                 ret
F00F20E8: 81e80000                 restore
