F00BB970: 9de3bf90                 save    %sp, -0x70, %sp! int
F00BB974: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00BB978: f0022290                 ld      [%o0+%lo(_cons_tp)], %i0
F00BB97C: 1108001a90122302         set     0x20006B02, %o0
F00BB984: 80a64008                 cmp     %i1, %o0
F00BB988: 02800034                 be      loc_F00BBA58
F00BB98C: 133c04fd                 sethi   -0xFEC0C00, %o1
F00BB990: 1480001b                 bg      loc_F00BB9FC
F00BB994: 1108001a                 sethi   0x20006800, %o0
F00BB998: 1120021d90122067         set     -0x7FF78B99, %o0
F00BB9A0: 80a64008                 cmp     %i1, %o0
F00BB9A4: 228000a2                 be,a    locret_F00BBC2C
F00BB9A8: b0102016                 mov     0x16, %i0
F00BB9AC: 14800009                 bg      loc_F00BB9D0
F00BB9B0: 1120031a                 sethi   -0x7FF39800, %o0
F00BB9B4: 1120011a90122309         set     -0x7FFB94F7, %o0
F00BB9BC: 80a64008                 cmp     %i1, %o0
F00BB9C0: 02800065                 be      loc_F00BBB54
F00BB9C4: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BB9C8: 10800080                 ba      loc_F00BBBC8
F00BB9CC: 90100018                 mov     %i0, %o0
F00BB9D0: 90122305                 bset    0x305, %o0
F00BB9D4: 80a64008                 cmp     %i1, %o0
F00BB9D8: 2280002d                 be,a    loc_F00BBA8C
F00BB9DC: d016a004                 lduh    [%i2+4], %o0
F00BB9E0: 1120031a90122306         set     -0x7FF394FA, %o0
F00BB9E8: 80a64008                 cmp     %i1, %o0
F00BB9EC: 0280004b                 be      loc_F00BBB18
F00BB9F0: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BB9F4: 10800075                 ba      loc_F00BBBC8
F00BB9F8: 90100018                 mov     %i0, %o0
F00BB9FC: 90122308                 bset    0x308, %o0
F00BBA00: 80a64008                 cmp     %i1, %o0
F00BBA04: 22800049                 be,a    loc_F00BBB28
F00BBA08: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BBA0C: 14800009                 bg      loc_F00BBA30
F00BBA10: 1110011a                 sethi   0x40046800, %o0
F00BBA14: 1108001a90122303         set     0x20006B03, %o0
F00BBA1C: 80a64008                 cmp     %i1, %o0
F00BBA20: 02800046                 be      loc_F00BBB38
F00BBA24: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BBA28: 10800068                 ba      loc_F00BBBC8
F00BBA2C: 90100018                 mov     %i0, %o0
F00BBA30: 9012230a                 bset    0x30A, %o0
F00BBA34: 80a64008                 cmp     %i1, %o0
F00BBA38: 0280004c                 be      loc_F00BBB68
F00BBA3C: 1110021a                 sethi   0x40086800, %o0
F00BBA40: 9012230b                 bset    0x30B, %o0
F00BBA44: 80a64008                 cmp     %i1, %o0
F00BBA48: 02800051                 be      loc_F00BBB8C
F00BBA4C: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BBA50: 1080005e                 ba      loc_F00BBBC8
F00BBA54: 90100018                 mov     %i0, %o0
F00BBA58: 90102001                 mov     1, %o0
F00BBA5C: d0226230                 st      %o0, [%o1+0x230]
F00BBA60: 92102001                 mov     1, %o1
F00BBA64: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BBA68: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BBA6C: 193c047f                 sethi   %hi(_mach_title), %o4
F00BBA70: d8032274                 ld      [%o4+%lo(_mach_title)], %o4! int
F00BBA74: 94102001                 mov     1, %o2! int
F00BBA78: da022004                 ld      [%o0+4], %o5! int
F00BBA7C: 9fc34000                 call    %o5
F00BBA80: 96102001                 mov     1, %o3! int
F00BBA84: 1080006a                 ba      locret_F00BBC2C
F00BBA88: b0102000                 mov     0, %i0
F00BBA8C: d216a006                 lduh    [%i2+6], %o1
F00BBA90: 7ffd2a9c                 call    _umul
F00BBA94: 91322002                 srl     %o0, 2, %o0
F00BBA98: b6920000                 orcc    %o0, %g0, %i3
F00BBA9C: 06800064                 bl      locret_F00BBC2C
F00BBAA0: b0102000                 mov     0, %i0
F00BBAA4: 7ffeb173                 call    _kalloc
F00BBAA8: 9010001b                 mov     %i3, %o0
F00BBAAC: b2920000                 orcc    %o0, %g0, %i1
F00BBAB0: 32800004                 bne,a   loc_F00BBAC0
F00BBAB4: d006a008                 ld      [%i2+8], %o0! int
F00BBAB8: 1080005d                 ba      locret_F00BBC2C
F00BBABC: b0103fff                 mov     -1, %i0
F00BBAC0: 92100019                 mov     %i1, %o1! int
F00BBAC4: 7fff7165                 call    _copyin
F00BBAC8: 9410001b                 mov     %i3, %o2
F00BBACC: 80a22000                 cmp     %o0, 0
F00BBAD0: 02800006                 be      loc_F00BBAE8
F00BBAD4: 90100019                 mov     %i1, %o0
F00BBAD8: 7ffeb1b2                 call    _kfree
F00BBADC: 9210001b                 mov     %i3, %o1
F00BBAE0: 10800053                 ba      locret_F00BBC2C
F00BBAE4: b0103fff                 mov     -1, %i0
F00BBAE8: f226a008                 st      %i1, [%i2+8]
F00BBAEC: 113c04fd                 sethi   %hi(_kmId), %o0
F00BBAF0: d0022240                 ld      [%o0+%lo(_kmId)], %o0! id
F00BBAF4: 133c0504                 sethi   %hi(paDrawrect), %o1
F00BBAF8: d202620c                 ld      [%o1+%lo(paDrawrect)], %o1! SEL
F00BBAFC: 4000d75d                 call    _objc_msgSend
F00BBB00: 9410001a                 mov     %i2, %o2
F00BBB04: b0100008                 mov     %o0, %i0
F00BBB08: 90100019                 mov     %i1, %o0
F00BBB0C: 7ffeb1a5                 call    _kfree
F00BBB10: 9210001b                 mov     %i3, %o1
F00BBB14: 30800046                 ba,a    locret_F00BBC2C
F00BBB18: d0022240                 ld      [%o0+0x240], %o0
F00BBB1C: 133c0504                 sethi   %hi(paEraserect), %o1
F00BBB20: 10800016                 ba      loc_F00BBB78
F00BBB24: d2026210                 ld      [%o1+%lo(paEraserect)], %o1
F00BBB28: d0022240                 ld      [%o0+0x240], %o0
F00BBB2C: 133c0504                 sethi   %hi(paDisablecons), %o1
F00BBB30: 10800005                 ba      loc_F00BBB44
F00BBB34: d2026214                 ld      [%o1+%lo(paDisablecons)], %o1
F00BBB38: d0022240                 ld      [%o0+0x240], %o0! id
F00BBB3C: 133c0504                 sethi   %hi(paDumpmsgbuf), %o1
F00BBB40: d2026218                 ld      [%o1+%lo(paDumpmsgbuf)], %o1! SEL
F00BBB44: 4000d74b                 call    _objc_msgSend
F00BBB48: 01000000                 nop
F00BBB4C: 10800038                 ba      locret_F00BBC2C
F00BBB50: b0100008                 mov     %o0, %i0
F00BBB54: d0022240                 ld      [%o0+0x240], %o0
F00BBB58: 133c0504                 sethi   %hi(paAnimationctl), %o1
F00BBB5C: d202621c                 ld      [%o1+%lo(paAnimationctl)], %o1
F00BBB60: 10800007                 ba      loc_F00BBB7C
F00BBB64: d4068000                 ld      [%i2], %o2
F00BBB68: 113c04fd                 sethi   %hi(_kmId), %o0
F00BBB6C: d0022240                 ld      [%o0+%lo(_kmId)], %o0! id
F00BBB70: 133c0504                 sethi   %hi(paGetstatus), %o1
F00BBB74: d2026220                 ld      [%o1+%lo(paGetstatus)], %o1! SEL
F00BBB78: 9410001a                 mov     %i2, %o2
F00BBB7C: 4000d73d                 call    _objc_msgSend
F00BBB80: 01000000                 nop
F00BBB84: 1080002a                 ba      locret_F00BBC2C
F00BBB88: b0100008                 mov     %o0, %i0
F00BBB8C: d0022240                 ld      [%o0+0x240], %o0! id
F00BBB90: 133c0504                 sethi   %hi(paGetscreensize), %o1
F00BBB94: d2026224                 ld      [%o1+%lo(paGetscreensize)], %o1! SEL
F00BBB98: 4000d736                 call    _objc_msgSend
F00BBB9C: 9407bff0                 add     %fp, var_10, %o2
F00BBBA0: d017bff0                 lduh    [%fp+var_10], %o0
F00BBBA4: d0368000                 sth     %o0, [%i2]
F00BBBA8: d017bff2                 lduh    [%fp+var_E], %o0
F00BBBAC: d036a002                 sth     %o0, [%i2+2]
F00BBBB0: d017bff4                 lduh    [%fp+var_C], %o0
F00BBBB4: d036a004                 sth     %o0, [%i2+4]
F00BBBB8: d017bff6                 lduh    [%fp+var_A], %o0
F00BBBBC: b0102000                 mov     0, %i0
F00BBBC0: 1080001b                 ba      locret_F00BBC2C
F00BBBC4: d036a006                 sth     %o0, [%i2+6]
F00BBBC8: d84e2047                 ldsb    [%i0+0x47], %o4
F00BBBCC: 92100019                 mov     %i1, %o1
F00BBBD0: 972b2001                 sll     %o4, 1, %o3
F00BBBD4: 9602c00c                 add     %o3, %o4, %o3
F00BBBD8: 972ae004                 sll     %o3, 4, %o3
F00BBBDC: 193c042e981320cc         set     _linesw, %o4
F00BBBE4: 9602c00c                 add     %o3, %o4, %o3
F00BBBE8: d802e010                 ld      [%o3+0x10], %o4
F00BBBEC: 9410001a                 mov     %i2, %o2
F00BBBF0: 9fc30000                 call    %o4
F00BBBF4: 9610001b                 mov     %i3, %o3
F00BBBF8: 80a22000                 cmp     %o0, 0
F00BBBFC: 26800004                 bl,a    loc_F00BBC0C
F00BBC00: 90100018                 mov     %i0, %o0
F00BBC04: 1080000a                 ba      locret_F00BBC2C
F00BBC08: b0100008                 mov     %o0, %i0
F00BBC0C: 92100019                 mov     %i1, %o1
F00BBC10: 9410001a                 mov     %i2, %o2
F00BBC14: 7ffd6bec                 call    _ttioctl
F00BBC18: 9610001b                 mov     %i3, %o3
F00BBC1C: 80a22000                 cmp     %o0, 0
F00BBC20: 16800003                 bge     locret_F00BBC2C
F00BBC24: b0100008                 mov     %o0, %i0
F00BBC28: b0102019                 mov     0x19, %i0
F00BBC2C: 81c7e008                 ret
F00BBC30: 81e80000                 restore
