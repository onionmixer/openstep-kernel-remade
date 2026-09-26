F00429E0: 9de3bf60                 save    %sp, -0xA0, %sp
F00429E4: 90102078                 mov     0x78, %o0! void *
F00429E8: 273c04d0                 sethi   %hi(_active_threads), %l3
F00429EC: d204e260                 ld      [%l3+%lo(_active_threads)], %o1! size_t
F00429F0: 94102001                 mov     1, %o2
F00429F4: 4000959f                 call    _kalloc
F00429F8: d4226198                 st      %o2, [%o1+0x198]
F00429FC: a2100008                 mov     %o0, %l1
F0042A00: 40014916                 call    _bzero
F0042A04: 92102078                 mov     0x78, %o1 ! 'x'
F0042A08: 213c04eb                 sethi   %hi(_clntkudpxid), %l0
F0042A0C: d0042030                 ld      [%l0+%lo(_clntkudpxid)], %o0
F0042A10: 80a22000                 cmp     %o0, 0
F0042A14: 12800006                 bne     loc_F0042A2C
F0042A18: a4046004                 add     %l1, 4, %l2
F0042A1C: 7fff415c                 call    _getthetime
F0042A20: 9007bfc0                 add     %fp, var_40, %o0
F0042A24: d007bfc4                 ld      [%fp+var_3C], %o0
F0042A28: d0242030                 st      %o0, [%l0+%lo(_clntkudpxid)]
F0042A2C: 113c0436901221c8         set     _udp_ops, %o0
F0042A34: d0246008                 st      %o0, [%l1+8]
F0042A38: 7ffffeab                 call    _authkern_create
F0042A3C: e224600c                 st      %l1, [%l1+0xC]
F0042A40: d0246004                 st      %o0, [%l1+4]
F0042A44: c027bfc8                 clr     [%fp+var_38]
F0042A48: c027bfcc                 clr     [%fp+var_34]
F0042A4C: 90102002                 mov     2, %o0
F0042A50: d027bfd0                 st      %o0, [%fp+var_30]
F0042A54: f227bfd4                 st      %i1, [%fp+var_2C]
F0042A58: f427bfd8                 st      %i2, [%fp+var_28]
F0042A5C: 90100012                 mov     %l2, %o0
F0042A60: 92100018                 mov     %i0, %o1
F0042A64: 9410001b                 mov     %i3, %o2
F0042A68: 4000004c                 call    _clntkudp_init
F0042A6C: 9610001c                 mov     %i4, %o3
F0042A70: 21000008                 sethi   0x2000, %l0
F0042A74: 4000957f                 call    _kalloc
F0042A78: 90142260                 or      %l0, 0x260, %o0
F0042A7C: 94100008                 mov     %o0, %o2
F0042A80: d4246068                 st      %o2, [%l1+0x68]
F0042A84: 113c010a901221a4         set     sub_F00429A4, %o0
F0042A8C: 92102000                 mov     0, %o1
F0042A90: 96142260                 or      %l0, 0x260, %o3
F0042A94: 7fff6e2b                 call    _mclgetx
F0042A98: 98102001                 mov     1, %o4
F0042A9C: b2920000                 orcc    %o0, %g0, %i1
F0042AA0: 0280002f                 be      loc_F0042B5C
F0042AA4: a0046034                 add     %l1, 0x34, %l0 ! '4'
F0042AA8: 90100010                 mov     %l0, %o0
F0042AAC: 92100019                 mov     %i1, %o1! rpc_msg *
F0042AB0: 40000c5e                 call    _xdrmbuf_init
F0042AB4: 94102000                 mov     0, %o2
F0042AB8: 90100010                 mov     %l0, %o0! XDR *
F0042ABC: 40000604                 call    _xdr_callhdr
F0042AC0: 9207bfc8                 add     %fp, var_38, %o1
F0042AC4: 80a22000                 cmp     %o0, 0
F0042AC8: 32800009                 bne,a   loc_F0042AEC
F0042ACC: d0046038                 ld      [%l1+0x38], %o0
F0042AD0: 113c0436                 sethi   %hi(aClntkudpCreate), %o0! "clntkudp_create - Fatal header serializ"...
F0042AD4: 7fff46e1                 call    _printf
F0042AD8: 901221e0                 bset    %lo(aClntkudpCreate), %o0! "clntkudp_create - Fatal header serializ"...
F0042ADC: 7fff6c62                 call    _m_freem
F0042AE0: 90100019                 mov     %i1, %o0
F0042AE4: 1080001f                 ba      loc_F0042B60
F0042AE8: 113c04d0                 sethi   -0xFECC000, %o0
F0042AEC: d2022010                 ld      [%o0+0x10], %o1
F0042AF0: 9fc24000                 call    %o1
F0042AF4: 90100010                 mov     %l0, %o0
F0042AF8: d0246064                 st      %o0, [%l1+0x64]
F0042AFC: 7fff6bee                 call    _m_free
F0042B00: 90100019                 mov     %i1, %o0
F0042B04: 90102002                 mov     2, %o0
F0042B08: 92046014                 add     %l1, 0x14, %o1
F0042B0C: 94102002                 mov     2, %o2
F0042B10: 7fff6eb7                 call    _socreate
F0042B14: 96102011                 mov     0x11, %o3
F0042B18: 92920000                 orcc    %o0, %g0, %o1
F0042B1C: 02800004                 be      loc_F0042B2C
F0042B20: 113c0436                 sethi   %hi(aClntkudpCreate_0), %o0! "clntkudp_create: socket creation proble"...
F0042B24: 1080000c                 ba      loc_F0042B54
F0042B28: 90122218                 bset    %lo(aClntkudpCreate_0), %o0! "clntkudp_create: socket creation proble"...
F0042B2C: 4000026a                 call    sub_F00434D4
F0042B30: d0046014                 ld      [%l1+0x14], %o0
F0042B34: 92920000                 orcc    %o0, %g0, %o1
F0042B38: 12800006                 bne     loc_F0042B50
F0042B3C: 113c0436                 sethi   -0xFEF2800, %o0
F0042B40: d004e260                 ld      [%l3+0x260], %o0
F0042B44: b0100012                 mov     %l2, %i0
F0042B48: 10800012                 ba      locret_F0042B90
F0042B4C: c0222198                 clr     [%o0+0x198]
F0042B50: 90122248                 bset    0x248, %o0! char *
F0042B54: 7fff46c1                 call    _printf
F0042B58: 01000000                 nop
F0042B5C: 113c04d0                 sethi   -0xFECC000, %o0
F0042B60: d0022260                 ld      [%o0+0x260], %o0
F0042B64: 13000008                 sethi   0x2000, %o1
F0042B68: c0222198                 clr     [%o0+0x198]
F0042B6C: d0046068                 ld      [%l1+0x68], %o0
F0042B70: 4000958c                 call    _kfree
F0042B74: 92126260                 bset    0x260, %o1
F0042B78: 7fff33a8                 call    _crfree
F0042B7C: d0046074                 ld      [%l1+0x74], %o0
F0042B80: 90100011                 mov     %l1, %o0
F0042B84: 40009587                 call    _kfree
F0042B88: 92102078                 mov     0x78, %o1 ! 'x'
F0042B8C: b0102000                 mov     0, %i0
F0042B90: 81c7e008                 ret
F0042B94: 81e80000                 restore
