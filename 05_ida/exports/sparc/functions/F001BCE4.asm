F001BCE4: 9de3bf98                 save    %sp, -0x68, %sp
F001BCE8: b00e20ff                 and     %i0, 0xFF, %i0
F001BCEC: b12e2004                 sll     %i0, 4, %i0
F001BCF0: 113c04bc90122204         set     unk_F012F204, %o0
F001BCF8: b0060008                 add     %i0, %o0, %i0
F001BCFC: e0062008                 ld      [%i0+8], %l0
F001BD00: d0042040                 ld      [%l0+0x40], %o0
F001BD04: 808a2010                 btst    0x10, %o0
F001BD08: 0280001e                 be      loc_F001BD80
F001BD0C: f006200c                 ld      [%i0+0xC], %i0
F001BD10: 80a66001                 cmp     %i1, 1
F001BD14: 0280000d                 be      loc_F001BD48
F001BD18: 01000000                 nop
F001BD1C: 14800007                 bg      loc_F001BD38
F001BD20: 80a66002                 cmp     %i1, 2
F001BD24: 80a66000                 cmp     %i1, 0
F001BD28: 0280001c                 be      loc_F001BD98
F001BD2C: 808a2004                 btst    4, %o0
F001BD30: 10800050                 ba      locret_F001BE70
F001BD34: b0102000                 mov     0, %i0
F001BD38: 02800031                 be      loc_F001BDFC
F001BD3C: 808a2004                 btst    4, %o0
F001BD40: 1080004c                 ba      locret_F001BE70
F001BD44: b0102000                 mov     0, %i0
F001BD48: 4001eb9c                 call    _spltty
F001BD4C: 01000000                 nop
F001BD50: d2042040                 ld      [%l0+0x40], %o1
F001BD54: 808a6004                 btst    4, %o1
F001BD58: 0280000c                 be      loc_F001BD88
F001BD5C: 94100008                 mov     %o0, %o2
F001BD60: d0042018                 ld      [%l0+0x18], %o0
F001BD64: 80a22000                 cmp     %o0, 0
F001BD68: 02800008                 be      loc_F001BD88
F001BD6C: 808a6100                 btst    0x100, %o1
F001BD70: 12800006                 bne     loc_F001BD88
F001BD74: 01000000                 nop
F001BD78: 4001ebeb                 call    _splx
F001BD7C: 9010000a                 mov     %o2, %o0
F001BD80: 1080003c                 ba      locret_F001BE70
F001BD84: b0102001                 mov     1, %i0
F001BD88: 4001ebe7                 call    _splx
F001BD8C: 9010000a                 mov     %o2, %o0
F001BD90: d0042040                 ld      [%l0+0x40], %o0
F001BD94: 808a2004                 btst    4, %o0
F001BD98: 02800011                 be      loc_F001BDDC
F001BD9C: 01000000                 nop
F001BDA0: d2060000                 ld      [%i0], %o1
F001BDA4: 808a6008                 btst    8, %o1
F001BDA8: 02800007                 be      loc_F001BDC4
F001BDAC: 808a6080                 btst    0x80, %o1
F001BDB0: d00e200c                 ldub    [%i0+0xC], %o0
F001BDB4: 80a22000                 cmp     %o0, 0
F001BDB8: 3280002e                 bne,a   locret_F001BE70
F001BDBC: b0102001                 mov     1, %i0
F001BDC0: 808a6080                 btst    0x80, %o1
F001BDC4: 02800006                 be      loc_F001BDDC
F001BDC8: 01000000                 nop
F001BDCC: d00e200d                 ldub    [%i0+0xD], %o0
F001BDD0: 80a22000                 cmp     %o0, 0
F001BDD4: 32800027                 bne,a   locret_F001BE70
F001BDD8: b0102001                 mov     1, %i0
F001BDDC: 7fffe899                 call    _selthreadcache
F001BDE0: 90062004                 add     %i0, 4, %o0
F001BDE4: 80a22000                 cmp     %o0, 0
F001BDE8: 22800022                 be,a    locret_F001BE70
F001BDEC: b0102000                 mov     0, %i0
F001BDF0: d0060000                 ld      [%i0], %o0
F001BDF4: 1080001d                 ba      loc_F001BE68
F001BDF8: 90122001                 bset    1, %o0
F001BDFC: 02800014                 be      loc_F001BE4C
F001BE00: 01000000                 nop
F001BE04: d0060000                 ld      [%i0], %o0
F001BE08: 808a2020                 btst    0x20, %o0 ! ' '
F001BE0C: 22800005                 be,a    loc_F001BE20
F001BE10: d0040000                 ld      [%l0], %o0
F001BE14: d004200c                 ld      [%l0+0xC], %o0
F001BE18: 1080000b                 ba      loc_F001BE44
F001BE1C: 80a22000                 cmp     %o0, 0
F001BE20: d204200c                 ld      [%l0+0xC], %o1
F001BE24: 90020009                 add     %o0, %o1, %o0
F001BE28: 80a223fd                 cmp     %o0, 0x3FD
F001BE2C: 04bfffd5                 ble     loc_F001BD80
F001BE30: 80a26000                 cmp     %o1, 0
F001BE34: 12800006                 bne     loc_F001BE4C
F001BE38: 01000000                 nop
F001BE3C: d004203c                 ld      [%l0+0x3C], %o0
F001BE40: 808a2022                 btst    0x22, %o0 ! '"'
F001BE44: 2280000b                 be,a    locret_F001BE70
F001BE48: b0102001                 mov     1, %i0
F001BE4C: 7fffe87d                 call    _selthreadcache
F001BE50: 90062008                 add     %i0, 8, %o0
F001BE54: 80a22000                 cmp     %o0, 0
F001BE58: 22800006                 be,a    locret_F001BE70
F001BE5C: b0102000                 mov     0, %i0
F001BE60: d0060000                 ld      [%i0], %o0
F001BE64: 90122002                 bset    2, %o0
F001BE68: d0260000                 st      %o0, [%i0]
F001BE6C: b0102000                 mov     0, %i0
F001BE70: 81c7e008                 ret
F001BE74: 81e80000                 restore
