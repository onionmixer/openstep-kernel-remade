F006BCA4: 9de3bf98                 save    %sp, -0x68, %sp
F006BCA8: e2060000                 ld      [%i0], %l1
F006BCAC: d2046004                 ld      [%l1+4], %o1
F006BCB0: d00c4009                 ldub    [%l1+%o1], %o0
F006BCB4: 900a200f                 and     %o0, 0xF, %o0
F006BCB8: 80a22005                 cmp     %o0, 5
F006BCBC: 08800005                 bleu    loc_F006BCD0
F006BCC0: a6044009                 add     %l1, %o1, %l3
F006BCC4: 90100013                 mov     %l3, %o0
F006BCC8: 7fff1c93                 call    _ip_stripoptions
F006BCCC: 92102000                 mov     0, %o1
F006BCD0: d0046004                 ld      [%l1+4], %o0
F006BCD4: 80a2207c                 cmp     %o0, 0x7C ! '|'
F006BCD8: 18800006                 bgu     loc_F006BCF0
F006BCDC: 90100011                 mov     %l1, %o0
F006BCE0: d0146008                 lduh    [%l1+8], %o0
F006BCE4: 80a22017                 cmp     %o0, 0x17
F006BCE8: 18800009                 bgu     loc_F006BD0C
F006BCEC: 90100011                 mov     %l1, %o0
F006BCF0: 7ffec8f9                 call    _m_pullup
F006BCF4: 92102018                 mov     0x18, %o1
F006BCF8: a2920000                 orcc    %o0, %g0, %l1
F006BCFC: 0280005c                 be      loc_F006BE6C
F006BD00: e2260000                 st      %l1, [%i0]
F006BD04: d0046004                 ld      [%l1+4], %o0
F006BD08: a6044008                 add     %l1, %o0, %l3
F006BD0C: d004e00c                 ld      [%l3+0xC], %o0
F006BD10: d214e014                 lduh    [%l3+0x14], %o1
F006BD14: d404e010                 ld      [%l3+0x10], %o2
F006BD18: d614e016                 lduh    [%l3+0x16], %o3
F006BD1C: 7fffff6b                 call    _find_listener
F006BD20: d80ce009                 ldub    [%l3+9], %o4
F006BD24: aa920000                 orcc    %o0, %g0, %l5
F006BD28: 02800052                 be      locret_F006BE70
F006BD2C: b0102000                 mov     0, %i0
F006BD30: 4000abec                 call    _spl0
F006BD34: 01000000                 nop
F006BD38: 113c04f0                 sethi   %hi(_mach_net_kmsg_zone), %o0
F006BD3C: 400034f0                 call    _zget
F006BD40: d00221a0                 ld      [%o0+%lo(_mach_net_kmsg_zone)], %o0
F006BD44: a0920000                 orcc    %o0, %g0, %l0
F006BD48: 12800005                 bne     loc_F006BD5C
F006BD4C: 90103ffd                 mov     -3, %o0
F006BD50: 7ffec7c5                 call    _m_freem
F006BD54: 90100011                 mov     %l1, %o0
F006BD58: 30800043                 ba,a    loc_F006BE64
F006BD5C: d0242008                 st      %o0, [%l0+8]
F006BD60: c024200c                 clr     [%l0+0xC]
F006BD64: c0242010                 clr     [%l0+0x10]
F006BD68: d00cc000                 ldub    [%l3], %o0
F006BD6C: a41027d4                 mov     0x7D4, %l2
F006BD70: a804202c                 add     %l0, 0x2C, %l4 ! ','
F006BD74: 80a46000                 cmp     %l1, 0
F006BD78: 900a200f                 and     %o0, 0xF, %o0
F006BD7C: d214e002                 lduh    [%l3+2], %o1
F006BD80: 912a2002                 sll     %o0, 2, %o0
F006BD84: 92024008                 add     %o1, %o0, %o1
F006BD88: d014e006                 lduh    [%l3+6], %o0
F006BD8C: d234e002                 sth     %o1, [%l3+2]
F006BD90: 912a2010                 sll     %o0, 16, %o0
F006BD94: 913a2013                 sra     %o0, 19, %o0
F006BD98: 02800015                 be      loc_F006BDEC
F006BD9C: d034e006                 sth     %o0, [%l3+6]
F006BDA0: 80a4a000                 cmp     %l2, 0
F006BDA4: 24800013                 ble,a   loc_F006BDF0
F006BDA8: e4242010                 st      %l2, [%l0+0x10]
F006BDAC: f0546008                 ldsh    [%l1+8], %i0
F006BDB0: 80a60012                 cmp     %i0, %l2
F006BDB4: 34800002                 bg,a    loc_F006BDBC
F006BDB8: b0100012                 mov     %l2, %i0
F006BDBC: 92100014                 mov     %l4, %o1! void *
F006BDC0: 94100018                 mov     %i0, %o2! size_t
F006BDC4: a805000a                 add     %l4, %o2, %l4
F006BDC8: d0046004                 ld      [%l1+4], %o0! void *
F006BDCC: a424800a                 sub     %l2, %o2, %l2
F006BDD0: 4000a350                 call    _bcopy
F006BDD4: 90044008                 add     %l1, %o0, %o0
F006BDD8: 7ffec737                 call    _m_free
F006BDDC: 90100011                 mov     %l1, %o0
F006BDE0: a2920000                 orcc    %o0, %g0, %l1
F006BDE4: 12bffff0                 bne     loc_F006BDA4
F006BDE8: 80a4a000                 cmp     %l2, 0
F006BDEC: e4242010                 st      %l2, [%l0+0x10]
F006BDF0: d0042010                 ld      [%l0+0x10], %o0
F006BDF4: a40cbffc                 and     %l2, -4, %l2
F006BDF8: 90248008                 sub     %l2, %o0, %o0
F006BDFC: d0242010                 st      %o0, [%l0+0x10]
F006BE00: 113c04bd                 sethi   %hi(dword_F012F684), %o0
F006BE04: d2022284                 ld      [%o0+%lo(dword_F012F684)], %o1
F006BE08: d2242014                 st      %o1, [%l0+0x14]
F006BE0C: 90122284                 bset    %lo(dword_F012F684), %o0
F006BE10: d2022004                 ld      [%o0+4], %o1
F006BE14: d2242018                 st      %o1, [%l0+0x18]
F006BE18: d2022008                 ld      [%o0+8], %o1
F006BE1C: d224201c                 st      %o1, [%l0+0x1C]
F006BE20: d202200c                 ld      [%o0+0xC], %o1
F006BE24: d2242020                 st      %o1, [%l0+0x20]
F006BE28: d2022010                 ld      [%o0+0x10], %o1
F006BE2C: d2242024                 st      %o1, [%l0+0x24]
F006BE30: d4022014                 ld      [%o0+0x14], %o2
F006BE34: d2042018                 ld      [%l0+0x18], %o1
F006BE38: 90100015                 mov     %l5, %o0
F006BE3C: d4242028                 st      %o2, [%l0+0x28]
F006BE40: 92224012                 sub     %o1, %l2, %o1
F006BE44: d2242018                 st      %o1, [%l0+0x18]
F006BE48: 7fffb5fa                 call    _ipc_object_reference
F006BE4C: d024201c                 st      %o0, [%l0+0x1C]
F006BE50: 90100010                 mov     %l0, %o0
F006BE54: 13000040                 sethi   0x10000, %o1
F006BE58: 94102000                 mov     0, %o2
F006BE5C: 7fffb188                 call    _ipc_mqueue_send
F006BE60: 96102000                 mov     0, %o3
F006BE64: 4000ab8c                 call    _splnet
F006BE68: 01000000                 nop
F006BE6C: b0102001                 mov     1, %i0
F006BE70: 81c7e008                 ret
F006BE74: 81e80000                 restore
