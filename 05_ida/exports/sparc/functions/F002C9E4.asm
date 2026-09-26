F002C9E4: 9de3bf98                 save    %sp, -0x68, %sp
F002C9E8: a2100018                 mov     %i0, %l1
F002C9EC: b0102000                 mov     0, %i0
F002C9F0: 80a6600b                 cmp     %i1, 0xB
F002C9F4: 12800004                 bne     loc_F002CA04
F002C9F8: e0046008                 ld      [%l1+8], %l0
F002C9FC: 10800095                 ba      locret_F002CC50! jumptable F002CA54 cases 8,13
F002CA00: b010202d                 mov     0x2D, %i0 ! '-'
F002CA04: 80a72000                 cmp     %i4, 0
F002CA08: 02800008                 be      loc_F002CA28
F002CA0C: 80a42000                 cmp     %l0, 0
F002CA10: d0572008                 ldsh    [%i4+8], %o0
F002CA14: 80a22000                 cmp     %o0, 0
F002CA18: 02800004                 be      loc_F002CA28
F002CA1C: 80a42000                 cmp     %l0, 0
F002CA20: 10800087                 ba      loc_F002CC3C! jumptable F002CA54 cases 3,5,14,17
F002CA24: b010202d                 mov     0x2D, %i0 ! '-'
F002CA28: 12800006                 bne     loc_F002CA40
F002CA2C: 80a66011                 cmp     %i1, 0x11
F002CA30: 80a66000                 cmp     %i1, 0
F002CA34: 32800082                 bne,a   loc_F002CC3C
F002CA38: b0102016                 mov     0x16, %i0
F002CA3C: 80a66011                 cmp     %i1, 0x11! switch 18 cases
F002CA40: 1880007c                 bgu     def_F002CA54! jumptable F002CA54 default case, case 11
F002CA44: 932e6002                 sll     %i1, 2, %o1
F002CA48: 113c00b29012225c         set     jpt_F002CA54, %o0
F002CA50: d0024008                 ld      [%o1+%o0], %o0
F002CA54: 81c20000                 jmp     %o0! switch jump
F002CA58: 01000000                 nop
F002CAA4: d0146006                 lduh    [%l1+6], %o0! jumptable F002CA54 case 0
F002CAA8: 808a2080                 btst    0x80, %o0
F002CAAC: 12800004                 bne     loc_F002CABC
F002CAB0: 80a42000                 cmp     %l0, 0
F002CAB4: 10800062                 ba      loc_F002CC3C
F002CAB8: b010200d                 mov     0xD, %i0
F002CABC: 12800060                 bne     loc_F002CC3C
F002CAC0: b0102016                 mov     0x16, %i0
F002CAC4: 90100011                 mov     %l1, %o0
F002CAC8: 7ffffe62                 call    _raw_attach
F002CACC: 9210001b                 mov     %i3, %o1
F002CAD0: 1080005b                 ba      loc_F002CC3C
F002CAD4: b0100008                 mov     %o0, %i0
F002CAD8: 80a42000                 cmp     %l0, 0! jumptable F002CA54 case 1
F002CADC: 22800058                 be,a    loc_F002CC3C
F002CAE0: b0102039                 mov     0x39, %i0 ! '9'
F002CAE4: 7ffffe88                 call    _raw_detach
F002CAE8: 90100010                 mov     %l0, %o0
F002CAEC: 10800055                 ba      loc_F002CC40
F002CAF0: 80a6a000                 cmp     %i2, 0
F002CAF4: d014204c                 lduh    [%l0+0x4C], %o0! jumptable F002CA54 case 4
F002CAF8: 808a2002                 btst    2, %o0
F002CAFC: 32800050                 bne,a   loc_F002CC3C
F002CB00: b0102038                 mov     0x38, %i0 ! '8'
F002CB04: 90100010                 mov     %l0, %o0
F002CB08: 7ffffed6                 call    _raw_connaddr
F002CB0C: 9210001b                 mov     %i3, %o1
F002CB10: 7fffcd2f                 call    _soisconnected
F002CB14: 90100011                 mov     %l1, %o0
F002CB18: 1080004a                 ba      loc_F002CC40
F002CB1C: 80a6a000                 cmp     %i2, 0
F002CB20: d014204c                 lduh    [%l0+0x4C], %o0! jumptable F002CA54 case 2
F002CB24: 808a2001                 btst    1, %o0
F002CB28: 12800045                 bne     loc_F002CC3C
F002CB2C: b0102016                 mov     0x16, %i0
F002CB30: 90100011                 mov     %l1, %o0
F002CB34: 7ffffea8                 call    _raw_bind
F002CB38: 9210001b                 mov     %i3, %o1
F002CB3C: 10800040                 ba      loc_F002CC3C
F002CB40: b0100008                 mov     %o0, %i0
F002CB44: d014204c                 lduh    [%l0+0x4C], %o0! jumptable F002CA54 case 6
F002CB48: 808a2002                 btst    2, %o0
F002CB4C: 2280003c                 be,a    loc_F002CC3C
F002CB50: b0102039                 mov     0x39, %i0 ! '9'
F002CB54: 7ffffe93                 call    _raw_disconnect
F002CB58: 90100010                 mov     %l0, %o0
F002CB5C: 30800025                 ba,a    loc_F002CBF0
F002CB60: 7fffcde3                 call    _socantsendmore! jumptable F002CA54 case 7
F002CB64: 90100011                 mov     %l1, %o0
F002CB68: 10800036                 ba      loc_F002CC40
F002CB6C: 80a6a000                 cmp     %i2, 0
F002CB70: 80a6e000                 cmp     %i3, 0! jumptable F002CA54 case 9
F002CB74: 0280000a                 be      loc_F002CB9C
F002CB78: d014204c                 lduh    [%l0+0x4C], %o0
F002CB7C: 808a2002                 btst    2, %o0
F002CB80: 1280002f                 bne     loc_F002CC3C
F002CB84: b0102038                 mov     0x38, %i0 ! '8'
F002CB88: 90100010                 mov     %l0, %o0
F002CB8C: 7ffffeb5                 call    _raw_connaddr
F002CB90: 9210001b                 mov     %i3, %o1
F002CB94: 10800007                 ba      loc_F002CBB0
F002CB98: 9010001a                 mov     %i2, %o0
F002CB9C: 808a2002                 btst    2, %o0
F002CBA0: 12800004                 bne     loc_F002CBB0
F002CBA4: 9010001a                 mov     %i2, %o0
F002CBA8: 10800025                 ba      loc_F002CC3C
F002CBAC: b0102039                 mov     0x39, %i0 ! '9'
F002CBB0: d404600c                 ld      [%l1+0xC], %o2
F002CBB4: 92100011                 mov     %l1, %o1
F002CBB8: d402a010                 ld      [%o2+0x10], %o2
F002CBBC: 9fc28000                 call    %o2
F002CBC0: b4102000                 mov     0, %i2
F002CBC4: 80a6e000                 cmp     %i3, 0
F002CBC8: 0280001d                 be      loc_F002CC3C
F002CBCC: b0100008                 mov     %o0, %i0
F002CBD0: d014204c                 lduh    [%l0+0x4C], %o0
F002CBD4: 900a3ffd                 and     %o0, -3, %o0
F002CBD8: 10800019                 ba      loc_F002CC3C
F002CBDC: d034204c                 sth     %o0, [%l0+0x4C]
F002CBE0: 7ffffe70                 call    _raw_disconnect! jumptable F002CA54 case 10
F002CBE4: 90100010                 mov     %l0, %o0
F002CBE8: 7fffc6f3                 call    _sofree
F002CBEC: 90100011                 mov     %l1, %o0
F002CBF0: 7fffcd2a                 call    _soisdisconnected
F002CBF4: 90100011                 mov     %l1, %o0
F002CBF8: 10800012                 ba      loc_F002CC40
F002CBFC: 80a6a000                 cmp     %i2, 0
F002CC00: 10800014                 ba      locret_F002CC50! jumptable F002CA54 case 12
F002CC04: b0102000                 mov     0, %i0
F002CC08: 10800003                 ba      loc_F002CC14! jumptable F002CA54 case 15
F002CC0C: 9004201c                 add     %l0, 0x1C, %o0
F002CC10: 9004200c                 add     %l0, 0xC, %o0! jumptable F002CA54 case 16
F002CC14: d206e004                 ld      [%i3+4], %o1! void *
F002CC18: 94102010                 mov     0x10, %o2! size_t
F002CC1C: 40019fbd                 call    _bcopy
F002CC20: 9206c009                 add     %i3, %o1, %o1
F002CC24: 90102010                 mov     0x10, %o0
F002CC28: 10800005                 ba      loc_F002CC3C
F002CC2C: d036e008                 sth     %o0, [%i3+8]
F002CC30: 113c0430                 sethi   %hi(aRawUsrreq), %o0! jumptable F002CA54 default case, case 11
F002CC34: 7fffa14f                 call    _panic
F002CC38: 90122328                 bset    %lo(aRawUsrreq), %o0! "raw_usrreq"
F002CC3C: 80a6a000                 cmp     %i2, 0
F002CC40: 02800004                 be      locret_F002CC50
F002CC44: 01000000                 nop
F002CC48: 7fffc407                 call    _m_freem
F002CC4C: 9010001a                 mov     %i2, %o0
F002CC50: 81c7e008                 ret
F002CC54: 81e80000                 restore
