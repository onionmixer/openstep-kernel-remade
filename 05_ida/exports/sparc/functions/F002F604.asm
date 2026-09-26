F002F604: 9de3bf78                 save    %sp, -0x88, %sp
F002F608: 40019da3                 call    _splnet
F002F60C: e4060000                 ld      [%i0], %l2
F002F610: 133c04d9                 sethi   %hi(_in_ifaddr), %o1
F002F614: f0026070                 ld      [%o1+%lo(_in_ifaddr)], %i0
F002F618: 80a62000                 cmp     %i0, 0
F002F61C: 0280000b                 be      loc_F002F648
F002F620: a6100008                 mov     %o0, %l3
F002F624: d0062020                 ld      [%i0+0x20], %o0
F002F628: 80a20019                 cmp     %o0, %i1
F002F62C: 02800007                 be      loc_F002F648
F002F630: 80a62000                 cmp     %i0, 0
F002F634: f0062040                 ld      [%i0+0x40], %i0
F002F638: 80a62000                 cmp     %i0, 0
F002F63C: 32bffffb                 bne,a   loc_F002F628
F002F640: d0062020                 ld      [%i0+0x20], %o0
F002F644: 80a62000                 cmp     %i0, 0
F002F648: 32800004                 bne,a   loc_F002F658
F002F64C: f0062044                 ld      [%i0+0x44], %i0
F002F650: 1080000d                 ba      loc_F002F684
F002F654: b0102000                 mov     0, %i0
F002F658: 80a62000                 cmp     %i0, 0
F002F65C: 02800011                 be      loc_F002F6A0
F002F660: 113c04d9                 sethi   -0xFEC9C00, %o0
F002F664: d0060000                 ld      [%i0], %o0
F002F668: 80a20012                 cmp     %o0, %l2
F002F66C: 02800007                 be      loc_F002F688
F002F670: 80a62000                 cmp     %i0, 0
F002F674: f0062014                 ld      [%i0+0x14], %i0
F002F678: 80a62000                 cmp     %i0, 0
F002F67C: 32bffffb                 bne,a   loc_F002F668
F002F680: d0060000                 ld      [%i0], %o0
F002F684: 80a62000                 cmp     %i0, 0
F002F688: 02800006                 be      loc_F002F6A0
F002F68C: 113c04d9                 sethi   -0xFEC9C00, %o0
F002F690: d006200c                 ld      [%i0+0xC], %o0
F002F694: 90022001                 inc     %o0
F002F698: 10800039                 ba      loc_F002F77C
F002F69C: d026200c                 st      %o0, [%i0+0xC]
F002F6A0: e0022070                 ld      [%o0+0x70], %l0
F002F6A4: 80a42000                 cmp     %l0, 0
F002F6A8: 02800012                 be      loc_F002F6F0
F002F6AC: 90102000                 mov     0, %o0
F002F6B0: d0042020                 ld      [%l0+0x20], %o0
F002F6B4: 80a20019                 cmp     %o0, %i1
F002F6B8: 02800007                 be      loc_F002F6D4
F002F6BC: 80a42000                 cmp     %l0, 0
F002F6C0: e0042040                 ld      [%l0+0x40], %l0
F002F6C4: 80a42000                 cmp     %l0, 0
F002F6C8: 32bffffb                 bne,a   loc_F002F6B4
F002F6CC: d0042020                 ld      [%l0+0x20], %o0
F002F6D0: 80a42000                 cmp     %l0, 0
F002F6D4: 02800007                 be      loc_F002F6F0
F002F6D8: 90102000                 mov     0, %o0
F002F6DC: 7fffb8c7                 call    _m_getclr
F002F6E0: 9210200f                 mov     0xF, %o1
F002F6E4: a2920000                 orcc    %o0, %g0, %l1
F002F6E8: 32800006                 bne,a   loc_F002F700
F002F6EC: d0046004                 ld      [%l1+4], %o0
F002F6F0: 40019d8d                 call    _splx
F002F6F4: 90100013                 mov     %l3, %o0
F002F6F8: 10800023                 ba      locret_F002F784
F002F6FC: b0102000                 mov     0, %i0
F002F700: b0044008                 add     %l1, %o0, %i0
F002F704: e4244008                 st      %l2, [%l1+%o0]
F002F708: f2262004                 st      %i1, [%i0+4]
F002F70C: 90102001                 mov     1, %o0
F002F710: d026200c                 st      %o0, [%i0+0xC]
F002F714: e0262008                 st      %l0, [%i0+8]
F002F718: d0042044                 ld      [%l0+0x44], %o0
F002F71C: d0262014                 st      %o0, [%i0+0x14]
F002F720: f0242044                 st      %i0, [%l0+0x44]
F002F724: 90102002                 mov     2, %o0
F002F728: d037bfe8                 sth     %o0, [%fp+var_18]
F002F72C: e427bfec                 st      %l2, [%fp+var_14]
F002F730: d0066038                 ld      [%i1+0x38], %o0
F002F734: 80a22000                 cmp     %o0, 0
F002F738: 02800009                 be      loc_F002F75C
F002F73C: 9407bfd8                 add     %fp, var_28, %o2
F002F740: 90100019                 mov     %i1, %o0
F002F744: 1320081a                 sethi   -0x7FDF9800, %o1
F002F748: 7ffff142                 call    _if_ioctl
F002F74C: 92126131                 bset    0x131, %o1
F002F750: 80a22000                 cmp     %o0, 0
F002F754: 02800008                 be      loc_F002F774
F002F758: 01000000                 nop
F002F75C: d2062014                 ld      [%i0+0x14], %o1
F002F760: 90100011                 mov     %l1, %o0
F002F764: 7fffb8d4                 call    _m_free
F002F768: d2242044                 st      %o1, [%l0+0x44]
F002F76C: 10800004                 ba      loc_F002F77C
F002F770: b0102000                 mov     0, %i0
F002F774: 400026a7                 call    _igmp_joingroup
F002F778: 90100018                 mov     %i0, %o0
F002F77C: 40019d6a                 call    _splx
F002F780: 90100013                 mov     %l3, %o0
F002F784: 81c7e008                 ret
F002F788: 81e80000                 restore
