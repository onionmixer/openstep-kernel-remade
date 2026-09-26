F006D8E8: 9de3bf98                 save    %sp, -0x68, %sp
F006D8EC: d2062038                 ld      [%i0+0x38], %o1
F006D8F0: 11100000                 sethi   0x40000000, %o0
F006D8F4: e2062024                 ld      [%i0+0x24], %l1
F006D8F8: 902a4008                 andn    %o1, %o0, %o0
F006D8FC: 80a46000                 cmp     %l1, 0
F006D900: 028000a3                 be      locret_F006DB8C
F006D904: d0262038                 st      %o0, [%i0+0x38]
F006D908: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F006D910: d0040000                 ld      [%l0], %o0
F006D914: 80a22000                 cmp     %o0, 0
F006D918: 12bffffe                 bne     loc_F006D910
F006D91C: 01000000                 nop
F006D920: 4000a562                 call    _simple_lock_try
F006D924: 90100010                 mov     %l0, %o0
F006D928: 80a22000                 cmp     %o0, 0
F006D92C: 02bffff9                 be      loc_F006D910
F006D930: 01000000                 nop
F006D934: a0046010                 add     %l1, 0x10, %l0
F006D938: d0040000                 ld      [%l0], %o0
F006D93C: 80a22000                 cmp     %o0, 0
F006D940: 12bffffe                 bne     loc_F006D938
F006D944: 01000000                 nop
F006D948: 4000a558                 call    _simple_lock_try
F006D94C: 90100010                 mov     %l0, %o0
F006D950: 80a22000                 cmp     %o0, 0
F006D954: 02bffff9                 be      loc_F006D938
F006D958: 01000000                 nop
F006D95C: e0044000                 ld      [%l1], %l0
F006D960: 80a44010                 cmp     %l1, %l0
F006D964: 02800087                 be      loc_F006DB80
F006D968: 113fffdf                 sethi   -0x8400, %o0
F006D96C: 2d200000                 sethi   0x80000000, %l6
F006D970: 2f100000                 sethi   0x40000000, %l7
F006D974: 273c04f0                 sethi   -0xFEC4000, %l3
F006D978: 333c04f0a8166228         set     _vm_page_queue_inactive, %l4
F006D980: b41223ff                 or      %o0, 0x3FF, %i2
F006D984: 111fffffaa1223ff         set     0x7FFFFFFF, %l5
F006D98C: d2042020                 ld      [%l0+0x20], %o1
F006D990: 91326014                 srl     %o1, 20, %o0
F006D994: 808a2001                 btst    1, %o0
F006D998: 32800077                 bne,a   loc_F006DB74
F006D99C: e0042008                 ld      [%l0+8], %l0
F006D9A0: 808a4016                 btst    %l6, %o1
F006D9A4: 02800021                 be      loc_F006DA28
F006D9A8: 90124017                 or      %o1, %l7, %o0
F006D9AC: d0242020                 st      %o0, [%l0+0x20]
F006D9B0: 90100010                 mov     %l0, %o0
F006D9B4: 40000cc8                 call    _assert_wait
F006D9B8: 92102000                 mov     0, %o1
F006D9BC: c0246010                 clr     [%l1+0x10]
F006D9C0: c024e230                 clr     [%l3+0x230]
F006D9C4: 4000133f                 call    _thread_block
F006D9C8: a014e230                 or      %l3, 0x230, %l0
F006D9CC: d0040000                 ld      [%l0], %o0
F006D9D0: 80a22000                 cmp     %o0, 0
F006D9D4: 12bffffe                 bne     loc_F006D9CC
F006D9D8: 01000000                 nop
F006D9DC: 4000a533                 call    _simple_lock_try
F006D9E0: 90100010                 mov     %l0, %o0
F006D9E4: 80a22000                 cmp     %o0, 0
F006D9E8: 02bffff9                 be      loc_F006D9CC
F006D9EC: 01000000                 nop
F006D9F0: b0046010                 add     %l1, 0x10, %i0
F006D9F4: d0060000                 ld      [%i0], %o0
F006D9F8: 80a22000                 cmp     %o0, 0
F006D9FC: 12bffffe                 bne     loc_F006D9F4
F006DA00: 01000000                 nop
F006DA04: 4000a529                 call    _simple_lock_try
F006DA08: 90100018                 mov     %i0, %o0
F006DA0C: 80a22000                 cmp     %o0, 0
F006DA10: 02bffff9                 be      loc_F006D9F4
F006DA14: 01000000                 nop
F006DA18: 10bfffd2                 ba      loc_F006D960
F006DA1C: e0044000                 ld      [%l1], %l0
F006DA20: 10800011                 ba      loc_F006DA64
F006DA24: d0266228                 st      %o0, [%i1+0x228]
F006DA28: d204201c                 ld      [%l0+0x1C], %o1
F006DA2C: 11000010                 sethi   0x4000, %o0
F006DA30: 808a4008                 btst    %o0, %o1
F006DA34: 12800004                 bne     loc_F006DA44
F006DA38: 01000000                 nop
F006DA3C: 40006f6a                 call    _vm_page_activate
F006DA40: 90100010                 mov     %l0, %o0
F006DA44: 40006f26                 call    _vm_page_deactivate
F006DA48: 90100010                 mov     %l0, %o0
F006DA4C: d0040000                 ld      [%l0], %o0
F006DA50: d2042004                 ld      [%l0+4], %o1
F006DA54: 80a24014                 cmp     %o1, %l4
F006DA58: 02bffff2                 be      loc_F006DA20
F006DA5C: d2222004                 st      %o1, [%o0+4]
F006DA60: d0224000                 st      %o0, [%o1]
F006DA64: d004201c                 ld      [%l0+0x1C], %o0
F006DA68: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F006DA6C: d202a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o1
F006DA70: 900a001a                 and     %o0, %i2, %o0
F006DA74: d024201c                 st      %o0, [%l0+0x1C]
F006DA78: 92027fff                 inc     -1, %o1
F006DA7C: d0042020                 ld      [%l0+0x20], %o0
F006DA80: d222a220                 st      %o1, [%o2+%lo(_vm_page_inactive_count)]
F006DA84: d204201c                 ld      [%l0+0x1C], %o1
F006DA88: 90120016                 bset    %l6, %o0
F006DA8C: d0242020                 st      %o0, [%l0+0x20]
F006DA90: 11000008                 sethi   0x2000, %o0
F006DA94: 808a4008                 btst    %o0, %o1
F006DA98: 02800028                 be      loc_F006DB38
F006DA9C: 01000000                 nop
F006DAA0: d0042024                 ld      [%l0+0x24], %o0
F006DAA4: 4000bf55                 call    _pmap_remove_all
F006DAA8: b014e230                 or      %l3, 0x230, %i0
F006DAAC: c0246010                 clr     [%l1+0x10]
F006DAB0: d2146044                 lduh    [%l1+0x44], %o1
F006DAB4: 92026001                 inc     %o1
F006DAB8: d2346044                 sth     %o1, [%l1+0x44]
F006DABC: c024e230                 clr     [%l3+0x230]
F006DAC0: 40007704                 call    _vnode_pageout
F006DAC4: 90100010                 mov     %l0, %o0
F006DAC8: a4100008                 mov     %o0, %l2
F006DACC: d0060000                 ld      [%i0], %o0
F006DAD0: 80a22000                 cmp     %o0, 0
F006DAD4: 12bffffe                 bne     loc_F006DACC
F006DAD8: 01000000                 nop
F006DADC: 4000a4f3                 call    _simple_lock_try
F006DAE0: 90100018                 mov     %i0, %o0
F006DAE4: 80a22000                 cmp     %o0, 0
F006DAE8: 02bffff9                 be      loc_F006DACC
F006DAEC: 01000000                 nop
F006DAF0: b0046010                 add     %l1, 0x10, %i0
F006DAF4: d0060000                 ld      [%i0], %o0
F006DAF8: 80a22000                 cmp     %o0, 0
F006DAFC: 12bffffe                 bne     loc_F006DAF4
F006DB00: 01000000                 nop
F006DB04: 4000a4e9                 call    _simple_lock_try
F006DB08: 90100018                 mov     %i0, %o0
F006DB0C: 80a22000                 cmp     %o0, 0
F006DB10: 02bffff9                 be      loc_F006DAF4
F006DB14: 80a4a000                 cmp     %l2, 0
F006DB18: d0146044                 lduh    [%l1+0x44], %o0
F006DB1C: 90023fff                 inc     -1, %o0
F006DB20: 12800006                 bne     loc_F006DB38
F006DB24: d0346044                 sth     %o0, [%l1+0x44]
F006DB28: d204201c                 ld      [%l0+0x1C], %o1
F006DB2C: 11000008                 sethi   0x2000, %o0
F006DB30: 902a4008                 andn    %o1, %o0, %o0
F006DB34: d024201c                 st      %o0, [%l0+0x1C]
F006DB38: 40006f2b                 call    _vm_page_activate
F006DB3C: 90100010                 mov     %l0, %o0
F006DB40: d0042020                 ld      [%l0+0x20], %o0
F006DB44: 920a0015                 and     %o0, %l5, %o1
F006DB48: 808a4017                 btst    %l7, %o1
F006DB4C: 02800009                 be      loc_F006DB70
F006DB50: d2242020                 st      %o1, [%l0+0x20]
F006DB54: 11100000                 sethi   0x40000000, %o0
F006DB58: 902a4008                 andn    %o1, %o0, %o0
F006DB5C: d0242020                 st      %o0, [%l0+0x20]
F006DB60: 90100010                 mov     %l0, %o0
F006DB64: 92102000                 mov     0, %o1
F006DB68: 40000d25                 call    _thread_wakeup_prim
F006DB6C: 94102000                 mov     0, %o2
F006DB70: e0042008                 ld      [%l0+8], %l0
F006DB74: 80a44010                 cmp     %l1, %l0
F006DB78: 32bfff86                 bne,a   loc_F006D990
F006DB7C: d2042020                 ld      [%l0+0x20], %o1
F006DB80: c0246010                 clr     [%l1+0x10]
F006DB84: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006DB88: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F006DB8C: 81c7e008                 ret
F006DB90: 81e80000                 restore
